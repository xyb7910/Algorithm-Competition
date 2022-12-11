//KM�㷨 
#include <algorithm> 
#include <iostream>
using namespace std;

const int MAX = 1024;

int n;            // X �Ĵ�С
int w[MAX] [MAX]; // w[i][j]��ʾ��i��j��Ȩ��
int A[MAX],B[MAX]; // ����
bool VisitX [MAX], VisitY [MAX];//��ӛ�Ƿ�������
int match [MAX]; // match[1]=3��ʾ����1�붥��3ƥ��

void init (int size)// ��ʼ��Ȩ��
{
  n = size;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)
      cin>>w[i][j];   
}

bool dfs(int u)// �� X(u)Ѱ������·
{
  VisitX [u] = true;
  for (int v = 0; v < n; v ++)
    if (!VisitY[v] && A[u]+B[v]==w[u][v])//����A[u]+B[v]==w[u][v]�ſɼ��� 
    {
      VisitY[v]=true;
      if (match[v]==-1 || dfs(match[v]))
      {
        match [v]=u;//����ƥ�� 
        return true;//������·�򷵻�true  
      }
    }
  return false;
}

int km(bool maxsum)
{
  int i, j;
  if (!maxsum)//���������СȨ 
    for (i = 0; i < n; i ++)
      for (j = 0; j < n; j ++)
        w[i] [j] = -w[i] [j];
    
  for (i = 0; i < n; i ++)// ��ʼ�����,��A[i]=max,B[i]=0
  {
    A[i] = -0x1FFFFFFF;
    B[i] = 0;              
    for (j = 0; j < n; j ++)
      if (A[i] < w[i] [j])
        A[i] = w[i] [j]; 
  }
  memset (match, -1, sizeof (match));//��δƥ�� 
  for (int u = 0; u < n; u ++)
    while (1)
    {
      memset (VisitX, 0, sizeof (VisitX)); 
      memset (VisitY, 0, sizeof (VisitY));
      if (dfs (u))//��������·�����˳� 
        break;

      int d=0x7FFFFFFF;// ��������·��������dֵ 
      for (i = 0; i < n; i ++)
        if (VisitX [i])
          for (j = 0; j < n; j ++)
            if(!VisitY [j])
              d= min(A[i]+B[j]-w[i][j],d);

      for (i = 0; i < n; i ++)//���ı�� 
      {
        if (VisitX [i])
          A[i] -= d;
        if (VisitY [i])
          B[i] += d;
      }
    }

  int ans = 0; 
  for (i = 0; i < n; i ++)
    ans += w[match[i]][i];

  if (!maxsum)//�������СȨ 
  {
    ans = -ans;
    for (i = 0; i < n; i ++)
      for (j = 0; j < n; j ++)
        w[i] [j] = -w[i][j];//�ָ�ԭweight[][]��ֵ 
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  init (n);
  int cost = km(true);//�����Ȩ 
  cout<<cost<<endl;
  return 0;
} 
