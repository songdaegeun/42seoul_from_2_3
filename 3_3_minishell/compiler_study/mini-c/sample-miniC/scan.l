delim           [ \t\n]
ws              {delim}+
letter          [A-Za-z]
digit           [0-9]
identifier      {letter}({letter}|{digit}|_)*
unsigned_int    {digit}{digit}*
int_constant    (\+|-)?{unsigned_int}
c_char          [^(\'|\,|\\|\n)]
escaped_char    (\n|\t|\\|\")
char_constant   (\'{c_char}\')|(\'{escaped_char}\')
s_char          [^(\"|\,|\\|\n)]|{escaped_char}
string_constant \"({s_char})*\"
void            \0 

%{
#include <stdio.h>
#include "y.tab.h"

#define STRMAX 999      /*SIZE OF LEXEMES ARRAY */
#define SYMMAX 100      /*SIZE OF SYMTABLE */

#define BSIZE 128
#define NONE -1
#define EOS '\0'

int tokenval;
int lineno;

struct entry 	{
                	char *lexptr;
                	int token;
		};

static skipcmnts();
int yylval; 
char    lexemes[STRMAX];
int     lastchar =-1;	  	 /* last used position in lexemes */
struct entry symtable[SYMMAX];
int     lastentry=0;   		 /* last used position in symtable */

struct entry keywords[] = {

        "void",VOID,
        "if",IF,
        "else",ELSE,
        "while",WHILE,
        "do",DO,
        "for",FOR,
        "continue",CONTINUE,
        "break",BREAK,
        "return",RETURN,
        "typedef",TYPEDEF,
        "++",INC_OP,
        "--",DEC_OP,
        "+=",ADD_ASSIGN,
        "-=",SUB_ASSIGN,
        "*=",MUL_ASSIGN,
        "/=",DIV_ASSIGN,
        "%=",MOD_ASSIGN,
        "||",OR_OP,
        "!=",NE_OP,
        "==",EQ_OP,
        ">=",GE_OP,
        "<=",LE_OP,
        "&&",AND_OP
         };

void count();

%}

%%
"/*"			{ comment(); }
"break"			{ count(); return(BREAK); }
"char"			{ count(); return(CHAR); }
"continue"		{ count(); return(CONTINUE); }
"do"			{ count(); return(DO); }
"else"			{ count(); return(ELSE); }
"for"			{ count(); return(FOR); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"return"		{ count(); return(RETURN); }
"typedef"		{ count(); return(TYPEDEF); }
"void"			{ count(); return(VOID); }
"while"			{ count(); return(WHILE); }

{unsigned_int}  	{ yylval = insert(yytext,INTIGER); count(); return(INTIGER);}

{identifier}    	{ yylval = insert(yytext,IDENTIFIER); count(); return(IDENTIFIER);}

{int_constant}		{ yylval = insert(yytext,INT_CONSTANT); count(); return(INT_CONSTANT);}

{char_constant} 	{ yylval = insert(yytext,CHAR_CONSTANT); count(); return(CHAR_CONSTANT);}

{string_constant}       { yylval = insert(yytext,STRING_CONSTANT); count(); return(STRING_CONSTANT);}

{void}          	{ count(); return(VOID);}

"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
"{"			{ count(); return('{'); }
"}"			{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
"["			{ count(); return('['); }
"]"			{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}

comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}

int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}

init()         /* loads keywords into symtable */
{
        struct entry *p;
        for (p = keywords; p->token; p++)
                insert(p->lexptr, p->token);
}

int     lookup(s)               /* returns position of entry for s */
        char s[];
{
        int p;
        for (p = lastentry; p > 0; p = p - 1)
                if (strcmp(symtable[p].lexptr,s) == 0)
                        return p;
        return 0;
}

int     insert(s,tok)   /* returns position of entry for s */
        char s[];
        int  tok;
{
        int  len;
        len = strlen(s); /*strlen computes length of s */
        if  (lastentry +1 >= SYMMAX)
                printf("symbol table full");
        lastentry = lastentry +1;
        symtable[lastentry].token = tok;
        symtable[lastentry].lexptr = &lexemes[lastchar +1];
        lastchar = lastchar + len + 1;
        strcpy(symtable[lastentry].lexptr,s);
        return lastentry;
}

