//��������
#include <iostream>
using namespace std;
#define M 1000//����Ѱ�ҷ�Χ 

int main()
{
  int k0,k1,k2,k3,k4,k5,k6,k7,k8,k9;//�������ӣ�������һ��������10�� 
  int i,j,n,s;
  for(j=2;j<=M;j++)//ö��ÿһ���� 
  {
    n=0;//nָ�����ӱ����λ�� 
    s=j;
    for(i=1;i<j;i++)
    {
      if((j%i)==0)
      {
        n++; 
        s=s-i;
        switch(n)//�ж����Ӵ��ںδ� 
        {
          case 1:k0=i;break;
          case 2:k1=i;break;
          case 3:k2=i;break;
          case 4:k3=i;break;
          case 5:k4=i;break;
          case 6:k5=i;break;
          case 7:k6=i;break;
          case 8:k7=i;break;
          case 9:k8=i;break;
          case 10:k9=i;break;
        }
      }  
    }
    if(s==0)//����ȥ�������Ӻ�ǡ��Ϊ0,���������� 
    {
      cout<<j<<"��һ��������,����������:";
      if(n>1)
        cout<<k0<<' '<<k1<<' ';
      if(n>2)
        cout<<k2<<' ';
      if(n>3)
        cout<<k3<<' ';
      if(n>4)
        cout<<k4<<' ';
      if(n>5)
        cout<<k5<<' ';                
      if(n>6)
        cout<<k6<<' ';
      if(n>7)
        cout<<k7<<' '; 
      if(n>8)
        cout<<k8<<' ';
      if(n>9)
        cout<<k9<<' '; 
      cout<<"\n";
    }
  }
  system("pause");
  return 0;
}   
