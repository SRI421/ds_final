#include<stdio.h>
#define MAX 100
#define COM(x,y) x==y?0:x>y?1:-1
typedef struct
{
  int coef;
  int expo;
}element;

element poly[MAX];
int avail=0;

void attach(int co,int ex)
{
  poly[avail].coef=co;
  poly[avail++].expo=ex;
}

void add(int startA,int endA,int startB,int endB,int *startc,int *endc)
{
  *startc=avail;
  int sum=0;
  while(startA<=endA && startB<=endB)
  {
    switch (COM(poly[startA].expo,poly[startB].expo))
    {
      case 1:attach(poly[startA].coef,poly[startA].expo);
              startA++;
              break;
      case 0:sum=poly[startA].coef+poly[startB].coef;
              attach(sum,poly[startA].expo);
              startA++;
              startB++;
              break;
      case -1:attach(poly[startB].coef,poly[startB].expo);
              startB++;
              break;
    }
  }
  for(;startA<=endA;startA++)
  attach(poly[startA].coef,poly[endA].expo);

  for(;startB<=endB;startB++)
  attach(poly[startB].coef,poly[endB].expo);

  *endc=avail-1;
}

void main()
{
  int i,n,m,startA,startB,endA,endB,startc,endc;

  printf("enter no of terms in poly1\n");
  scanf("%d",&n);
  printf("enter the coeficients and exponents\n");
  for(i=0;i<n;i++)
  scanf("%d%d",&poly[i].coef,&poly[i].expo);

  printf("enter no of terms in poly2\n");
  scanf("%d",&m);
  printf("enter the coeficients and exponents\n");
  for(i=n;i<n+m;i++)
  scanf("%d%d",&poly[i].coef,&poly[i].expo);

  avail=n+m;
  add(0,n-1,n,n+m-1,&startc,&endc);

  printf("the addition of two polynomials are\n");
  for(i=startc;i<=endc;i++)
  printf("+%dx^%d",poly[i].coef,poly[i].expo);
}
