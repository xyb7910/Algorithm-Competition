/*
�������ƣ�������������� 
����˵����������ѡһ������Ԫ�أ��˴����,�������м�λ�ã���Ϊ���գ�
�ѱ���С��Ԫ�طŵ�������ߣ�������ķ����ұߡ�Ȼ�����õݹ飬�ٽ�����
�����������������������������������.
�������ߣ�ZXH (2010-7-28)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 
#include <iostream>
#include <fstream>
using namespace std;
#define N 100000
int a[N+1];
int n;    
 
void quick(int i,int j)
{
  int m,n,temp;
  int k;
  m=i;
  n=j;
  k = a[rand() % (j - i + 1) + i];
    while(m<=n)
  {
    while(a[m]<k&&m<j)  m++;  /* �������ұ�k���Ԫ��*/
    while(a[n]>k&&n>i)  n--;  /* ���ҵ����ұ�kС��Ԫ��*/ 
   
    if(m<=n)
    {               /*���ҵ��������������򽻻�*/
       temp=a[m];
       a[m]=a[n];
       a[n]=temp;

      m++;
      n--;
    }
  }
  if(m<j)  quick(m,j);  /*���õݹ�*/
  if(n>i)  quick(i,n);
}

int main()
{
   freopen("sort.in","r",stdin);
   freopen("sort.out","w",stdout);
   int i;
   scanf("%d",&n); 
   for(i=1;i<=n;i++)
     scanf("%d",&a[i]); 
   srand (time (0));//���������    
   quick(1,n);
  
   for(i=1;i<=n;i++)
     printf("%d ",a[i]);
}
