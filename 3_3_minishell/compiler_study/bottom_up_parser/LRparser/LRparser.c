#include <stdio.h>
#include "parsetab1.h"

#define SENT_SIZE	1024
#define STACK_SIZE	1024
#define MAX_RULES	9999

/*
 * return value: �Է½ɺ��� ���� token number
 */
int conv_terminal2int(char input_symbol)
{
	int i;

	for (i=0; i < N_TERMINALS+1; i++) {
		if (input_symbol == term_tab[i])
			return i;
	}
	return 0;
}

/*
 * �Է¹����� token number�� ��ȯ
 */
int conv_string2token(char input_buffer[], int input[])
{
	int i;

	for (i=0; input_buffer[i]; i++) {
		input[i] = conv_terminal2int(input_buffer[i]);
//		printf("%d: %c -- %d\n", i, input_buffer[i], input[i]);
	}
	input[i] = 0;
}

void put_cfg_rule(int rule)
{
	int i;

	printf("\t%d: ", rule);	// ������Ģ ��ȣ

//	printf("%d ->", cfg[rule][1]);	// LHS
	printf("%c ->", term_tab[cfg[rule][1]]);	// LHS

	for (i=0; i < cfg[rule][0]; i++) {
//		printf(" %d", cfg[rule][i+2]);	// RHS
		printf(" %c", term_tab[cfg[rule][i+2]]);	// RHS
	}
	printf("\n");
}

void put_right_parse(int n_rp, int right_parse[])
{
	int i;

	printf("Output: right parse\n");
	for (i=0; i < n_rp; i++)
		put_cfg_rule(right_parse[i]);	// right parse -- ����� ������Ģ ���
}

int LR_parse(int input[], int right_parse[])
{
	int i=0;	// index of next symbol
	int next_symbol;

	int stack[STACK_SIZE];
	int tp=0;	// stack top

	int op;	// shift/reduece/accept/error
	int n_rp=0;

	stack[tp++] = 0;	// start state;
	next_symbol = input[i++];
	while (1) {
		op = partab[stack[tp-1]][next_symbol];

		if (op == ACCEPT) {
			return n_rp;
		} else if (op == 0) {	// ERROR
			return -n_rp;
		} else if (op > 0) {	// shift operation
			stack[tp++] = next_symbol;	// shift
			stack[tp++] = op;	// next state
			next_symbol = input[i++];
		} else if (op < 0) {	// reduce operation
			tp -= cfg[-op][0] * 2;	// stack���� ������Ģ�� RHS ����
			if (tp <= 0) printf("ERROR -- stack pointer under flow\n");
			stack[tp] = cfg[-op][1];	// stack�� LHS push
			stack[tp+1] = partab[stack[tp-1]][stack[tp]];	// stack�� next state push
			tp += 2;

//			put_cfg_rule(-op);	// right parse -- ����� ������Ģ ���
			if (n_rp < MAX_RULES) right_parse[n_rp++] = -op;
		}
	}
}

main()
{
	char input_buffer[SENT_SIZE];
	int input[SENT_SIZE];	// token number�� ��ȯ�� �Է� ����
	int n_rp, right_parse[MAX_RULES];	// ����� ������Ģ�� ������� ����

	printf("Input sentence = ");
	fgets(input_buffer, SENT_SIZE, stdin);
	conv_string2token(input_buffer, input);

	n_rp = LR_parse(input, right_parse);

	if (n_rp > 0) {
		put_right_parse(n_rp, right_parse);
		puts("ACCEPT");
	} else {
		put_right_parse(-n_rp, right_parse);
		puts("ERROR");
	}
}
