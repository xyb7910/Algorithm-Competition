//Ӳ�����⣭��ϱ��� 
#include<iostream>
#include<cstdlib>
#include<cstring>
#define INF 99999999
using namespace std;

const int MAX=100002;
bool dp[MAX];
int a[102],c[102];//a�����i��Ӳ�ҵļ�ֵ,c�������. 

int main()
{
  freopen("coin.in","r",stdin);
  freopen("coin.out","w",stdout);  
  int n,m;
  while(cin>>n>>m,n||m)
  {
    for(int i=0;i<n;++i)
      cin>>a[i];
    for(int i=0;i<n;++i)
      cin>>c[i];
    if(m<=0)//�����mΪ����
    {
      cout<<"0\n";
      continue;
    }
    memset(dp,false,sizeof(bool)*(m+1));
    dp[0]=true;
    for(int i=0;i<n;++i)
    {
      if(a[i]*c[i]>=m)//��ȫ���� 
      { 
		for(int j=a[i];j<=m;++j)
        {
		  if(dp[j-a[i]])
            dp[j]=true;
		}
      }
      else//���ر��� 
      {
		int k=0;
		for(k=1;k*2-1<=c[i];k=k*2)//�������Ż�����01��������. 
        {
		  for(int j=m;j>=k*a[i];--j)
          {
		    if(dp[j-k*a[i]])
              dp[j]=true;
		  }
		}
		for(int j=m;j>=(c[i]-k+1)*a[i];--j)
        {
		  if(dp[j-(c[i]-k+1)*a[i]])
             dp[j]=true;
		}
      }
    }
    int sum=0;
    for(int i=1;i<=m;++i)
      if(dp[i])
        sum++;
    cout<<sum<<endl;
  }
  return 0;
} 
