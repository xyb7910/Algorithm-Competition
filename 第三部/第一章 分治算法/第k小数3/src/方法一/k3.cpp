//�ڣ�С������������ 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long LL;
LL A[100000], B[100000]; 
int compare(const void * p, const void * q)
{
  return *(LL *)p - *(LL *)q;
}
 
LL cal(LL A[],LL m,LL B[],LL n,LL mid)//����midֵ���������е������� 
{
  LL i, j;
  LL cnt = 0;
 
  j = n - 1;
  for (i=0; i<m; ++i)
  {
    while (j>=0 && A[i]+B[j]>mid)//��λ����������ӱ�midС��λ�� 
      --j;
    cnt += (j+1);//�ۼ� 
  }
  return cnt;
}
 
LL findKth(LL A[],LL m,LL B[],LL n,LL k)
{
  LL min = A[0] + B[0];
  LL max = A[m - 1] + B[n - 1];
  LL mid;
  LL ans;
 
  while (min <= max)//���� 
  {
    mid = ((max - min) >> 1) + min;
    if (k <= cal (A, m, B, n, mid))
      max = mid - 1;
    else
      min = mid + 1;
  }
  return min;
}
 
int main()
{
  freopen("k3.in","r",stdin);
  freopen("k3.out","w",stdout);
  LL m, n,k,i;
 
  while(scanf ("%lld%lld%lld", &m, &n, &k) != EOF)
  {
    for (i=0; i<m; ++i)
      scanf ("%lld", &A[i]);
    for (i=0; i<n; ++i)
      scanf ("%lld", &B[i]);
    qsort (A, m, sizeof(LL), compare);
    qsort (B, n, sizeof(LL), compare);
    printf ("%lld\n", findKth (A, m, B, n, k));
  }
  return 0;
}
