//��N��������ĸ���������3����sqrt(N)��ѭ��
#include <iostream>
using namespace std;
int i,ii,n;

int main()
{
  cin>>n;
  i=n;
  ii=0;
  while(i>=5)
  {
    i=i/5;
    ii=ii+i;
  }
  cout<<ii<<endl;
  system("pause");
  return 0;
}
