//��������
#include <iostream>
using namespace std;

int main()
{
  int f1=1,f2=1,i;
  for(i=1;i<=20;i++)
  {
    cout<<f1<<' '<<f2; 
    if(i%2==0)  //��һ���������f1��f2����4�����֣���ֵ������һ��
      cout<<'\n';
    f1=f1+f2;
    f2=f2+f1;
  }
  system("pause");
  return 0;
}
