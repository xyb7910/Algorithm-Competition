//���ӳ��ҵĵݹ��� 
#include <iostream>
using namespace std;

int peach(int day)
{
  int n;
  if(day==10)
    n=1;
  else
    n=2*(peach(++day)+1);
  return n;    
}

int main()
{
  cout<<peach(1)<<endl;//���1534
  system("pause");
}
