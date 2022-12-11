/*���н�ͨ 

  f[i][j][m] = min{f[i][k][t] + f[k][j][m - t]} 
    
  d[m][i][j] ��ʾi �� j����� m ��·���м���k
  l[m][i][j] ��ʾi �� k����ӵ�·����
  r[m][i][j] ��ʾk �� j����ӵ�·����
  ��Ȼ l[m][i][j] + r[m][i][j] == m
  ���ѽ������  
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 10;
const int INF = 10000 + 10;

typedef int int2[MAXN][MAXN];

int n, M;
int2 f[11], d[11];
int2 l[11], r[11];

struct Que
{
  int x, y, t;
}q[MAXN];
int cnt;

void pushinq(int x, int y, int t)
{
  int temp;
  Que &q1 = q[++cnt];
  q1.x = x;
  q1.y = y;
  q1.t = t;
  if (q1.x>q1.y)
    temp = q1.x, q1.x = q1.y, q1.y = temp;
}

void init1()
{
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 0; k <= M; ++k)
        f[k][i][j] = INF;
}

int comp (const void *x, const void *y)
{
  Que &a = *(Que *)x;
  Que &b = *(Que *)y;
  if (a.x == b.x)
    return a.y - b.y;
  else
    return a.x - b.x;
}

void init()
{
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (f[0][i][j] != INF)
        for (int m = 1; m <= M; ++m)
          f[m][i][j] = f[m][i][j] = f[m - 1][i][j] / 2;
}

void print()
{
  for (int k = 0; k <= M; ++k)
  {
    printf("%d:\n", k);
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
        printf("%d ", f[k][i][j]);
      printf("\n");
    }
    printf("\n\n");
  }
}

bool dfs(const int &m,const int &i, const int &j)
{
  if (d[m][i][j])
  {// ���i j֮���н�㣬��ô�������
   // ����ֵ��ʾ�Ƿ�������һ�������߶� ֻ�����˲����
    if (l[m][i][j] && dfs(l[m][i][j], i, d[m][i][j]))
      pushinq(i,d[m][i][j],l[m][i][j]);
    if (r[m][i][j] && dfs(r[m][i][j], d[m][i][j], j))
      pushinq(d[m][i][j],j,r[m][i][j]);
    return 0;
  }
  return 1;
}

int main()
{
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  int x, y, w;
  scanf("%d %d", &n, &M); 
  init1();
  while (scanf("%d %d %d", &x, &y, &w) != EOF && x)
  {
    f[0][x][y] = f[0][y][x] = w;
    //print();
  }
  init();
  if (M == 0)//��� 0 �����У� �������ʼ��floyd
  {
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
          if(f[0][i][k]!=INF&&f[0][k][j]!=INF &&(f[0][i][j] == INF
                        || f[0][i][j] > f[0][i][k] + f[0][k][j]))
             f[0][i][j] = f[0][i][k] + f[0][k][j];
  }
  else//����ѭ��
  { 
    for (int m = 1; m <= M; ++m)
      for (int t = 1; t <= m; ++t)
        for (int k = 1; k <= n; ++k)
          for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
              if (f[m - t][i][k] != INF && f[t][k][j] != INF &&
                 (f[m][i][j]==INF||f[m][i][j]>f[m-t][i][k]+f[t][k][j]))
              {
                f[m][i][j] = f[m - t][i][k] + f[t][k][j];
                d[m][i][j] = k;
                l[m][i][j] = m-t;
                r[m][i][j] = t;
              }
  }
  //print();
  printf("%d\n", f[M][1][n]);
  if (M)//��ȻM == 0 ʱ�����·��
  {
    dfs(M, 1, n); // ���ѽ�ȥ������ӵ�·��
    qsort(&q[1], cnt, sizeof(Que), comp);
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= q[i].t; ++j)
      {
        //����ѭ������Ϊһ��·�Ͽ�����Ӳ�ֹ1��·��
        printf("%d %d\n", q[i].x, q[i].y);
      }
  }
  return 0;
}
