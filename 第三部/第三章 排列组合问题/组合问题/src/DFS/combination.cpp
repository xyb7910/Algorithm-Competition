#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[101]= {1};
bool pd[101];

void print()
{
  for(int i=1; i<=n; i++)
    cout<<a[i];
  cout<<endl;
}
void dfs(int i)
{
  if(i>n)
    print();
  else
    for(int j=a[i-1]; j<=m; j++)
      if(pd[j]==0)
      {
        pd[j]=1;
        a[i]=j;
        dfs(i+1);
        pd[j]=0;
      }
}
int main()
{
  freopen("combination.in","r",stdin);
  freopen("combination.out","w",stdout);
  cin>>m>>n;
  dfs(1);

  return 0;
}
