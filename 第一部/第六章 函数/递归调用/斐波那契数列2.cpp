//쳲��������иĽ��㷨 
#include <iostream>
#include <stdlib.h>
using namespace std;

int a[5000];
int f(int n)
{  
  if(n<3)
    return 1;
  if(a[n]>0)//���������n���ֵ 
    return a[n];//ֱ�ӷ��ظ�ֵ 
  a[n]=f(n-1)+f(n-2);//����ݹ������ֵ   
  return a[n];   
}

int main()
{
  int n;
  cin>>n;
  cout<<f(n);   
  system("pause");   
  return 0;
}
