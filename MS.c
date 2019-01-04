#include<stdio.h>
#define MAXSIZE 100
#define MAXSTACK 10


int stack[MAXSIZE];
int top[MAXSTACK],boundary[MAXSTACK+1];

void push(int i)
{
int x;
if(top[i]!=boundary[i+1])
{
	printf("Enter the element you want to add : ");
	scanf("%d",&x);
	stack[++top[i]]=x;
}
else{
	printf("\n\n\tSTACK IS FULL!!!\n\n");
}
}


int pop(int i)
{
  if(top[i]==boundary[i])
  {
    printf("\n\n\tTHE STACK IS EMPTY\n\n");
    return -1;
  }
  else
  return stack[top[i]--];

}


void display(int i)
{
  int x;
  for(x=boundary[i]+1;x<=top[i];x++)
  	printf("-->%d\n",stack[x]);

}


int main()
{
  int i,j,n,ch;
  printf("Enter the number of stacks you want :");
  scanf("%d",&n);
  top[0]=boundary[0]=-1;
  for(j=1;j<=n;j++)
  {
  	top[j]=boundary[j]=(MAXSIZE/n)*j;
  }
  printf("\n\n\t\tSTACK INITIALIZED\n\n");
  while(1)
  {
    printf("Enter \n1.PUSH \n2.POP\n3.DISPLAY\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      	printf("Enter the stack number :");
      	scanf("%d",&i);
      	push(i);
      	break;
      case 2:
      	printf("Enter the stack from which you want to delete :");
      	scanf("%d",&i);
      	printf("Element deleted is : %d",pop(i));
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
