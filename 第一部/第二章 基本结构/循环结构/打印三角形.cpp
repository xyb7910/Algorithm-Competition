//��ӡ������
#include <iostream>
using namespace std;

int main()
{
  for(int i=1;i<=4;i++)//������� 
  {
    for(int j=1;j<=4-i;j++)//����ÿ������Ŀո��� 
      cout<<' ';
    for(int j=1;j<=2*i-1;j++)//����ÿ�������*�ĸ��� 
      cout<<'*';
    cout<<endl;                    
  }
  system("pause");
  return 0;
}
