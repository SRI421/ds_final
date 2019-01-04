#include<stdio.h>

typedef enum{lparen,rparen,plus,minus,divide,times,mod,eos,operand}precedence;

precedence stack[50];

int n=0,top=-1;

char expr[50];

precedence getToken(char *symbol,int* n)
{
  (*symbol)=expr[(*n)++];
  switch((*symbol))
  {
    case '(':return lparen;
              break;
    case ')':return rparen;
              break;
    case '+':return plus;
              break;
    case '-':return minus;
              break;
    case '*':return times;
              break;
    case '/':return divide;
              break;
    case '%':return mod;
              break;
    case '\0':return eos;
              break;
    default: return operand;
  }
}

void push(precedence t)
{
  stack[++top]=t;
}

precedence pop()
{
  return stack[top--];
}

int eval()
{
  precedence token;
  char symbol;
  int op1,op2;
  token=getToken(&symbol,&n);
  while(token!=eos)
  {
    if(token==operand)
      push(symbol-'0');
    else
    {
      op2=pop();
      op1=pop();
      switch(token)
      {
        case plus : push(op1+op2);
                    break;
        case minus : push(op1-op2);
                    break;
        case times : push(op1*op2);
                    break;
        case divide : push(op1/op2);
                    break;
        case mod : push(op1%op2);
                    break;
      }
    }
    token=getToken(&symbol,&n);
  }
  return pop();
}

void main()
{
  int ans;
  printf("Enter an expression\n");
  scanf("%s",expr);
  ans=eval();
  printf("Ans=%d\n",ans);
}
