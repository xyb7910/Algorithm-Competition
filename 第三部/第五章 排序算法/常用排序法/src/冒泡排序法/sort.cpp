/*
ð�ݷ�
��ԭ��Ϊ��a[0]��ʼ�����ν���ͺ����Ԫ�رȽ�,
��a[0]>a[i]���򽻻����ǣ�һֱ�Ƚϵ�a[n]��
ͬ���a[1],a[2],...a[n-1]�������������
*/

#include "stdio.h"
int a[100000];

void bubble(int n) /*�������������������׵�ַ�������С*/
{
 int i,j,temp;
 for(i=0;i<n-1;i++)
   for(j=i+1;j<n;j++)  /*ע��ѭ����������*/
   if(a[i]>a[j])  {
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
   }
}

main()
{
   int i,n;   
   freopen("sort.in","r",stdin);
   freopen("sort.out","w",stdout);   
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     
   bubble(n);
   
   for(i=0;i<n;i++)
     printf("%d ",a[i]);
}
