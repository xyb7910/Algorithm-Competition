//����1+2+3+��+100��ֵ
#include <iostream>
using namespace std;

int main()
{
  int i=1,sum=0;
  while(i<=100)  //��i<=100ʱ����ִ��ѭ�����ڵ����
  {
    sum=sum+i;
    i++;
  }   
  cout<<sum<<endl;
  system("pause");
  return 0;
}
