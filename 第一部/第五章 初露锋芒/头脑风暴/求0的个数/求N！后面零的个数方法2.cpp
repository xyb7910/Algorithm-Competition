//��N��������ĸ���������2��N/5��ѭ��
#include <iostream>
using namespace std;

int main()
{
  int i,ii,j,n;
  j=5;ii=0;
  cin>>n;
  while(j<=n)
  {
    i=j;
    while(i%5==0)//�ж�������5�����ж��ٸ�0 
    {
      i=i/5;
      ii=ii+1;
    }
    j=j+5;
  }
  cout<<ii<<endl;
  system("pause");
  return 0;
}
