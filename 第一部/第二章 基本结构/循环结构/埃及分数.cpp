//��������
#include<iostream>
using namespace std;

int main()
{
  long int a,b,c;
  cin>>a>>b;  //�������a�ͷ�ĸb
  while(1)
  {
    if(b%a!=0)//�����Ӳ���������ĸ
      c=b/a+1;//��ֽ��һ����ĸΪb/a+1�İ�������
    else//������������������(��������)
    { 
      c=b/a; 
      a=1;
    }   

    if(a==1)//�������Ѿ�Ϊ1�� 
    {
      cout<<"1/"<<c;
      break;  //�����
    }
    else
      cout<<"1/"<<c<<"+";

    a=a*c-b;  //��������ķ���
    b=b*c;    //��������ķ�ĸ

    if(a==3) //������Ϊ3����������������������3/14=1/7+1/14
    {   
       cout<<"1/"<<b/2<<"+"<<"1/"<<b;
       break;
    }
  } 
  system("pause");
  return 0;
}   
