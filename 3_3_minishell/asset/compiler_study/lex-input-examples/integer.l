%{
	/* C 언어의 정수 인식 */
	#include <stdio.h>
%}
DIGIT [0-9]
OCTAL [0-7]
HEXA [0-9a-fA-F]
%%
“이 부분을 완성하시오.” { printf("\t%s -> 8진수 정수\n", yytext); }
“이 부분을 완성하시오.” { printf("\t%s -> 10진수 정수\n", yytext); }
“이 부분을 완성하시오.” { printf("\t%s -> 16진수 정수\n", yytext); }
%%
main()
{
	yylex();
}
