//ȫ�ֱ�����ֲ�����
# include <iostream>
using namespace std;

int num1=5;//ȫ�ֱ��������к�������ʹ����

int fun1()
{
  int a=0;//�ֲ�����,ֻ���ڱ�������ʹ��  
  num1++;
}

int num2=4;//ȫ�ֱ���,���Ա������fun2������main����ʹ�� 
int fun2()
{
   num2++; 
}

int main()
{
  int sum=5;//�ֲ�������ֻ��main��������Ч
  fun1();
  fun2();
  sum+=num1+num2;
  cout<<sum<<endl;
  system("pause");
  return 0;
}
