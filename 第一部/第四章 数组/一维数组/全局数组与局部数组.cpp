 //ȫ��������ֲ����� 
#include <iostream>
using namespace std;
int a[10];

int fun()//��һ�������� 
{
  a[0]=0;//a[]Ϊȫ�����飬���Ա����� 
  //b[0]=0; ����ĵ��ã���Ϊb[]Ϊ�ֲ����� 
}

int main() 
{
  int i,b[10];
  for(i=0;i<=9;i++)
    cout<<a[i]<<' ';//�����ֵ��Ϊ0 
  cout<<endl;  
  for(i=0;i<=9;i++)
    cout<<b[i]<<' ';//�����ֵĩ֪ 
  system("pause");
  return 0;
}
