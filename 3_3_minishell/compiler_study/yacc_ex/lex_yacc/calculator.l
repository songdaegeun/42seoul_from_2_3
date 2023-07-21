%{
	#include "y.tab.h"
	int yywrap();
%}
%%
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }
[ \t]	;   // skip
\n	return 0;   // eof
.	return yytext[0];
%%
int yywrap() { return 1; }