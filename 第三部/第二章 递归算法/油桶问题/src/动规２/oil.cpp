//��Ͱ���⣭���棲 
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  freopen("oil.in","rb",stdin);
  freopen("oil.out","w",stdout);
  int n,m;
  scanf("%d %d",&n,&m);
    
  int i,j,cost[n+1];
  for(i=1;i<=n;i++)
    scanf("%d",&cost[i]);
    
  bool f[m+1];
  for(i=1;i<=m;i++) 
    f[i]=0; //��0 
  f[0]=1; //f[i][0]=true 
    
  for(j=1;j<=n;j++)//ѹ�������01�������� 
    for(i=m;i>0;i--)
      f[i]=f[i] | ((i-cost[j]>=0) & f[i-cost[j]]); 
    
  printf("%s\n",f[m]?"yes":"no");
  return 0;
}
