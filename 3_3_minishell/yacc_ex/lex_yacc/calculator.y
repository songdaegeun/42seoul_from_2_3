%{
#include <stdio.h>
void yyerror(char *s);
int yylex();
%} 
%token NUMBER
%%
state: expression { printf("= %d\n", $1); }
	;
expression: expression '+' NUMBER {$$ = $1 + $3;}
	| NUMBER {$$ = $1;}
	;
%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

main()
{
	yyparse();
}

