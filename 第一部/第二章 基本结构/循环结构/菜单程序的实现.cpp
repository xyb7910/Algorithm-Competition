//�˵������ʵ�� 
#include <iostream>
using namespace std;

int main()
{
   int c;
   int a,b;
   do
   {
     system("cls");//����  
     cout<<"Сѧ��������ϰϵͳ\n";
     cout<<"   1.�ӷ�\n"; 
     cout<<"   2.����\n";
     cout<<"   3.�˷�\n";
     cout<<"   4.����\n";
     cout<<"   5.�˳�\n";
     cout<<"��ѡ�� (1~5):  ";
     cin>>c;
     if(c!=5)
     {
        cout<<"���������������Կո���"; 
        cin>>a>>b;
        switch(c)
        {
           case 1:cout<<a<<"+"<<b<<"="<<a+b<<endl;break;
           case 2:cout<<a<<"-"<<b<<"="<<a-b<<endl;break;
           case 3:cout<<a<<"*"<<b<<"="<<a*b<<endl;break;
           case 4:if(b!=0) 
                    cout<<a<<"/"<<b<<"="<<a/b<<endl;
                  else
                    cout<<"��������Ϊ0��";
                  break;  
           default:cout<<"��������룬������ѡ��\n"<<endl;                                       
        }    
        system("pause");
     }
     else
     {
       cout<<"��ϰ����!\n";
       break;
     }
   }while(1);
   system("pause");
   return 0;  
}
