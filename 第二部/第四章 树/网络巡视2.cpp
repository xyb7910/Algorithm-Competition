//����Ѳ��2
#include <bits/stdc++.h>
using namespace std;

int n,vis[4200];
vector <int> Edg[4200];
int dp[4200][2];

void dfs(int u)
{
  vis[u]=1;
  dp[u][0]=1;//��ʼ��
  dp[u][1]=0;
  for(int i=0; i<Edg[u].size(); i++)
  {
    int v=Edg[u][i];
    if(!vis[v])
    {
      dfs(v);
      dp[u][0]+=min(dp[v][0],dp[v][1]);//�ӽڵ����µı�Ҫ������
      dp[u][1]+=dp[v][0];//��v�������ڼ��� ����ʹ��edge(u,v)������
    }
  }
}

int main()
{
  while(cin>>n)
  {
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
      Edg[i].clear();
    int root=-1;
    for(int k=1; k<=n; k++)
    {
      int u,num,v;
      scanf("%d:(%d)",&u,&num);//ע���ʽ������
      if(root==-1)
        root=u;
      for(int i=1; i<=num; i++)
      {
        scanf("%d",&v);
        Edg[u].push_back(v);
        Edg[v].push_back(u);//˫���
      }
    }
    dfs(root);
    cout<<min(dp[root][0],dp[root][1])<<endl;
  }
  return 0;
}

