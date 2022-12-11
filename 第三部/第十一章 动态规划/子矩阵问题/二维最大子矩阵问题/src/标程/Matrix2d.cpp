//��ά����Ӿ������� 
#include <iostream>
#include <cstdlib>
using namespace std;
int a[201][201],sum[201][201];
int temp[200+1];
int n,m;

void solve()
{
  long i,j,k,max=-INT_MAX,sumall;
  for(i=0;i<=n;i++)   
    for(j=i+1;j<=n;j++)   //��i�е�j��
    {
      for(k=1;k<=m;k++)      //��ѭ�����i��j�е�k�еĺ�
        temp[k]=sum[j][k]-sum[i][k];
      sumall=0;
      for(k=1;k<=m;k++)   //����������к�һ�����ҵ����ֵ
      {
        sumall+=temp[k];
        if(sumall>max)   //��¼���ֵ 
          max=sumall;
        if(sumall<0)
          sumall=0;
      }
    }
  cout<<max<<endl;;
}

void init()
{
  int i,j;
  cin>>n>>m;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      cin>>a[i][j];
  for(i=1;i<=n;i++)    // sum[i,j]��ʾ�����j��ǰi��Ԫ�صĺͣ�    
    for(j=1;j<=m;j++)
        sum[i][j]=sum[i-1][j]+a[i][j];//ѹ������ 
}

int main()
{
  freopen("Matrix2d.in","r",stdin);
  freopen("Matrix2d.out","w",stdout);  
  init();
  solve();
  return 0;
}
