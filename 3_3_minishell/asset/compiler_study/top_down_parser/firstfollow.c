#include <stdio.h>
/*
	S -> AbB | BbB
	A -> aBb | bBb | cBb
	B -> d | e | f
*/
#define N_NONTERMINAL 3
#define N_TERMINAL 7 // terminal num + epsilon
#define N_RHS 8
#define MAX_CFG_STRING 10

char non_terminal[N_NONTERMINAL] = {'S', 'A', 'B'};
char terminal[N_TERMINAL] = {'a', 'b', 'c', 'd', 'e', 'f', '@'};  //@ = epsilon

char cfg[N_RHS][MAX_CFG_STRING] = {  // 생성규칙
	// {LSH, RHS...}
	{'S', 'A', 'b', 'B'},
	{'S', 'B', 'b', 'B'},
	{'A', 'a', 'B', 'b'},
	{'A', 'b', 'B', 'b'},
	{'A', 'c', 'B', 'b'},
	{'B', 'd'},
	{'B', 'e'},
	{'B', 'f'},
};

// 각 nonterminal에 대한 FIRST(X)를 기록하는 자료구조 (terminals + epsilon)
int record_first[N_NONTERMINAL][N_TERMINAL] = {0}; 

// 각 nonterminal에 대한 FOLLOW를 기록하는 자료구조 (terminals + 시작기호 $)
int record_follow[N_NONTERMINAL][N_TERMINAL+1] = {0}; 

int get_nonterminal_num(char ch)
{
	int i;
	for (i=0; i < N_NONTERMINAL; i++) {
		if (ch == non_terminal[i]) return i;
	}
	return -1;
}

int get_terminal_num(char ch)
{
	int i;
	for (i=0; i < N_TERMINAL; i++) {
		if (ch == terminal[i]) return i;
	}
	return -1;
}

int is_terminal(char ch)
{
	// 영문 대문자이면 nonterminal
	if ('A' <= ch && ch <= 'Z') return 0;

	//그외 모두 terminal
	return 1;
}


void first(char *cur_cfg_RHS, int *cur_record_first)
{
	int i, record_num;
	char *cur_cfg = NULL;
	char cur_nonterminal = *cur_cfg_RHS;

	if (cur_cfg_RHS == NULL) return;
	if (is_terminal(*cur_cfg_RHS)) { //terminal
		record_num = get_terminal_num(*cur_cfg_RHS);
		cur_record_first[record_num] = 1; //terminal record.
	} else { //nonterminal
		for (i=0; i < N_RHS; i++) {
			cur_cfg = cfg[i];
			if (cur_nonterminal == cur_cfg[0]) {
				//LHS의 nonterminal과 현재 구해야할 nonterminal이 같으면.
				first(&cur_cfg[1], cur_record_first);
			}
		}
	}

	if (cur_record_first[N_TERMINAL-1]) { //위 과정에서 epsilon 발견된 경우
		/* FIRST(Y1Y2Y3..Yk) = FIRST(Y1) - {epsilon}) U FIRST(Y2Y3...Yk) */
		if (*(cur_cfg_RHS+1) != 0) { //맨 마지막 Yk가 아니라면. 
			cur_record_first[N_TERMINAL-1] = 0; //epsilon 제거
			first(cur_cfg_RHS+1, cur_record_first);
		}
	}
}

void get_firsts()
{
	int i, j;
	char cur_nonterminal;
	char *cur_cfg = NULL;

	/* 각 nonterminal들에 대하여 first계산 */
	for (i=0; i < N_NONTERMINAL; i++) {
		cur_nonterminal = non_terminal[i];
		for (j=0; j < N_RHS; j++) {
			cur_cfg = cfg[j];
			if (cur_nonterminal == cur_cfg[0]) {
				//LHS의 nonterminal과 현재 구해야할 nonterminal이 같으면.
				first(&cur_cfg[1], record_first[i]);
			}
		}
	}
}

