/*
�������ƣ�ѡ������ 
����˵������Ҫ�����һ�����У�ѡ����С��һ�������һ��λ�õ���������
Ȼ����ʣ�µ�������������С����ڶ���λ�õ������������ѭ����������
�����������һ�����Ƚ�Ϊֹ�� ѡ�������ǲ��ȶ��ġ��㷨���Ӷ�O(n2)--[n��ƽ��]
�������ߣ�ZXH (2010-4-2)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 
#include "stdio.h"
#define N 100000
int a[N+1];
  
void select_sort(int n)
{
 int i, j, min, t;
 for (i=1; i<n; i++)
 {
    min = i; /*���赱ǰ�±�Ϊi������С���ȽϺ��ٵ���*/
    for (j=i+1; j<=n; j++)/*ѭ���ҳ���С�������±����ĸ�*/
    {
       if (a[j] < a[min])   
          min = j; /*������������ǰ���С������������±�*/
    }  
  
    if (min != i) /*���min��ѭ���иı��ˣ�����Ҫ��������*/
    {
       t = a[i];
       a[i] = a[min];
       a[min] = t;
    }
 }
}

int main()
{  
   freopen("sort.in","r",stdin);
   freopen("sort.out","w",stdout);
   int i,n;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
      
   select_sort(n);
   
   for(i=1;i<=n;i++)
     printf("%d ",a[i]);
   return 0;
}
