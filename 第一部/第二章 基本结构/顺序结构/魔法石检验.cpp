//ħ��ʯ���� 
#include <iostream>
using namespace std;

int main()
{
  int num;//�ȶ������ 
  int hundred,ten,indiv;
  cout<<"������һ����λ��";
  cin>>num;//����һ����λ�� 
  hundred=num/100;//�ֽ��λ�� 
  ten=num/10%10;//�ֽ�ʮλ�� 
  indiv=num%10;//�ֽ��λ�� 
  cout<<"��λ��Ϊ"<<hundred<<endl;//��� 
  cout<<"ʮλ��Ϊ"<<ten<<endl;
  cout<<"��λ��Ϊ"<<indiv<<endl;
  system("pause");
  return 0;
}
