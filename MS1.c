#include<stdio.h>
#include<stdlib.h>
#define MAX_STACKS 10

typedef struct
{
  int key;
}element;

struct stack
{
  element data;
  struct stack* link;
};
typedef struct stack* stackpointer;

stackpointer top[MAX_STACKS];

void push(element e,int s)
{
  stackpointer temp=(stackpointer)malloc(sizeof(struct stack));
  temp->data=e;
  temp->link=top[s];
  top[s]=temp;
}

element pop(int i)
{
  stackpointer temp=top[i];
  element e,t;
  t.key=-1;
  if(!temp)
  return t;

  e=top[i]->data;
  top[i]=top[i]->link;
  free(temp);
  return e;
}
void display(int i)
{
  stackpointer temp=top[i];
  while(temp)
  {
    printf("%d\n",temp->data.key);
    temp=temp->link;
  }
}

void main()
{
  element e;
  int choice,s;
  for(int i=0;i<10;i++)
  top[i]=NULL;

  while(1)
  {
    printf("1)Push\n");
    printf("2)Pop\n");
    printf("3)Display\n");
    printf("4)Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter stack number\n");
              scanf("%d",&s);
              printf("Enter element\n");
              scanf("%d",&e.key);
              push(e,s);
              break;
      case 2: printf("Enter stack number\n");
              scanf("%d",&s);
              e=pop(s);
              if(e.key==-1)
              printf("Empty stack\n");

              else
              printf("%d deleted\n",e.key);

              break;
      case 3: printf("Enter stack number\n");
              scanf("%d",&s);
              display(s);
              break;
      case 4: exit(0);
              break;
    }
  }
}
