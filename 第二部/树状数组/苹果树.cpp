//ƻ���� 
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int t[MAXN], a[MAXN],Left[MAXN], Right[MAXN];
vector<vector<int>>Edge(MAXN);//POJ��vector��Ҫ����д������vector
int N,M,Time;

int LowBit(int x)
{
  return x&(-x);
}

void DFS(int node)//Ϊÿһ��node���ʱ�������ֵ����ֵ��
{
  Left[node] = Time;
  for(int i=0; i<Edge[node].size(); i++)
  {
    Time++;
    DFS(Edge[node][i]);
  }
  Right[node] = Time;
}

void Update(int k, int num)//�޸Ľڵ�k�����Ϊ1��ɾ��Ϊ-1
{
  for(int i=k; i<=N; i+=LowBit(i)) //nΪ���鳤��
    t[i]+=num;
}

int GetSum(int x)
{
  int sum=0;
  for(int i=x; i>0; i-=LowBit(i))
    sum +=t[i];
  return sum;
}

int main()
{
  while(scanf("%d", &N)!=EOF)
  {
    memset(Left, 0, sizeof(Left));
    memset(Right, 0, sizeof(Right));
    memset(a, 0, sizeof(a));
    memset(t, 0, sizeof(t));
    for(int i=0; i<MAXN; i++)
      Edge[i].clear();
    int x,y;
    for(int i=1; i<N; i++) //����x��y��
    {
      scanf("%d%d", &x, &y);
      Edge[x].push_back(y);
    }
    Time = 1;
    DFS(1);//ÿ������Ӧһ����߽���ұ߽磬���Ĺ�Ͻ��Χ������߽絽�ұ߽�
    for(int i=1; i<=N; i++)
    {
      a[i] = 1;//���ÿ��a[]�϶���һ��ƻ��,���ڵ㶼��һ����
      Update(i,1);//ͬʱ������״�����ֵ
    }
    scanf("%d%*c", &M);
    char ch;
    for(int i=0; i<M; i++)
    {
      scanf("%c %d%*c", &ch, &y);
      if(ch == 'Q')//b����������[Left[b], right[b]]
        printf("%d\n", GetSum(Right[y]) - GetSum(Left[y]-1));
      else
      {
        a[y]?Update(Left[y],-1):Update(Left[y],1);
        a[y] = !a[y];//��Ϊ�෴��״̬
      }
    }
  }
  return 0;
}
