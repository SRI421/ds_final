#include<stdio.h>
#include<string.h>

int fail[20];

void failure(char *p)
{
  fail[0]=-1;
  int i,j,n;

  n=strlen(p);

  for(j=1;j<=n;j++)
  {
    i=fail[j-1];

    while((p[j]!=p[i+1]) && i>=0)
    {
      i=fail[i];
    }

    if(p[j]==p[i+1])
    fail[j]=i+1;

    else fail[j]=-1;
  }
}

int kmp(char *s,char *p)
{
  int lens=strlen(s);
  int lenp=strlen(p);

  int i=0,j=0;

  while(i<lens && j<lenp)
  {
    if(s[i]==p[j])
    {
      i++;
      j++;
    }
    else if(j==0)
    i++;

    else j=fail[j-1]+1;
  }
  return ((j==lenp)?(i-lenp):-1);
}


void main()
{
  char str[20],pat[20];
  int pos,i,ch,lenp;
  printf("enter the string\n");
  scanf("%s",str);

  printf("enter the pattern\n");
  scanf("%s",pat);

  failure(pat);

  pos=kmp(str,pat);

  while(1)
  {
    printf("enter 1.failure 2.match 3.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: lenp=strlen(pat);
              for(i=0;i<lenp;i++)
              printf("%c->%d\n",pat[i],fail[i]);
              break;
      case 2:if(pos==-1) printf("pattern not found\n");
            else printf("pattern found at position %d\n",pos+1);
            break;
      case 3: return;
    }
  }

}
