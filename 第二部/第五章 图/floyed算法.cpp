//floyed�㷨 
#include <iostream>
#define maxn 100
using namespace std;
int n,s,t;
int a[maxn+1][maxn+1];

void floyed()
{
  int i,j,k;
  for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(a[i][k]!=-1 && a[k][j]!=-1)//Ҫע��ѡ��MAX_INT��ӻ��ɸ��� 
          if(a[i][k]+a[k][j]<a[i][j])
            a[i][j]=a[i][k]+a[k][j];
}

void init()
{
  int m,i,u,v;
  cin>>n>>m;
  for(u=1;u<=n;u++)
    for(v=1;v<=n;v++)
      a[u][v]=-1;//�˴�������ΪMAX_INT,������ӻ�ɸ��� 
  for(i=1;i<=m;i++)
    cin>>u>>v>>a[u][v];
  cin>>s>>t;
}

int main()
{
  init();
  floyed();
  cout<<a[s][t]+a[t][s]<<endl;
  return 0;
} 
