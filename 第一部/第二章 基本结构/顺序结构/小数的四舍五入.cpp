//С������������ 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double x;
  cout<<"������һ��˫������";
  cin>>x;
  x=(int)(x*100+0.5);
  x/=100;
  cout<<setprecision(2)<<fixed<<x<<endl;
  system("pause");
  return 0;
}
