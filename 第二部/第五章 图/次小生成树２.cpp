//��С�������� 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 105;

bool Tlink[MAXN][MAXN],vis[MAXN];//Tlink��¼���Ƿ���MST��,vis[i]��ʾi���Ƿ���MST 
int w[MAXN][MAXN];//w[i][j]Ϊi��j�ıߵ�Ȩֵ 
int lowc[MAXN], pre[MAXN];
int Max[MAXN][MAXN];//Max[i,j]ΪMST������i,jΨһ·������Ȩֵ
int n, m;

int MAX( int a, int b)
{
    return a > b ? a : b;
}

int prim()
{
  int i, j, p, k;
  int minc, res = 0;
  memset( vis, false, sizeof vis);
  memset( pre, 0, sizeof pre);
  memset( Max, 0, sizeof Max);
  vis[1] = 1;//�ӵ�һ���ڵ㿪ʼ 
  pre[1] = 1;//ǰ���ǽڵ㣱 
  for( i = 2; i <= n; i ++)//��ʼ��  
  { 
    lowc[i] = w[1][i]; 
    pre[i] = 1;
  }
  
  for( i = 2; i <= n; i ++)//prim�㷨 
  {
    minc = inf; p = -1;
    for( j = 1; j <= n; j ++) 
    {
      if( !vis[j] && lowc[j] < minc)//�ҳ��ڵ�û�б�����MST����СȨֵ�� 
      {
        minc = lowc[j];
        p = j;
      }
    }
    vis[p] = true;//�ýڵ����MST 
    res += minc;//��С��Ȩֵ�ۼ� 
    Max[ pre[p] ][p] = minc;
    Tlink[ pre[p] ][p] = true;//�������߱��Ϊ��С���ı� 
    Tlink[p][ pre[p] ] = true;//�������߱��Ϊ��С���ı� 
    for( k = 1; k <= n; k ++)
      Max[k][p] = MAX( Max[ pre[p] ][p], Max[k][p]);//�������Ӹñߵ����ֵ 
    for( j = 1; j <= n; j ++)//����p�㵽j�����С��Ȩֵ 
      if( !vis[j] && lowc[j] > w[p][j]) 
      {
        lowc[j] = w[p][j];
        pre[j] = p;//ȷ��ǰ���ڵ� 
      }
  }
  return res;
}

int main()
{
  int s, e, t, Ans, ans;
  bool ok = true;//�Ƿ�Ψһ��С�������ı�־ 
  cin>>n>>m;
  for( int i = 1; i <= n; i ++)
    for( int j = 1; j <= n; j ++)
      w[i][j] = inf;
  memset( Tlink, false, sizeof Tlink);
  for( int i = 1; i <= m; i ++)
  {
    cin>>s>>e>>t;
    w[s][e] = t;
    w[e][s] = t;
  }
  Ans = prim();//prim�㷨�����С������Ȩֵ 
  for( int i = 1; i <= n; i ++)
  {
    for( int j = 1; j <= n; j ++)
    {
      if( w[i][j] == inf || Tlink[i][j])//����õ�����С�����������ޱ������ 
        continue;
      ans = Ans + w[i][j] - Max[i][j];//Max[i,j]:MST������i,j������Ȩֵ
      if( Ans == ans)//������ּӷ���С����һ���ߺ�Ȩֵ��ԭ��С��Ȩֵ��� 
      {
        ok = false;//���Ψһ��С�� 
        break;
      }
    }
    if( !ok) 
      break;
  }
  if( ok) 
    printf( "%d\n", Ans);
  else 
    printf( "Not Unique!\n");
  return 0;
}
