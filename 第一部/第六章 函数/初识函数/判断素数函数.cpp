//�ж���������
#include <iostream>
using namespace std;
void prime(int number);//���Ӻ���������

int main()
{
  int num;  
  cin>>num;
  prime(num);
}

void prime(int number)  //���践��ֵʱ������ǰ�����void
{
  int n,flag=1;//flagΪ�Ƿ������ı��
  for(n=2;n<number/2;n++)
    if(number%n==0)
      flag=0;
  if(flag)  //���flagΪ��
     cout<<number<<"��һ������"<<endl;     
  else
     cout<<number<<"����һ������"<<endl;
  system("pause");
  return 0;
}
