//��ħ����
#include <iostream>
using namespace std;

int main()
{
  int sum=0,n;
  while(true)//��ʾ��ԶΪ�棬����Զѭ����Ҳ������while(1) 
  {
    cout<<"����һ��������0��ʾ������";
    cin>>n;
    if(n==0)
      break;//�����ò�ѭ�� 
    sum+=n;         
  }
  cout<<"�ܺ�Ϊ��"<<sum<<endl;
  system("pause");
  return 0;
}
