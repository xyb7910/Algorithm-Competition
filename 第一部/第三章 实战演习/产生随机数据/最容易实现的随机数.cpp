//������ʵ�ֵ������ 
#include <iostream>
#include <stdlib.h>//C�����г��õ�ͷ�ļ��������˳��õ�ϵͳ����
#include <time.h>//����ʹ��time���ͷ�ļ�
using namespace std;

int main()
{
 int i,j;
 int t=time(0)%10;//��ʱ����Ϊ�������

 cout<<"     *** Ȥζҡ���� ***  \n\n";
 cout<<"����ѡһ������(0-9):  ";

 cin>>j;

 if(j<0 || j>9)
    return 0;
   
 if(j==t)
   cout<<"\n��,�صȽ�!��������!";
 else if(abs(j-t)<=1)
   cout<<"\nһ�Ƚ�!�ܲ���ѽ!";
 else if(abs(j-t)<=2)
   cout<<"\n���Ƚ�!Ҳ������...";
 else if(abs(j-t)<=3)
   cout<<"\n���Ƚ�!��ҪŬ��Ŷ...";
 else
   cout<<"\n���ϧ!ʲô��û��..."; 
 system("pause");
 return 0;   
}
