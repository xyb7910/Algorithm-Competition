//��e��ֵ
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  float s=1,t=1;
  int i;
  for(i=1; i<=100; i++)
  {
    t=t/i;//1/i!��ǰ��1/(i-1)!���ƶ���
    s=s+t;
  }
  cout<<s;
  system("pause");
  return 0;
}
