//��Ƭ¼�Ʃ�������3
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int a,b;
  bool operator<(const Node &x) const  //������"<"����
  {
    return a<x.a || (a==x.a && b<x.b);
  }
  bool operator<=(const Node &x) const //������"<="����
  {
    return a<x.a || (a==x.a && b<=x.b);
  }
} dp[21][21];

int main()
{
  freopen("record.in","r",stdin);
  freopen("record.out","w",stdout);
  int n,m,t,Long;
  scanf("%d%d%d",&n,&m,&t);
  memset(dp,0x3f3f3f3f,sizeof(dp));
  for(int i=0; i<=n; ++i)
  {
    dp[i][0].a=1;
    dp[i][0].b=0;
  }
  for(int i=1; i<=n; ++i)
  {
    scanf("%d",&Long);
    if(Long<=t)
    {
      for(int j=1; j<=i; ++j)
      {
        if(Long+dp[i-1][j-1].b>t)//������һ�ų�Ƭ�Ų���
        {
          dp[i][j].a=dp[i-1][j-1].a+1;
          dp[i][j].b=Long;
        }
        else                     //������һ�ų�Ƭ�ŵ���
        {
          dp[i][j].a=dp[i-1][j-1].a;
          dp[i][j].b=Long+dp[i-1][j-1].b;
        }
        dp[i][j]=min(dp[i-1][j],dp[i][j]);
      }
    }
  }
  int Ans=0;
  Node tmp= {m,t};
  for(int j=n; j>=1; --j)//�ҵ��������������ֵ
    if(dp[n][j]<=tmp)//�����ز������Ƚϴ�С
    {
      Ans=j;
      break;
    }
  printf("%d\n",Ans);
  return 0;
}

