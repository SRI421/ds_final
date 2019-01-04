#include<stdio.h>

typedef enum {lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

precedence getToken(char *symbol,int *n);
void printToken(precedence t);

char expr[100];
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};

void push(precedence);
precedence pop();

precedence stack[100];
int top =0;

void main()
{
  printf("Enter a infix expression\n");
  scanf("%s",expr);
  precedence token,temp;
  int n=0;
  char symbol;
  stack[0]=eos;
  for(token=getToken(&symbol,&n);token!=eos;token=getToken(&symbol,&n))
  {
    if(token==operand)
    printf("%c",symbol);
    else if (token==rparen)
    {
      while(stack[top]!=lparen)
      printToken(pop());
      temp=pop();
    }
    else
    {
      while(isp[stack[top]]>=icp[token])
      printToken(pop());
      push(token);
    }
  }
  while((token=pop())!=eos)
  printToken(token);
  printf("\n");
}

void push(precedence t)
{
  stack[++top]=t;
}

precedence pop()
{
  return stack[top--];
}

precedence getToken(char *symbol,int *n)
{
  *symbol=expr[(*n)++];
  switch(*symbol)
  {
    case '(':return lparen;
    case ')':return rparen;
    case '+':return plus;
    case '-':return minus;
    case '/':return divide;
    case '*':return times;
    case '%':return mod;
    case '\0':return eos;
    default:return operand;
  }
}

void printToken(precedence t)
{
  switch(t)
  {
    case lparen:printf("(");
                break;
    case rparen:printf(")");
                break;
    case plus:printf("+");
                break;
    case minus:printf("-");
                break;
    case divide:printf("/");
                break;
    case times:printf("*");
                break;
    case mod:printf("%");
                break;
  }
}
