//�����������ʮ������ʾ 
#include <iostream>
using namespace std;

int show10(char *c)
{
  int num=0;   
  for(int i=0;i<=31;i++) 
    num=(num<<1)+c[i]; 
  return num;      
}

int main()
{
   int x;
   char c[32];
   for(int i=0;i<=31;i++)//���ַ���ʽ����32λ�Ķ�������
     cin>>c[i]; 
   for(int i=0;i<=31;i++)//�ַ�ת��Ϊ����
     c[i]=c[i]-'0';    
   cout<<show10(c)<<endl;
   system("pause");
   return 0;
}
