%{
	/* keyword */
%}
%%
“이 부분을 완성하시오.” { printf("\t%s -> keyword\n”, yytext); }
. ; //skip
%%
main()
{
	yylex();
}
