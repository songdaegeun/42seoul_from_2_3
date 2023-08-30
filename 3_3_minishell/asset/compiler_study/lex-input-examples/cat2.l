%{
	#include <stdio.h>
%}
%%
. | \n { printf(¡°%s\n¡±, yytext); }
%%
main()
{
	yylex();
}
