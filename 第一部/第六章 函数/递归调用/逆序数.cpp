//������������ĵݹ��� 
#include <iostream>
using namespace std;

int turn(int n)
{  
  if(n>=10)
  {
    cout<<n%10;
    turn(n/10);
  }
  else
    cout<<n;   
}

int main()
{
  int n;
  cin>>n;
  turn(n); 
  system("pause");
  return 0;
}
