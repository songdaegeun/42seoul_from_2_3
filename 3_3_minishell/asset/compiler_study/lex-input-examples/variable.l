%{
	/* C ����� ���� �ν� */
	#include <stdio.h>
%}

LETTER [a-zA-Z]
DIGIT [0-9]
UNDERBAR _
%%
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> variable\n", yytext); }
. ; //skip
%%
main()
{
	yylex();
}
