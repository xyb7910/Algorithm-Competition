//������
# include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int i,j,a[10000+1];
  for(i=2;i<10001;i++) //����ֵ
     a[i]=i;
  for(i=2;i<sqrt(10001);i++)   
    for(j=i+1;j<10001;j++)
    {
      if(a[i]!=0 && a[j]!=0)
         if(a[j]%a[i]==0) //����ܱ��������������Ϊ����
            a[j]=0;
     }   
  for(i=2;i<10001;i++)  //��������ӡ����
    if(a[i]!=0)  
      cout<<a[i]<<' ';
  getchar();
  return 0;
}
