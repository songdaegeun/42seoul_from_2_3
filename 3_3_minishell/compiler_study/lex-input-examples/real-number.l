%{
	/* C ����� �Ǽ� �ν� */
%}
DIGIT [0-9]
EXPONENT [eE]
SIGN [\+-]
%%
���� �κ��� �ϼ��Ͻÿ�.�� { printf("\t%s -> �Ǽ� ���\n", yytext); }
. ; //skip
%%
main()
{
	yylex();
}