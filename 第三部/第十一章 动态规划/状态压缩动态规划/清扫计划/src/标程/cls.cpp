//��ɨ�ƻ� 
#include <iostream>
#include <cstdlib>
#define INF 100000000
using namespace std;
int dis[12][12];
int dp[1<<11][12];
int n,ans,_min;

int main()
{
  freopen("cls.in","r",stdin);
  freopen("cls.out","w",stdout);
  while(scanf("%d",&n) && n)
  {
    for(int i = 0;i <= n;++i)
      for(int j = 0;j <= n;++j)
		scanf("%d",&dis[i][j]);
    for(int k = 0;k <= n;++k)//floyd�㷨 
      for(int i = 0;i <= n;++i)
		 for(int j = 0;j <= n;++j)
		   if(dis[i][k] + dis[k][j] < dis[i][j])
			 dis[i][j] = dis[i][k] + dis[k][j];
		
    for(int State = 0;State<= (1<<n)-1;++State)//ö������״̬��λ�����ʾ
      for(int i = 1;i <= n;++i)
      {
		if(State & (1<<(i-1)))//״̬S���Ѿ���������i
		{
		  if(State == (1<<(i-1)))//״̬Sֻ��������I	
            dp[State][i] = dis[0][i];//���Ž���Ȼ��dis[0][i],��DP�ı߽� 
		  else//���S�о����������
		  {
		    dp[State][i] = INF;
            //��û��������I��״̬�У�Ѱ�Һ��ʵ��м��Jʹ�þ�����̣���FLOYDһ��
		    for(int j = 1;j <= n;++j)
		      if(State & (1<<(j-1)) && j != i)//ö�ٲ��ǳ���I����������j 
				dp[State][i] = min(dp[State^(1<<(i-1))][j] + dis[j][i],dp[State][i]);
		  }
		}
      }
    ans = dp[(1<<n)-1][1] + dis[1][0];
    for(int i = 2;i <= n;++i)//�ҵ����Ž� 
      if(dp[(1<<n)-1][i] + dis[i][0] < ans)
        ans = dp[(1<<n)-1][i] + dis[i][0];
    printf("%d\n",ans);
  }
  return 0;
}
