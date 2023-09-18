#define N_TERMINALS		2
#define N_NONTERMINALS	2

char term_tab[N_TERMINALS+N_NONTERMINALS+1] = {
	'a',
	',',
	'\n',	// end of input sentence -- '$'
	'L',
	'E'
};

#define N_STATES	6
#define ACCEPT		999
int partab[N_STATES][N_TERMINALS+N_NONTERMINALS+1] = {
	{ 3, 0, 0, 1, 2},
	{ 0, 4, ACCEPT, 0, 0},
	{ 0,-2,-2, 0, 0},
	{ 0,-3,-3, 0, 0},
	{ 3, 0, 0, 0, 5},
	{ 0,-1,-1, 0, 0},
};

#define N_CFG_RULES	3
#define CFG_SIZE		10
/*
 * 생성규칙을 token number로 구현
 * cfg[i][0] : length(RHS)
 * cfg[i][1] : LHS
 * cfg[i][2], cfg[i][3], ... : RHS
 * cfg[i][j] == -1 : RHS 끝표시
 */
int cfg[N_CFG_RULES+1][CFG_SIZE] = {
	{ 0 },
	{ 3, 3, 3, 1, 4, -1 },	// LIST -> LIST , ELEMENT
	{ 1, 3, 4, -1 },	// LIST -> ELEMENT
	{ 1, 4, 0, -1 }	// ELEMENT -> a
};
