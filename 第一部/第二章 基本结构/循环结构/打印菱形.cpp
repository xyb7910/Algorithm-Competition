//��ӡ����
#include <iostream>
using namespace std;

int main()
{
  for(int i=-3;i<=3;i++)//�������
  {
    int k=abs(i);      
    for(int j=1;j<=k;j++)//�������ÿ�пո���
     cout<<' ';
    for(int j=1;j<=7-2*k;j++)//�������ÿ��*����
      cout<<'*';
    cout<<endl;                    
  }
  system("pause");
  return 0;
}
