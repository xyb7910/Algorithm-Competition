//���� 
#include <iostream>
using namespace std;
#define MAXV 50000
#define max(a,b) a>b?a:b

int main()
{
  freopen("Profit.in","r",stdin);
  freopen("Profit.out","w",stdout);
  int dp[MAXV];
  int v[11],c[11];
  int n,m,year,t,i,j,sum,k;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d%d%d",&m,&year,&t);
    for(i=1;i<=t;i++)
    {
      scanf("%d%d",&v[i],&c[i]);
      v[i]=v[i]/1000;//��Ϊ��ֵ��1000�ı��������Գ���1000
    }
    sum=0;
    for(i=0;i<year;i++)//��Ϊÿ�궼ҪͶ�ʣ�����ÿ�궼Ҫ����
    {			
      memset(dp,0,sizeof(dp));	//��������г�ʼ��
      sum=m/1000;		//�����ڵ�i��Ͷ��ǰ��ӵ�ж���Ǯ
      for(j=1;j<=t;j++)	//��ȫ����DP��������Ͷ����ǰj����Ʊ�ļ�ֵ���DP[k]
      {		
		for(k=0;k<=sum;k++)
		  if(k>=v[j])
		    dp[k]=max(dp[k],dp[k-v[j]]+c[j]);
      }
      m+=dp[sum];//������׬������Ϊ��һ��ĳ�ʼ�ʽ� 
    }
    printf("%d\n",m);
  }
  return 0;
}
