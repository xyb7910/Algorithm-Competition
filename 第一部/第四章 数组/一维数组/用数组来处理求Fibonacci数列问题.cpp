//��������������Fibonacci�������⡣
#include <iostream>
using namespace std;

int main()
{
  int i;
  int f[20]={1,1}; //a[0]=1,a[1]=1,���ࣱ����Ԫ���Զ���ֵΪ0
  for(i=2;i<20;i++)
     f[i]=f[i-2]+f[i-1];//���ε��� 
  for(i=0;i<20;i++)
  {
     if(i%5==0) 
       cout<<endl;//������Ϊһ��
     cout<<f[i]<<"  "; 
  }    
  system("pause");
  return 0;
}
