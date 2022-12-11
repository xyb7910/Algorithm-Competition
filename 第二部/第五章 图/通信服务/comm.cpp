#include <bits/stdc++.h>
using namespace std;
const int N=2010;
int n,tim;
int DfsNode[N],father[N];
vector<int>edg[N];
bool s[N],Set[N];//s[]Ϊ���ǵ�,Set[]Ϊ֧�伯��ע��Set����Сд

void dfs(int u,int fa)
{
  DfsNode[tim++]=u;
  for(int i=0; i<edg[u].size(); i++)
  {
    int v=edg[u][i];
    if(v!=fa)
    {
      father[v]=u;
      dfs(v,u);
    }
  }
}

int Check()
{
  int ans=0;
  for(int i=n-1; i>=0; i--)//��DFS�������м��
  {
    int t=DfsNode[i];
    if(!s[t])//��ǰ��δ�����ǣ�����������֧�伯��Ҳ����֧�伯�еĵ�����
    {
      if(!Set[father[t]])//��ǰ��ĸ��׽�㲻����֧�伯
      {
        Set[father[t]]=true;//����������֧�伯
        ans++;
      }
      s[t]=true;//��ǵ�ǰ��㱻����
      s[father[t]]=true;//��ǵ�ǰ���ĸ���㱻����
      s[father[father[t]]]=true;//��ǵ�ǰ���ĸ����ĸ���㱻����
    }
  }
  return ans;
}

int main()
{
  scanf("%d",&n);
  int u,v;
  for(int i=1; i<n; i++)//��ͼ
  {
    scanf("%d%d",&u,&v);
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  dfs(1,0);//�ӽ��1����
  printf("%d\n",Check());
  return 0;
}
