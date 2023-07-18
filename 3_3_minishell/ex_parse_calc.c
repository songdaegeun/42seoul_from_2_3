#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s_calculator
{
    char *expr;
    int tcnt;
	t_token *tokens[100];
	t_node *ps;
} t_calculator;

typedef struct s_token
{
    int priority;
    char ch;
	int value;
} t_token;

typedef struct s_node
{
	t_node *root;
	t_token *token;
	t_node *lc;
	t_node *rc;
} t_node;

bool IsOperator(char ch)
{
    return (ch =='+')||(ch=='-')||(ch=='*')||(ch=='/');
}

bool IsDigit(char ch)
{
    return (ch>='0')&&(ch<='9');
}

void View(t_calculator *cal)
{
    PostOrder(cal);
    printf("\n");
}

void run(t_calculator *cal)
{
    char *expr = cal->expr;
    printf("%s을 계산합니다....\n", expr);

    if(Lexical(cal))
    {
        if(Syntax(cal))
        {
            Parsing(cal);
            PostOrderView(cal);
            printf("%s=", expr);
            Calculate(cal);
            printf("\n");
        }
        else
        {
            printf("수식에 사용한 표현이 문법에 맞지 않습니다.\n");
        }
    }
    else
    {
        printf("사용할 수 없는 기호가 있습니다.\n");
    }
    printf("\n");
}

bool Lexical(t_calculator *cal)
{        
    char *expr = cal->expr;
    int i = 0;
    while(expr[i])
    {
        if(IsOperator(expr[i]))
        {
            i = MakeOperator(i, cal);
        }
        else
        {
            if(IsDigit(expr[i]))
            {
                i = MakeOperand(i, cal);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void View()
{
    cout<<ch<<" ";
}

bool MoreThanPriority(t_token *token_o, t_token *token_n)
{
    return token_o->priority >= token_n->priority;
}

int MakeOperator(int i, t_calculator *cal)
{
    char *expr = cal->expr;
	char ch;
    // tokens[tcnt] = new Operator(expr[i]);
    (cal->tokens)[cal->tcnt] = (t_token *)malloc(sizeof(t_token));
    ch = expr[i];
	(cal->tokens)[cal->tcnt]->ch = ch;
	if((ch=='+')||(ch=='-'))
	{
		(cal->tokens)[cal->tcnt]->priority = 1;
	}
	else
	{
		(cal->tokens)[cal->tcnt]->priority = 2;
	}
    cal->tcnt++;
    return i+1;
}

void View()
{
	cout<<value<<" ";
}

int MakeOperand(int i, t_calculator *cal)
{
	char *expr = cal->expr;
    int value = 0;
    while(IsDigit(expr[i]))
    {
        value = value*10 + expr[i] - '0';
        i++;
    }
    (cal->tokens)[cal->tcnt] = (t_token *)malloc(sizeof(t_token));
	(cal->tokens)[cal->tcnt]->priority = 3;  
    cal->tcnt++;
    return i;
}    

bool Syntax(t_calculator *cal)
{
    if(cal->tcnt % 2==0)
    {
        return false;
    }
    if((cal->tokens)[0]->priority !=3)
    {
        return false;
    }
    for(int i = 1; i < cal->tcnt; i+=2)
    {
        if((cal->tokens)[i]->priority==3)
        {
            return false;
        }            
        if((cal->tokens)[i+1]->priority != 3)
        {
            return false;
        }
    }
    return true;
}

void Add(t_token *token, t_node *root)
{
	// Node *now = new Node(token);
	t_node *now = (t_node*)malloc(sizeof(t_node));
	now->lc = 0;
	now->rc = 0;
	now->token = token;
	
	if(MoreThanPriority(root->token, token))
	{
		now->lc = root;
		root = now;
	}
	else
	{
		if(token->priority != 3)
		{
			now->lc = root->rc;
			root->rc = now;
		}
		else
		{
			t_node *pa = root;
			while(pa->rc)
			{
				pa = pa->rc;
			}
			pa->rc = now;
		}
	}
}

void PostOrder(t_calculator *cal)
{
	if(cal->tokens)
	{
		PostOrder(cal->tokens);
		PostOrder(sr->rc);
		sr->token->View();
	}
}
int Calculate()
{
	return PostOrderCalculate(root);
}
int PostOrderCalculate(Node *sr)
{
	if(sr->lc)
	{
		int lvalue = PostOrderCalculate(sr->lc);
		int rvalue = PostOrderCalculate(sr->rc);
		Operator *op = dynamic_cast(sr->token);
		switch(op->ch)
		{
		case '+': return lvalue + rvalue;
		case '-': return lvalue - rvalue;
		case '*': return lvalue * rvalue;
		case '/': 
			if(rvalue)
			{
				return lvalue / rvalue;
			}
			cout<<"divide zero error"<<endl;
			return 0;
		}
		throw "정의하지 않은 연산자입니다.";
	}
	Operand *op = dynamic_cast(sr->token);
	return op->value;
}


void Parsing(t_calculator *cal)
{
    // ps = new ParserTree((cal->tokens)[0]);
	t_node node;
	node.token = (cal->tokens)[0];
	node.rc = 0;
	node.lc = 0;
	node.root = &node;

    for(int i = 1; i < cal->tcnt;i++)
    {
        Add((cal->tokens)[i], node.root);
    }
}

void PostOrderView(t_calculator *cal)
{
    View(cal);
}

int Calculate()
{
    return ps->Calculate();        
}

int main()
{
    char tc_exprs[6][256]=
    {
        "2+3-5*5+6/2",
        "23*5/2+4*6",
        "2+4*5#6",
        "2+3*5+",
        "3+36+-7",
        "45+3*5-2+5/2*7",        
    };
    t_calculator *cal;
    for(int i = 0; i<6; i++)
    {
        // Calculator *cal  = new Calculator(tc_exprs[i]);
        cal = (t_calculator *)malloc(sizeof(t_calculator));
        cal->expr = tc_exprs[i];
        cal->tcnt = 0;

        run(cal);

        free(cal);
    }
	return 0;
}