#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int data;
}element;

element *queue;

int front=0,rear=0,capacity=5;

void display()
{
  int i;
  for(i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
  printf("%d->",queue[i].data);
}

element queueempty()
{
  element e;
  e.data=-1;
  return e;
}

element deleteq()
{
  if(front==rear)
  {
    return queueempty();
  }
  else
  {
    front=(front+1)%capacity;
    return queue[front];
  }
}

void copy(element *s,element *e,element *nq)
{
  int i=0;
  while(s<e)
  {
    *(nq+i)=*s;
    i++;
    s++;
  }
}

void queuefull()
{
  element* newq=malloc(2*capacity*sizeof(element));
  int start=(front+1)%capacity;

  if(start<2) copy(queue+start,queue+capacity,newq);
  else
  {
    copy(queue+start,queue+capacity,newq);
    copy(queue,queue+rear+1,newq+capacity-start);
  }

  front=2*capacity-1;
  rear=capacity-1;
  capacity=capacity*2;
  free(queue);
  queue=newq;
}

void addq(element x)
{
  rear=(rear+1)%capacity;
  if(front==rear)
  {
    queuefull();
  }
  queue[rear]=x;
}

int main()
{
  int ch;
  queue=(element*)malloc(capacity*sizeof(element));
  element x;
  while(1)
  {
    printf("enter 1.insert 2.delete 3.display 4.exit\n");
    scanf("%d",&ch);

    switch (ch)
    {
      case 1:printf("enter element to insert\n");
              scanf("%d",&x.data);
              addq(x);
              break;
      case 2: x=deleteq();
              if(x.data==-1) printf("the q is empty\n");
              else printf("the element deleted is %d\n",x.data);
              break;
      case 3:display();
            break;
      case 4:exit(0);
    }
  }
}
