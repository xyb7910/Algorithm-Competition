//�ж�����2
#include <iostream>
using namespace std;

int main()
{
  int year;
  cin>>year;
  if((year%400==0) || ((year%4==0) && (year%100!=0)))
    cout<<year <<"������"<<endl;
  else
    cout<<year<<"��������"<<endl;   
  system("pause");
  return 0;
}
