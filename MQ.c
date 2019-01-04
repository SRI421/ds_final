#include<stdio.h>
#define MAXSIZE 100
#define MAXQUEUE 10


int queue[MAXSIZE];
int front[MAXQUEUE],rear[MAXQUEUE],boundary[MAXQUEUE+1];

void insert(int i)
{
  int x;
  if(front[i]!=boundary[i+1])
  {
  	printf("Enter the element you want to add : ");
  	scanf("%d",&x);
  	queue[++rear[i]]=x;
  }
  else
  	printf("\n\n\tQUEUE IS FULL!!!\n\n");

}


int deleteq(int i)
{
  if(front[i]==boundary[i])
  {
    printf("\n\n\tTHE QUEUE IS EMPTY\n\n");
    return -1;
  }
  else
  return queue[front[i]++];

}


void display(int i)
{
  int x;
  for(x=front[i]+1;x<=rear[i];x++)
  	printf("-->%d\n",queue[x]);

}


int main()
{
  int i,j,n,ch;
  printf("Enter the number of queue you want :");
  scanf("%d",&n);
  front[0]=boundary[0]=rear[0]=-1;
  for(j=1;j<=n;j++)
  {
  	front[j]=boundary[j]=rear[j]=(MAXSIZE/n)*j;
  }
  printf("\n\n\t\tQUEUE INITIALIZED\n\n");
  while(1)
  {
    printf("Enter \n1.INSERT \n2.DELETE \n3.DISPLAY\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      	printf("Enter the stack number :");
      	scanf("%d",&i);
      	insert(i);
      	break;
      case 2:
      	printf("Enter the stack from which you want to delete :");
      	scanf("%d",&i);
      	printf("Element deleted is : %d",deleteq(i));
      	break;
      case 3:
      	printf("Enter which stack number to display : ");
      	scanf("%d",&i);
      	display(i);
      	break;
      default:
      	printf("Invalid choice ! \n");
    }
  }
}
