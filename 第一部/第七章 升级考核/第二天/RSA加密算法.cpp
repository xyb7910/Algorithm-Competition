//RSA�����㷨
#include <iostream>
using namespace std;

int main()
{
 int m,i=2;   
 cin>>m; 
 cout<<m<<"=";   
 while (m!=1)
 {
   while (m%i==0) //��2��ʼ������������������������� 
   {              //���������ܷ���ͬһ���� 
     m=m/i;  
     if(m==1)
      cout<<i;
     else
      cout<<i<<'*'; //˼��Ϊʲô�õ��Ķ��������ӣ�
   }   
   i++;             //�粻���������򽫳�����1���� 
 }
 system("pause");
 return 0;
}
