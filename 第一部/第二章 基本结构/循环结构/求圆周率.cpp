//��Բ����
# include <iostream>
# include <math.h>
using namespace std;

int main()
{
  int s=1;
  float n=1.0,t=1,pi=0;
  while(fabs(t)>1e-6)  //1e-6��C�����е�ָ�������ʽ
  {
    pi=pi+t;
    n=n+2; //��ĸ��2
    s=-s;  //�ı�Ӽ���
    t=s/n;  
  }
  pi=pi*4;
  cout<<pi<<endl;
  system("pause");
  return 0;
  
}
