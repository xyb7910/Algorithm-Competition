/*
�������ƣ��������� 
����˵�������뷨��һ�ֱȽ�ֱ�۵����򷽷��������Ȱ�����ͷ����Ԫ���ź���
�����ΰѺ����Ԫ�ز����ʵ���λ�á�������Ԫ�ز���Ҳ�����������
�������ߣ�ZXH (2010-4-2)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 
#include "stdio.h"
#define N 100000
int a[N+1];

void insert(int n)
{
  int i,j,temp;
  for(i=2;i<=n;i++)
  {
    temp=a[i];     /*tempΪҪ�����Ԫ��*/
    j=i-1;
    while(j>=1 && temp<a[j]) /*��a[i-1]��ʼ�ұ�a[i]С������ͬʱ������Ԫ�������*/
    {   
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;  /*����*/
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
   insert(n);
   
   for(i=1;i<=n;i++)
     printf("%d ",a[i]);
   return 0;  
}
