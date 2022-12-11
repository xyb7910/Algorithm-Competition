//ͨ������
#include <bits/stdc++.h>
using namespace std;
const int NN=105;
int n,root,root_son,index;
int  dfn[NN],low[NN];
bool cut[NN];//�������
vector<int> Map[NN];

void tarjan(int u)//����tarjan�㷨�е�һ��
{
  dfn[u]=low[u]=++index;
  for (int i=0; i<Map[u].size(); i++)
  {
    int v=Map[u][i];
    if (!dfn[v])//���û�з��ʹ�v 
    {
      tarjan(v);
      if (u==root)
        root_son++;
      else  //����Ǹ����
      {
        low[u]=min(low[u],low[v]);
        if (low[v]>=dfn[u])
          cut[u]=true;//��̽���Ѳ����ȸõ����ĵ㣬��õ��Ǹ��
      }
    }
    else
      low[u]=min(low[u],dfn[v]);
  }
}

void init_input()
{
  for (int i=1; i<=n; i++)//ͼ���
    Map[i].clear();
  memset(dfn,0,sizeof(dfn));
  memset(cut,false,sizeof(cut));
  int u,v;
  while (scanf("%d",&u),u)//ע�������ʽ
    while (getchar()!='\n')
    {
      scanf("%d",&v);
      Map[u].push_back(v);
      Map[v].push_back(u);
    }
}

int main()
{
  while (scanf("%d",&n)!=EOF && n)
  {
    init_input();//�����ʼ��
    root=1;
    root_son=0;
    tarjan(root);
    if (root_son>1) //�����������ĸ��Ǹ��
      cut[root]=true;
    int sum=0;
    for (int i=1; i<=n; i++)//�ۼƸ��
      sum+=cut[i];
    printf("%d\n",sum);
  }
  return 0;
}

