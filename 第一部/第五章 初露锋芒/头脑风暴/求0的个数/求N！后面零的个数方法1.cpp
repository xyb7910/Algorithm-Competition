//��N��������ĸ���������1
#include <iostream>
using namespace std;

int i,ii,n;
long sum;

int main()
{
  ii=0;
  sum=1;
  cin>>n;
  for(i=1; i<=n; i++)
  {
    sum=sum*i;
    while(sum%10==0)//��������0����ȥ��0������
    {
      sum=sum/10;
      ii=ii+1;
    }
    sum=sum%1000;//������λ������
  }
  cout<<ii<<endl;
  return 0;
}
