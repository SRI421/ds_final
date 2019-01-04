#include<stdio.h>
#define MAX 100
#define COL 20

typedef struct
{
  int col;
  int row;
  int val;
}element;

element a[MAX];
element b[MAX];

void fasttranspose()
{
  int rowTerms[COL],sp[COL];
  int i,j;

  if(a[0].val>0)
  {
    for(i=0;i<a[0].col;i++)
    rowTerms[i]=0;

    for(i=1;i<a[0].val;i++)
    rowTerms[a[i].col]++;

    sp[0]=1;

    for(i=1;i<a[0].col;i++)
    sp[i]=sp[i-1]+rowTerms[i-1];

    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    for(i=1;i<a[0].val;i++)
    {
      j=sp[a[i].col]++;
      b[j].row=a[i].col;
      b[j].col=a[i].row;
      b[j].val=a[i].val;
    }
  }
}


void main()
{
  int i;
  printf("enter no of row col and val\n");
  scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);

  for(i=1;i<=a[0].val;i++)
  {
    printf("enter row col and val\n");
    scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
  }

  fasttranspose();

  printf("original sparse matrix\n");
  printf("row\tcol\tval\n");
  for(i=1;i<=a[0].val;i++)
  {
    printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
  }

  printf("\ntransposed sparse matrix\n");
  printf("row\tcol\tval\n");
  for(i=1;i<=b[0].val;i++)
  {
    printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
  }
}
