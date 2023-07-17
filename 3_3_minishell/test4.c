#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tcnt = 0;

typedef struct s_calculator
{
    char *expr;
} t_calculator;

void Run(t_calculator* cal)
{
    char *expr = cal->expr;

    // cout<<expr<<"을 계산합니다. ..."<<endl;
    printf("%s을 계산합니다. ...\n",expr);
    if(Lexical())
    {
        if(Syntax())
        {
            Parsing();
            PostOrderView();
            cout<<expr<<"="<<Calculate()<<endl;
        }
        else
        {
            cout<<"수식에 사용한 표현이 문법에 맞지 않습니다."<<endl;
        }
    }
    else
    {
        cout<<"사용할 수 없는 기호가 있습니다."<<endl;
    }
    cout<<endl;
}

struct Calculator
{
    bool Lexical()
    {        
        int i = 0;
        while(expr[i])
        {
            if(IsOperator(expr[i]))
            {
                i = MakeOperator(i);
            }
            else
            {
                if(IsDigit(expr[i]))
                {
                    i = MakeOperand(i);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool IsOperator(char ch)
    {
        return (ch =='+')||(ch=='-')||(ch=='*')||(ch=='/');
    }
    bool IsDigit(char ch)
    {
        return (ch>='0')&&(ch<='9');
    }
    
    struct Token
    {
        int priority;
        bool MoreThanPriority(Token *token)
        {
            return priority>=token->priority;
        }
    };
    struct Operator:public Token
    {
        char ch;
        Operator(char ch)
        {
            this->ch = ch;
            if((ch=='+')||(ch=='-'))
            {
                priority = 1;
            }
            else
            {
                priority = 2;
            }
        }
        void View()
        {
            cout<<ch<<" ";
        }
        
    };
    Token *tokens[100];
    int tcnt;
    int MakeOperator(int i)
    {
        tokens[tcnt] = new Operator(expr[i]);
        tcnt++;
        return i+1;
    }
    struct Operand:public Token
    {
        int value;
        Operand(int value)
        {
            this->value = value;
            priority = 3;            
        }
        void View()
        {
            cout<<value<<" ";
        }
        
    };
    
    int MakeOperand(int i)
    {
        int value = 0;
        while(IsDigit(expr[i]))
        {
            value = value*10 + expr[i] - '0';
            i++;
        }
        tokens[tcnt] = new Operand(value);
        tcnt++;
        return i;
    }    

    bool Syntax()
    {
        if(tcnt%2==0)
        {
            return false;
        }
        if(tokens[0]->priority !=3)
        {
            return false;
        }
        for(int i = 1; i<tcnt; i+=2)
        {
            if(tokens[i]->priority==3)
            {
                return false;
            }            
            if(tokens[i+1]->priority != 3)
            {
                return false;
            }
        }
        return true;
    }

    struct ParserTree
    {
        struct Node
        {
            Token *token;
            Node *lc;
            Node *rc;
            Node(Token *token)
            {
                this->token = token;
                lc = rc = 0;
            }
        };
        Node *root;
        ParserTree(Token *token)
        {
            root = new Node(token);
        }
        void Add(Token *token)
        {
            Node *now = new Node(token);
            Token *st = root->token;
            if(st->MoreThanPriority(token))
            {
                now->lc = root;
                root = now;
            }
            else
            {
                if(token->priority !=3)
                {
                    now->lc = root->rc;
                    root->rc = now;
                }
                else
                {
                    Node *pa = root;
                    while(pa->rc)
                    {
                        pa = pa->rc;
                    }
                    pa->rc = now;
                }
            }
        }
        void View()
        {
            PostOrder(root);
            cout<<endl;
        }
        void PostOrder(Node *sr)
        {
            if(sr)
            {
                PostOrder(sr->lc);
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
    };
    ParserTree *ps;
    void Parsing()
    {
        ps = new ParserTree(tokens[0]);
        for(int i = 1; i<tcnt;i++)
        {
            ps->Add(tokens[i]);
        }
    }
    void PostOrderView()
    {
        ps->View();
    }
    int Calculate()
    {
        return ps->Calculate();        
    }
};

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
        cal = (t_calculator *)malloc(sizeof(t_calculator));
        cal->expr = tc_exprs[i];

        run(cal);

        // delete cal;
        free(cal);

    }
    return 0;
}