//sort
#include <iostream>
using namespace std;
#define N 100000
int a[N+1];
int n;    
 
void QuickSort(int i,int j)
{
  int m,n,temp;
  int k;
  m=i;
  n=j;
  k=a[(i+j)/2];  /*ѡȡ�Ĳ���*/
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
  if(m<j)  QuickSort(m,j);  /*���õݹ�*/
  if(n>i)  QuickSort(i,n);
}

int main()
{
   freopen("sort.in","r",stdin);
   freopen("sort.out","w",stdout);
   int i;
   scanf("%d",&n); 
   for(i=1;i<=n;i++)
     scanf("%d",&a[i]);  
   QuickSort(1,n);
  
   for(i=1;i<=n;i++)
     printf("%d ",a[i]);
}
