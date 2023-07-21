%{
	#include <stdio.h>
	char a[100];
%}
%union {
	int num;
	char *str;
}
%token NUMBER STRING
%%
print: print word
	| word
	;
word:	NUMBER { printf("number : %d\n", yylval); }
 	| STRING { printf("string : %s\n", yylval); }
	;
%%
yylex()
{
	int i, ch;

	while ((ch=getchar())==' ' || ch=='\t')
		; 	//skip
	if (ch=='\n') return 0;
	else if (isdigit(ch)) {
		ungetc(ch, stdin);
		fscanf(stdin, "%d", &yylval.num);
		return NUMBER;
	} else if (isalpha(ch)) {
		i = 0;
		a[i++] = ch;
		while (isalpha(ch=getchar())) {
			a[i++] = ch;
		}
		a[i] = '\0';
		yylval.str = a;
		ungetc(ch, stdin);
		return STRING;
	}
}
