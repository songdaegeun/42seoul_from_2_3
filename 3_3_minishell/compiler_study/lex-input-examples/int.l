%{
	/* ���� ���� ��ġ �켱���� ���� */ 
%}
%%
in { printf("IN\n"); }		// R1
in. { printf("IN+CHAR\n"); }	// R2
int { printf("INT\n"); }		// R3
. { printf("CHAR: %s\n", yytext); }	// R4
%%
main()
{
	yylex();
}