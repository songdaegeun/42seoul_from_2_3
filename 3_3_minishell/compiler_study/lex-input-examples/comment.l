%{
	/* �ּ� �ν� */
	#include <stdio.h>
%}
C [^\n\*]
STAR [\*]
BEGIN1 "//"
BEGIN2 "/\*"
END "\*/"
%%
���� �κ��� �ϼ��Ͻÿ�.�� {printf("\t%s -> //�ּ�\n", yytext);}
���� �κ��� �ϼ��Ͻÿ�.�� {printf("\t%s -> /**/�ּ�\n", yytext);}
. ; //skip
%%
main()
{
	yylex();
}