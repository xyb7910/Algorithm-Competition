//�ڽ��б�
#include <bits/stdc++.h>
using namespace std;

int Head[100100];//Head[i]���������i�ıߵı��
int Cnt;//��ʾ�ߵı��

struct Node
{
  int u;                              //�ߵ����
  int v;                              //�ߵ��յ�
  int w;                              //�ߵ�Ȩֵ
  int next;                           //ָ����һ���ߵı��
} edge[10000];

void Add(int u,int v,int w)           //�ӱ�
{
  edge[++Cnt].u=u;
  edge[Cnt].v=v;
  edge[Cnt].w=w;
  edge[Cnt].next=Head[u];             //����
  Head[u]=Cnt;
}

int main()
{
  int n,e,u,v,w;
  cin>>n>>e;                          //���붥�����ͱ���
  for(int i=0; i<e; i++)
  {
    cin>>u>>v>>w;
    Add(u,v,w);                       //�ӱߵ��ڽ��б�
  }
  for(int k=1; k<=n; ++k)             //����ڽ��б�
  {
    cout<<k;
    for(int i=Head[k]; i; i=edge[i].next)
      cout<<"->"<<edge[i].v<<"("<<edge[i].w<<")";
    cout<<endl;
  }
  return 0;
}

