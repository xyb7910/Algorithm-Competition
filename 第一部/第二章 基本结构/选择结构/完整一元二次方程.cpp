//��һԪ���η���
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  float a,b,c,disc,x1,x2,realpart,imagpart;
  cin>>a>>b>>c;
  if(fabs(a)<=1e-6)
    cout<<"����һ���Ϸ���һԪ���η���"<<endl;
  else
  {
    disc=b*b-4*a*c;
    if(fabs(disc)<=1e-6)
      cout<<"��������ȵ�ʵ����"<<-b/(2*a)<<endl;
    else if(disc>1e-6)
    {
      x1=(-b+sqrt(disc))/(2*a);
      x2=(-b-sqrt(disc))/(2*a);
      cout<<"��������ͬ��ʵ����"<<x1<<' '<<x2;
    }
    else
    {
      realpart=-b/(2*a);
      imagpart=sqrt(-disc)/(2*a);
      cout<<"���������:"<<realpart<<'+'<<imagpart<<"i, "<<realpart<<'-'<<imagpart<<"i\n";
    }
  }
  system("pause");
  return 0;
} 
