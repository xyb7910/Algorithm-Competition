//���ӳ���
#include <iostream>
using namespace std;

int main()
{
  int day=9,x1,x2=1;
  while(day>0)
  {
    x1=(x2+1)*2;//�ڣ�����������ǵڣ�������������ӣ���ģ���
    x2=x1;
    day--;            
  }
  cout<<x1;
  //system("pause");
  return 0;
}