void follow(char cur_nonterminal, int *cur_record_follow)
{
	int i, j;
	char *cur_cfg_ch = NULL;
	char cur_cfg_nonterminal;

	if (get_nonterminal_num(cur_nonterminal)==0) { //시작기호이면, $기록.
		cur_record_follow[N_TERMINAL] = 1;
	}

	for (i=0; i < N_RHS; i++) {
		cur_cfg_nonterminal = cfg[i][0];
		cur_cfg_ch = cfg[i]+1;

		while (*cur_cfg_ch) { //RHS char 하나씩 살펴보면서
			// follow구할 nonterminal과 같은 nonterminal을 RHS에서 발견하면.
			if (*cur_cfg_ch == cur_nonterminal) { 
				char next_ch = *(cur_cfg_ch+1);

				if (next_ch == 0) { //next ch가 epsilon.
					if (cur_cfg_nonterminal != cur_nonterminal)
					//현재 계산하고 있는 follow(A), 계산할 follow(A), 같은 nonterminal A에
					//대해서는 반복되므로 계산에서 제외. 
						follow(cur_cfg_nonterminal, cur_record_follow);
				} else if (is_terminal(next_ch)) { // next ch가 terminal: FIRST(a)=a
					int record_num = get_terminal_num(next_ch);
					cur_record_follow[record_num] = 1; //terminal record
				} else { //next ch가 nonterminal. 
					//(FIRST(A) = 이전의 구했던 FIRST(A) 이용하여 기록.
					int nonterminal_num = get_nonterminal_num(next_ch);
					for (j=0; j < N_TERMINAL; j++) {
						if (record_first[nonterminal_num][j]) cur_record_follow[j] = 1;
					}
				}

				if (cur_record_follow[N_TERMINAL-1]) { // epsilon이 존재하면
					/* (FIRST(b)-{epsilon}) U FOLLOW(LHS) */
					cur_record_follow[N_TERMINAL-1] = 0; //epsilon 제거
					follow(cur_cfg_nonterminal, cur_record_follow);
				}
				break;
			} else cur_cfg_ch++;
		}
	}
}

void get_follows()
{
	int i;
	char cur_nonterminal;

	/* 각 nonterminal들에 대하여 follow계산 */
	for (i=0; i < N_NONTERMINAL; i++) {
		cur_nonterminal = non_terminal[i];
		follow(cur_nonterminal, record_follow[i]);
	}
}


void put_follows()
{
	int i, j;

	printf("\n<follow>\n");
	for (i=0; i < N_NONTERMINAL; i++) {
		printf("FOLLOW(%C) = ", non_terminal[i]);
		
		for (j=0; j < N_TERMINAL; j++) {
			if (record_follow[i][j]) {
				printf("%c ", terminal[j]);
			}
		}
		if (record_follow[i][N_TERMINAL]) printf("$");
		printf("\n");
	}
}

void put_firsts()
{
	int i,j;

	printf("\n<first>\n");
	for (i=0; i<N_NONTERMINAL; i++) {
		printf("FIRST(%C) = ", non_terminal[i]);
		
		for (j=0; j<N_TERMINAL; j++) {
			if (record_first[i][j]) printf("%c ", terminal[j]);
		}
		printf("\n");
	}
}

void put_cfg()
{
	int i;
	int check_same_nonterminal=0;
	char pre_nonterminal=0;
	char *cur_cfg = NULL;

	printf("<input cfg>\n");
	for (i=0; i<N_RHS; i++) {
		if (pre_nonterminal!=0 && pre_nonterminal==cfg[i][0])
			check_same_nonterminal = 1;
		cur_cfg = cfg[i];
		pre_nonterminal = cfg[i][0];

		if (check_same_nonterminal) {
			printf(" | ");
			cur_cfg++;
			check_same_nonterminal = 0;
		} else {
			if (i==0) printf("%c -> ", *cur_cfg++);
			else printf("\n%c -> ", *cur_cfg++);
		}
		while (*cur_cfg) {
			printf("%c", *cur_cfg++);
		}
	}
	printf("\n");
}

void main()
{
	put_cfg();

	get_firsts();
	put_firsts();

	get_follows();
	put_follows();
}
