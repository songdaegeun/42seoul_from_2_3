LEX_FILE = scan
YACC_FILE = gram
OUT_FILE = gram

$(OUT_FILE): y.tab.c lex.yy.c
	cc -o $(OUT_FILE) y.tab.c lex.yy.c -ly -ll
y.tab.c: $(YACC_FILE).y
	yacc -d $(YACC_FILE).y
lex.yy.c: $(LEX_FILE).l
	lex $(LEX_FILE).l
