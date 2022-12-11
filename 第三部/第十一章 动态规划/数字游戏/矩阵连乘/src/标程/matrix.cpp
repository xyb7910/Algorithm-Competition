//�������� 
#include <iostream>
#include <stdlib.h>
const int MAXN=110;

int	F[MAXN][MAXN];
int	R[MAXN],C[MAXN],N;//��ά�ȷֿ������������飬��������� 

int main()
{
  freopen ("matrix.in", "r", stdin);
  freopen ("matrix.out", "w", stdout);

  scanf ("%d", &N);
  for (int i = 1; i <= N; ++i)//�˴�i�ӣ���� 
    scanf ("%d%d", &R[i], &C[i]);

  memset (F, 0, sizeof (F));//��ʼ�� 
  for (int l = 2; l <= N; ++l)//lȷ����������ϲ���Ϊ2ʱ����2������ϲ� 
    for (int i = 1; i <= N - l + 1; ++i)//��ĳ��lֵ�µ�i�еĸ��ӵ�ֵ
    {
      int j = i + l - 1;//ȷ���ұߵĽ��� 
	  F[i][j] = 1000000000;
      for (int k = i; k < j; ++k)//��i��j��l��������kλ�÷ָ���������
        if (F[i][k]+F[k+1][j]+R[i]*C[k]*C[j]<F[i][j])
		  F[i][j]=F[i][k]+F[k+1][j]+R[i]*C[k]*C[j];
     }

  printf ("%d\n", F[1][N]);
  return 0;
}
