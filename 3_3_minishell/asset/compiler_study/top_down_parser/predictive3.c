/*
	Predictive parser
	2017.11.03 by Kang, Seung-Shik at Kookmin University
*/
#include <stdio.h>
#include <string.h>

#define NONTERMINALS 2
#define TERMINALS 3
#define RULESIZE 5
#define MAX 100

#define INPUT_END_MARK ('a'+TERMINALS)
#define STACK_BOTTOM_MARK '_'

char create_rule[RULESIZE][MAX];
int parsing_table[NONTERMINALS][TERMINALS+1];
char stack[999];
int top;

void input_data(char *str)
{
	int len;

	printf("Input(b, ba*, ba*b, aaba*bcc) : ");
	scanf("%s", str);

	len = strlen(str);
	str[len] = INPUT_END_MARK;
	str[len+1] = 0;
	printf("Input string : %s (%c is an endig mark)\n", str, INPUT_END_MARK);
}

/*
	0. S -> aSc
	1. S -> bA
	2. A -> aA
	3. A -> b
	4. A -> epsilon

	문자를 인덱스로 표시하기 위하여 아래와 같이 차례대로 A, B..nonterminal 이름 변경.

	0. A -> aAc
	1. A -> bB
	2. B -> aB
	3. B -> b
	4. B -> epsilon
*/
void load_create_rule()
{
	strcpy(create_rule[0], "aAc");
	strcpy(create_rule[1], "bB");
	strcpy(create_rule[2], "aB");
	strcpy(create_rule[3], "b");
	strcpy(create_rule[4], "");
}

/*
	   Vn/Vt |	a	b	c	$(d)
	   ----------------------------------------
	     A	 |	0	1	-1	-1
	     B	 |	2	3	4	4
	생성 규칙이 없는 빈칸은 -1 로 표시.

	0. A -> aAc
	1. A -> bB
	2. B -> aB
	3. B -> b
	4. B -> epsilon
*/
void load_parsing_table()
{
	parsing_table[0][0] = 0;
	parsing_table[0][1] = 1;
	parsing_table[1][0] = 2;
	parsing_table[1][1] = 3;
	parsing_table[1][2] = 4;
	parsing_table[1][3] = 4;
}

char stack_top()
{
	return stack[top-1];
}

void push(char ch)
{
	stack[top++] = ch;
}

void pop()
{
	top--;
}

void init_stack()
{
	top=0;
	push(STACK_BOTTOM_MARK);
	push('A');
}

int is_nonterminal(char ch)
{
	if ('A' <= ch && ch <= 'Z') return 1;
	else return 0;
}

int is_terminal(char ch)
{
	return (is_nonterminal(ch) == 0);
}

void predictive_parsing(int table[NONTERMINALS][TERMINALS+1], char rule[RULESIZE][MAX], char *input)
{
	char *p = input;
	char *str_p;
	int i, index=0, len;

	while (1) {
		if (stack_top() == STACK_BOTTOM_MARK) {
			if (*p == INPUT_END_MARK)
				printf("[accept]\n");	// parsing OK
			else printf("[error] -- Input is not empty!\n");
			return;
		}

		if (is_terminal(stack_top())) {	// pop -- terminal symbol
			if (*p == stack_top()) {
				pop();
				p++;
			} else {
				printf("[error] -- Stack is not empty!\n");
				return;
			}
		} else { // expand -- nonterminal
			index = parsing_table[stack_top()-'A'][*p-'a'];
			if (index != -1) {
				str_p = rule[index];
				len = strlen(str_p);
				printf("[CFG %d] %c -> %s\n", index, stack_top(), str_p);
				pop();
				for (i=len-1; i>=0; i--) {
					push(str_p[i]);
				}
			} else { // error
				printf("[error] %c -> %c\n", stack_top(), *p);
				return;
			}
		}
	}
}

int main()
{
	char input[100];

	load_create_rule();
	load_parsing_table();

	input_data(input);
	init_stack();

	predictive_parsing(parsing_table, create_rule, input);
	return 0;
}
