//希尔排序
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int Data[MAXN],n;

void ShellSort(int *a, int n)//希尔排序
{
  int temp,i,j;
  for(int d=n/2; d>=1; d=d/2) //增量为d，每次减一半
    for(i=d; i<n; i++) //对每个数按组进行直接插入排序
    {
      temp=a[i];//注意：此插入排序和之前的插入排序实现方法略有区别
      for(j=i-d; (j>=0) && (a[j]>temp); j=j-d) //如果比它小，则这里就是它的位置了
        a[j+d]=a[j];
      a[j+d]=temp;
    }
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%d",&Data[i]);
  ShellSort(Data,n);//调用希尔排序

  for (int i=0; i<n; ++i)//输出
    printf("%d ",Data[i]);
  printf("\n");
  return 0;
}

