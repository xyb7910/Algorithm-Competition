//�ߵͽ����� 2
#include <iostream>
using namespace std;


int main()
{
  unsigned int n;
  cin>>n;
  n=(n>>16)|(n<<16);
  cout<<n<<endl;
  return 0;
}
