//�߾��ȷ����Ż��㷨 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAXN 100

int Delay(int x)//�����ӳ�����λ�� 
{
  int n2=0,n5=0,Max;
  while(x%2==0)  
  {
    n2++;
    x/=2;
  }
  while(x%5==0)  
  {
    n5++;
    x/=5;
  }
  return n2>n5?n2:n5;
}

int Gcd(int a, int b)//ŷ����µ��������Լ�� 
{ 
  while(b != 0) 
  { 
    int r = b; 
    b = a % b; 
    a = r; 
  } 
  return a; 
}

int Repetend(int x)//����ѭ����λ�� 
{
  int digit,k=9;  
  while(x%2==0)//�������г�ȥ����2��5  
    x/=2;
  while(x%5==0)  
    x/=5;
  for(digit=1;digit<=MAXN;++digit)//������С��kֵ������10^k-1��x���� 
  {
    if(k%x==0)
      break;
    k=k%x*10+9;         
  }      
  return digit;
}

void compute(int m,int n,int delay,int repetend)
{
  int digit=delay+repetend;   
  for(int i=1;i<=digit;++i)    
  {
     m*=10;              //��������10λ
     cout<<m/n;    
     m%=n;               //����һ������
     if(m==0)            //����Ϊ0,��Ϊ����С��
        return;               //�˳�ѭ��
   }
   cout<<'\n';
   cout<<"����ѭ��С��"<<"��С�����"<<digit<<"λ";
   cout<<'\n';
}

int main()
{
  freopen("fraction.in","r",stdin);
  freopen("fraction.out","w",stdout);
  int m,n,digit,j,gcd;
  cin>>m;
  cin.ignore(1,'/');//����'/'�ַ�
  cin>>n;
  cout<<m<<'/'<<n<<"=0.";
  gcd=Gcd(m,n);//�����Լ�� 
  m/=gcd;
  n/=gcd;
  compute(m,n,Delay(n),Repetend(n));
  return 0;
}
