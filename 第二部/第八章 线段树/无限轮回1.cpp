//�����ֻة�����ö��
#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
  int n;
  while (scanf ("%d",&n)!=-1)
  {
    for (int i=0; i<n; i++)
      scanf ("%d",&a[i]);
    int sum=0;
    for (int i=0; i<n; i++)//�����ʼ���е�������
      for (int j=i+1; j<n; j++)
        if (a[i]>a[j])
          sum++;
    int minn=sum;
    for (int i=0; i<n; i++)
    {
      sum=sum-a[i]+(n-a[i]-1);
      minn=min(sum,minn);
    }
    printf ("%d\n",minn);
  }
  return 0;
}

