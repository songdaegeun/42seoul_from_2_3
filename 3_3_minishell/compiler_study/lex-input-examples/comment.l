%{
	/* 주석 인식 */
	#include <stdio.h>
%}
C [^\n\*]
STAR [\*]
BEGIN1 "//"
BEGIN2 "/\*"
END "\*/"
%%
“이 부분을 완성하시오.” {printf("\t%s -> //주석\n", yytext);}
“이 부분을 완성하시오.” {printf("\t%s -> /**/주석\n", yytext);}
. ; //skip
%%
main()
{
	yylex();
}
