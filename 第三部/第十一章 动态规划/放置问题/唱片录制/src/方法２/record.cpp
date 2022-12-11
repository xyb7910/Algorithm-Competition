//³ªÆ¬Â¼ÖÆ ©¤·½·¨2
#include <bits/stdc++.h>
using namespace std;

int Long[21],f[21][21*21];

int main()
{
  freopen("record.in","r",stdin);
  freopen("record.out","w",stdout);
  int n,m,t;
  scanf("%d%d%d",&n,&m,&t);
  for(int i=1; i<=n; i++)
    scanf("%d",&Long[i]);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=t*m; j++)
    {
      f[i][j]=f[i-1][j];
      if(j%t>=Long[i])
        f[i][j]=max(f[i][j],f[i-1][j-Long[i]]+1);
      else if (j/t*t-Long[i]>=0)
        f[i][j]=max(f[i][j],f[i-1][j/t*t-Long[i]]+1);
    }
  printf("%d\n",f[n][t*m]);
  return 0;
}

