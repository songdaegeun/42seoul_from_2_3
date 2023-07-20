#define N_TERMINALS	5
#define N_NONTERMINALS	3

#define N_CFG_RULES	6
#define CFG_SIZE		10

#define N_STATES	12
#define ACCEPT		999

char term_tab[N_TERMINALS+N_NONTERMINALS+1] = {
	'a',
	'+',
	'*',
	'(',
	')',
	'\n',	// end of input sentence -- '$'
	'E',
	'T',
	'F'
};

int partab[N_STATES][N_TERMINALS+N_NONTERMINALS+1] = {
	{ 5, 0, 0, 4, 0, 0, 1, 2, 3 },
	{ 0, 6, 0, 0, 0, ACCEPT, 0, 0, 0 },
	{ 0,-2, 7, 0,-2,-2, 0, 0, 0 },
	{ 0,-4,-4, 0,-4,-4, 0, 0, 0 },
	{ 5, 0, 0, 4, 0, 0, 8, 2, 3 },
	{ 0,-6,-6, 0,-6,-6, 0, 0, 0 },
	{ 5, 0, 0, 4, 0, 0, 0, 9, 3 },
	{ 5, 0, 0, 4, 0, 0, 0, 0,10 },
	{ 0, 6, 0, 0,11, 0, 0, 0, 0 },
	{ 0,-1, 7, 0,-1,-1, 0, 0, 0 },
	{ 0,-3,-3, 0,-3,-3, 0, 0, 0 },
	{ 0,-5,-5, 0,-5,-5, 0, 0, 0 },
};

/*
 * 생성규칙을 token number로 구현
 * cfg[i][0] : length(RHS)
 * cfg[i][1] : LHS
 * cfg[i][2], cfg[i][3], ... : RHS
 * cfg[i][j] == -1 : RHS 끝표시
 */
int cfg[N_CFG_RULES+1][CFG_SIZE] = {
	{ 0 },
	{ 3, 6, 6, 1, 7, -1 },	// E -> E + T
	{ 1, 6, 7, -1 },		// E -> T
	{ 3, 7, 7, 2, 8, -1 },	// T -> T * F
	{ 1, 7, 8, -1 },		// T -> F
	{ 3, 8, 3, 6, 4, -1 },	// F -> ( E )
	{ 1, 8, 0, -1 },		// F -> a
};
