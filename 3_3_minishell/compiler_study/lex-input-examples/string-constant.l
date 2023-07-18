%{
	/* 스트링 상수 인식 */
	#include <stdio.h>
%}
LETTER [a-zA-Z]
QUOTE \”
ESCAPE_QUOTE \\\”
%%
“이 부분을 완성하시오.” { printf("\t%s -> 스트링 상수\n", yytext); }
. ; //skip
%%
main()
{
	yylex();
}
