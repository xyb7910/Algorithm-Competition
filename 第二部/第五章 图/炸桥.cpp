#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1010;
struct node
{
  int v,man,id;
} n1,n2;
vector<node>Map[N];
int dfn[N],low[N];
int index,ans;

int dfs(int u,int fa)
{
  low[u] = dfn[u] = ++index;
  for(int i=0; i<Map[u].size(); i++)
  {
    int v = Map[u][i].v;
    int id = Map[u][i].id;
    if(id == fa) continue;
    if(!dfn[v])
    {
      dfs(v,id);//ע���2��������id
      low[u] = min(low[u],low[v]);
      if(low[v] > dfn[u])//�ҵ���
        ans = min(ans,Map[u][i].man);//������С������
    }
    else
      low[u] = min(low[u],dfn[v]);
  }
}

int main()
{
  int t,n,m;
  while(scanf("%d%d",&n,&m)!=EOF && n+m)
  {
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=0; i<=n; i++)
      Map[i].clear();
    index = 0;
    ans = INF;
    int a,b,c,cnt=0;//cntͳ����ͨ��������
    for(int ID=1; ID<=m; ID++)
    {
      scanf("%d%d%d",&a,&b,&c);
      n1.v=b,n1.man=c,n1.id=ID;
      n2.v=a,n2.man=c,n2.id=ID;
      Map[a].push_back(n1);
      Map[b].push_back(n2);
    }
    for(int i=1; i<=n; i++)//ö�٣���Ϊ���ܶ���һ����ͨ����
      if(!dfn[i])
      {
        cnt++;
        dfs(i,0);
      }
    if(cnt > 1)  //ͼ����ͨ�Ͳ���ȥ��
      ans = 0;
    else if(ans == INF)
      ans = -1;
    else if(ans == 0) //û�˿���,ҲҪ��һ��ȥ
      ans = 1;
    printf("%d\n",ans);
  }
  return 0;
}

