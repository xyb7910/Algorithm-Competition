#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6;
int n=0;
char s[maxn];

bool ok(int x,int y,int k)
{
  if(x-y>=2 && x>=k)
    return 1;
  if(y-x>=2 && y>=k)
    return 1;
  return 0;
}

void write(int k)
{
  int i,x=0,y=0;
  for(i=0; i<n; i++)
  {
    if(s[i]=='W')
      x++;
    else
      y++;
    if(ok(x,y,k))
    {
      printf("%d:%d\n",x,y);
      x=y=0;
    }
  }
  printf("%d:%d\n",x,y);
}

int main()
{
  while(scanf("%c",&s[n]),s[n]!='E')
    if(s[n]=='W' || s[n]=='L')
      n++;
  write(11);
  printf("\n");
  write(21);
  return 0;
}
