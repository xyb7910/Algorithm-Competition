//�����������
#include <iostream>
#include <math.h>//����ƽ����������Ҫ��ѧ��ͷ�ļ�
using namespace std;

int main()
{
  float a,b,c,p,area;
  cin>>a>>b>>c;
  p=1/2*(a+b+c);
  area=sqrt(p*(p-a)*(p-b)*(p-c));//sqrtΪ��ƽ��������
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  cout<<"c="<<c<<endl;
  cout<<"p="<<p<<endl;
  cout<<"area="<<area<<endl;
  system("pause"); 
}
