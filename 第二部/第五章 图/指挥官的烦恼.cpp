//ָ�ӹٵķ��� 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define INF 0x7f7f7f7f

int pre[MAXN],id[MAXN],vis[MAXN],n,m,pos;
long long in[MAXN];//����С���Ȩ,pre[v]Ϊ�ñߵ����
struct node//�ߵ�Ȩ�Ͷ���
{
  int u,v;
  long long w;
} edge[MAXN * MAXN];

long long Zhu_Liu(int root,int N,int E)
{
  long long Ans = 0;//����С����ͼ��Ȩֵ
  while(true)
  {
    //1.����̻�����A
    for(int i = 0; i < N; i++)
      in[i] = INF;//��ʼ��Ϊ�����
    for(int i = 0; i < E; i++)//����ÿ����
    {
      int u = edge[i].u;
      int v = edge[i].v;
      if(edge[i].w < in[v] && u != v)//����ΪȨֵ��С�����
      {
        pre[v] = u;//�ڵ�uָ��v
        in[v] = edge[i].w;//��С���
        if(u == root)//��������ʵ�ʵ����
          pos = i;
      }
    }
    for(int i = 0; i < N; i++)//�ж��Ƿ������С����ͼ
      if(i!=root && in[i] == INF) return -1;//�е�û�����,����С����ͼ
    //2.�һ�
    int Ring = 0;//��¼����
    memset(id, -1, sizeof(id));
    memset(vis, -1, sizeof(vis));
    in[root] = 0;
    for(int i = 0; i < N; i++) //���ÿ����
    {
      Ans += in[i];//��¼Ȩֵ
      int v = i;
      while(vis[v] != i && id[v] == -1 && v != root)
      {
        vis[v] = i;
        v = pre[v];
      }
      if(v != root && id[v] == -1)
      {
        for(int u = pre[v]; u != v; u = pre[u])
          id[u] = Ring;//��ǽڵ�uΪ�ڼ�����
        id[v] = Ring++;
      }
    }
    if(Ring == 0) break; //�޻�break
    for(int i = 0; i < N; i++)
      if(id[i] == -1)
        id[i] = Ring++;
    //3.������ͼ������,���±��
    for(int i = 0; i < E; i++)
    {
      int u = edge[i].u;
      int v = edge[i].v;
      edge[i].u = id[u];
      edge[i].v = id[v];
      if(id[u] != id[v])
        edge[i].w -= in[v];
    }
    N = Ring;
    root = id[root];
  }
  return Ans;
}

int main()
{
  while(scanf("%d%d", &n, &m) != EOF)
  {
    long long sum = 0;
    for(int i = 0; i<m; i++)
    {
      scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
      edge[i].u++;
      edge[i].v++;
      sum+=edge[i].w;
    }
    sum++;//sum++�ǽ�������ı���ԭ���ı���ȫ���ֿ� 
    for(int i=m; i<m+n; i++) //�������
    {
      edge[i].u=0;
      edge[i].v=i-m+1;
      edge[i].w=sum;//���������������ı�Ȩ��ͬ
    }
    long long ans=Zhu_Liu(0, n+1,m+n);//n+1Ϊ�ܽ����,m+nΪ�ܱ���
    if(ans==-1 || ans-sum>=sum)
      printf("impossible\n");
    else
      printf("%lld %d\n",ans-sum,pos-m);
    printf("\n");
  }
  return 0;
}
