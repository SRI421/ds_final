#include<stdio.h>

#define MAX_HEAP 100
#define HEAPFULL(n) (n==MAX_HEAP)
#define HEAPEMPTY(n) (n!=0)

typedef struct node{
int key;
} element;

element heap[MAX_HEAP];
int n=0;

void insert(element item)
{
  int i;
  if(HEAPFULL(n))
  {
    printf("Heap Full");
    return;
  }
  i=++n;
  while((i!=1) && (item.key>heap[i/2].key))
  {
  	heap[i]=heap[i/2];
  	i/=2;
  }
  heap[i]=item;
}


element deleteHeap()
{
  int parent,child;
  element temp,item;
  if(n==0)
  {
  	printf("Heap is empty\n");
  	return;
  }
  item=heap[1];
  temp=heap[n--];
  parent=1;
  child=2;
  while(child<=n)
  {
  	if(child<n && heap[child].key< heap[child+1].key)
  		child++;
  	if(temp.key>=heap[child].key)
  		break;
  	heap[parent]=heap[child];
  	parent=child;
  	child*=2;
  }
  heap[parent]=temp;
  return item;
}


void display()
{
  int i;
  for(i=1;i<=n;i++)
  printf("-> %d\n",heap[i].key);

}



int main()
{
  int ch,n=0;
  element item;
  while(1)
  {
  	printf("\n1.Insert\n2.Display\n3.Delete\nEnter your choice : ");
  	scanf("%d",&ch);
  	switch(ch)
  	{
    	case 1:
          	printf("Enter the element you need to insert : ");
          	scanf("%d",&item.key);
          	insert(item);
          	break;
    	case 2:
          	printf("The contents in the heap are as follows : \n");
          	display();
          	break;
    	case 3:
          	item=deleteHeap();
          	printf("The element deleted is : %d\n",item.key);
          	break;
  	}

  }
  return 0;
}
