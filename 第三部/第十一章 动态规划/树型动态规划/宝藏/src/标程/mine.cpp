//���� 
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct list
{
  int l;
  int r;
}node[2001];

int val[2001];//��ֵ 
int vis[2001][101];//���仯�������ӿ�ݹ��ٶ� 
int m,n;

int dp(int x,int m)
{
  if(m==0)//������ˣ�����0 
    return 0;
  if(vis[x][m]!=-1)//��������ֵ��ֱ�ӷ��� 
    return vis[x][m];
  if(x==0)//��·���� 
    return 0;
  int ans=0;
  ans=dp(node[x].r,m);//�����ֵܽڵ㣬�������� 
  //���������������ȷ��������������ߣ����������ֵ���
  for(int i=0;i<m;i++)//������ӣ�����һ��
    ans=max(ans,dp(node[x].l,i)+val[x]+dp(node[x].r,m-i-1));
  vis[x][m]=ans;//���仯���� 
  return ans;
}

int main()
{  
  freopen("mine.in","r",stdin);
  freopen("mine.out","w",stdout);      
  int i;
  scanf("%d%d",&n,&m);
  memset(vis,-1,sizeof(vis));
  for(i=1;i<=n;i++)
    scanf("%d",&val[i]);
  for(i=0;i<=n;i++)//��ʼ�� 
    node[i].l=node[i].r=0;
  for(i=1;i<=n;i++)//������������ 
  {
    int a,b;
    scanf("%d%d",&a,&b);
    node[b].r=node[a].l;
    node[a].l=b;
  }
  cout<<dp(node[0].l,m)<<endl;
  return 0;
}


