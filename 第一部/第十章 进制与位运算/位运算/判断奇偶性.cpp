//�ж���ż��
#include <iostream>
using namespace std;

int main()
{
  int x;
  cin>>x;
  if((x&1)==0)//ע��λ��������ȼ��ܵͣ����Ա�������� 
    cout<<x<<"��ż��"<<endl;
  else
    cout<<x<<"������"<<endl;  
  system("pause");
}
