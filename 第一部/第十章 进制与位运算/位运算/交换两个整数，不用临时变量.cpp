//��������������������ʱ����
#include <iostream>
using namespace std;

int main()
{
  int a=123;
  int b=789;
  a=a^b;
  b=b^a;
  a=a^b;
  cout<<a<<" "<<b;//������Ϊ789 123 
  system("pause");
}
