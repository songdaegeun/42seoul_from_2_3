%{
	/* C ����� ���� �ν� */
	#include <stdio.h>
%}
DIGIT [0-9]
OCTAL [0-7]
HEXA [0-9a-fA-F]
%%
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> 8���� ����\n", yytext); }
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> 10���� ����\n", yytext); }
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> 16���� ����\n", yytext); }
%%
main()
{
	yylex();
}