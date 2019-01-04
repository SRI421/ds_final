#include<stdio.h>
#include<stdlib.h>
#define MAX_STACKS 10
typedef struct
{
  int key;
}element;

struct queue
{
  element data;
  struct queue* link;
};

typedef struct queue* queuepointer;

queuepointer front[MAX_STACKS],rear[MAX_STACKS];

void addq(element e,int s)
{
  queuepointer temp=(queuepointer)malloc(sizeof(struct queue));
  temp->data=e;
  temp->link=NULL;
  if(front[s])
  rear[s]->link=temp;
  else
  front[s]=temp;
  rear[s]=temp;
}

element deleteq(int i)
{
  queuepointer temp=front[i];
  element e,t;
  t.key=-1;
  if(!temp)
  return t;

  e=temp->data;
  front[i]=temp->link;
  free(temp);
  return e;
}

void display(int i)
{
  queuepointer temp=rear[i];
  while(temp)
  {
    printf("%d->",temp->data.key);
    temp=temp->link;
  }
}

void main()
{
  element e;
  int choice,s;
  for(int i=0;i<10;i++)
  front[i]=NULL;

  while(1)
  {
    printf("1)Add\n");
    printf("2)Delete\n");
    printf("3)Display\n");
    printf("4)Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter queue number\n");
              scanf("%d",&s);
              printf("Enter element\n");
              scanf("%d",&e.key);
              addq(e,s);
              break;
      case 2: printf("Enter stack number\n");
              scanf("%d",&s);
              e=deleteq(s);
              if(e.key==-1)
              printf("Empty queue\n");

              else
              printf("%d deleted\n",e.key);

              break;
      case 3: printf("Enter queue number\n");
              scanf("%d",&s);
              display(s);
              break;
      case 4: exit(0);
              break;
    }
  }
}
