//唱片录制 ─方法1
#include <bits/stdc++.h>
using namespace std;

int g[21][21][21],Long[21];

int main()
{
  freopen("record.in","r",stdin);
  freopen("record.out","w",stdout);
  int n,m,t;
  scanf("%d%d%d",&n,&m,&t);
  for (int i=1; i<=n; i++)
    scanf("%d",&Long[i]);
  for (int i=1; i<=n; i++)
    for (int j=0; j<=m; j++)
      for (int k=0; k<t; k++)//k不超过唱片长度
      {
        if (k>=Long[i])
          g[i][j][k]=max(g[i-1][j][k],g[i-1][j][k-Long[i]]+1);
        else if(t-Long[i]>=0 && j>0)
          g[i][j][k]=max(g[i-1][j][k],g[i-1][j-1][t-Long[i]]+1);
        else
          g[i][j][k]=g[i-1][j][k];
      }
  printf("%d\n",g[n][m][0]);
  return 0;
}

