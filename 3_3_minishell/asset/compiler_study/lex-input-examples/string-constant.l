%{
	/* ��Ʈ�� ��� �ν� */
	#include <stdio.h>
%}
LETTER [a-zA-Z]
QUOTE \��
ESCAPE_QUOTE \\\��
%%
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> ��Ʈ�� ���\n", yytext); }
. ; //skip
%%
main()
{
	yylex();
}