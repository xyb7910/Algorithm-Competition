//�ж�����1
#include <iostream>
using namespace std;

int main()
{
  int year,leap;
  cin>>year;
  if(year%400==0)
    cout<<"������";
  else if(year%100!=0)
  {
    if (year%4==0)   
      cout<<"������";
    else
      cout<<"��������";
  }
  else
    cout<<"��������";     
  system("pause");
  return 0;
}
