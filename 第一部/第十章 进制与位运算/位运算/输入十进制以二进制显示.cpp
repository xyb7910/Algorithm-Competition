//����ʮ�����Զ�������ʾ 
#include <iostream>
using namespace std;

int main()
{
  int m,number,s[32];  
  cin>>number;
  for(int i=1;i<=32;i++)  //32λ�ı����� 
    s[i-1]=number>>(i-1)&1;//��ÿһλ�Ƶ����Ҷ���1���������� 
  for(int i=31;i>=0;i--)
    cout<<s[i]<<' ';
  system("pause");
}
