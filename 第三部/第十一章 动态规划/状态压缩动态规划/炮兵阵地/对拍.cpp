#include <stdio.h>  
#include <string.h>  
#define MAX 110  
#define INF 1000000000  
  
  
int state[MAX][MAX], one[MAX][MAX];         //state[i][j]��ʾ��i�е�j���Ϸ�״̬��one��ʾ��i�е�j���Ϸ�״̬�к�1�ĸ���  
int ans, stnum[MAX], sum[MAX * 20];         //stnum[i]��ʾi�кϷ���״̬����sum[i]Ϊi״̬��1�ĸ���  
int n, m, map[MAX][MAX], dp[MAX][70][70];   //dp[i][j][k]��ʾ��i�е�j��״̬��-1�е�k��״̬���е����1�ĸ���  
  
  
inline int max(int a, int b) 
{  
  return a > b ? a : b;  
} 
 
void Initial() 
{  
  ans = 0;  
  memset(dp, 0, sizeof (dp));  
  memset(map, 0, sizeof (map));  
  memset(one, 0, sizeof (one));  
  memset(stnum, 0, sizeof (stnum));  
} 
 
void GetOneSum() 
{  
  //Ԥ�����Ȱ�ÿ��״̬�ﺬ�е�1�����������  
  for (int i = 0; i <= (1 << 10); ++i) 
  {  
    int tp = 0;  
    for (int j = 0; j <= 10; ++j)  
      if (i & (1 << j)) 
        tp++;  
    sum[i] = tp;  
  }  
} 
 
int Check(int x) 
{  
  //x&(x>>1)���жϵ�ǰ���Ƿ��ǰһ�г�ͻ,x>>2����ǰ����  
  if (x > 1 && (x & (x >> 1))) 
    return 0;  
  if (x > 2 && (x & (x >> 2))) 
    return 0;  
  return 1;  
} 
 
void FindState(int x, int tot) 
{  
  //Ԥ�����ѵ�x���кϷ���״̬ȫ���ҳ������浽state�����У�tot�Ǳ������е�p��ѹ��������һ��״̬  
  for (int i = 0; i < (1 << m); ++i)  
    if (Check(i) && (i & tot) == i) 
    {  
      //��i&tot�� == i��ʾ����i�Ǽ���tot���Ӽ��ϣ���˼��i����ĺ��е��ж���p��  
      stnum[x]++;  
      int tp = stnum[x];  
      state[x][tp] = i;  
      one[x][tp] = sum[i];  
    }  
}  
  
int main()   
{  
  int i, j, k, s;  
  char tp[MAX];  
  GetOneSum();  
  while (scanf("%d%d", &n, &m) != EOF) 
  {  
    Initial(), stnum[0] = 70;  
    for (i = 1; i <= n; ++i) 
    {  
      scanf("%s", tp);  
      for (k = j = 0; j < m; ++j) 
      {         
        map[i][j] = (tp[j] == 'P' ? 1 : 0);  
        k += (map[i][j] ? (1 << j) : 0);  
      }  
      FindState(i, k);  
    }  
  
    //��ʼ����1��  
    for (j = 1; j <= stnum[1]; ++j)  
      for (k = 1; k <= stnum[0]; ++k)  
        dp[1][j][k] = one[1][j];  
    //״̬ת��  
    for (i = 2; i <= n; ++i)  
      for (j = 1; j <= stnum[i]; ++j)  
        for (k = 1; k <= stnum[i - 1]; ++k)  
          if (!(state[i][j] & state[i - 1][k])) 
          {                 
            //�ж�����״̬�Ƿ��г�ͻ  
            int tpmax = 0;  
            for (s = 0; s <= stnum[i - 2]; ++s) 
            {  
              if (!(state[i][j] & state[i-2][s])              //�ж�����״̬�Ƿ��г�ͻ  
              && !(state[i - 1][k] & state[i - 2][s]))  
                tpmax = max(dp[i - 1][k][s], tpmax);  
            }  
            dp[i][j][k] = tpmax + one[i][j];  
          }  
  
    //Update Answer  
    for (j = 1; j <= stnum[n]; ++j)  
      for (k = 1; k <= stnum[n-1]; ++k)  
        ans = max(ans, dp[n][j][k]);  
    printf("%d\n", ans);  
  }
  return 0;  
}  
