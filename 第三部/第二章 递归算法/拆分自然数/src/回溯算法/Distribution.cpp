//��Ȼ�����-�����㷨 
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int Num[100],total=0,N ;

void print(int k)
{
  int i;
  cout<<N<<"="<<Num[1];
  for(i=2;i<=k;i++)
    cout<<"+"<<Num[i];                 
  cout<<"\n";
  total++;   
}

void split(int n,int digit)//n����Ҫ��ֵ�����m��ʾ��ֵ�λ�� 
{
  int remainder;    
  for(int i=1;i<=n;i++)//��1��ʼ���Բ��   
    if(i>=Num[digit-1])//��ֵ������ڻ����ǰһ��
    {
      Num[digit]=i ;// ���������������          
      remainder=n-i ;// ʣ�µ�����n-i
      if(remainder==0 && digit>1)//��ʣ����Ϊ0���ܲ�ָ�������1�����ӡ��� 
        print(digit);
      else
        split(remainder,digit+1);// ����ʣ�µ����������в��
      Num[digit]=0;//ȡ�����ν�����ָ���ʼֵ��������һ�β�ּ�����
    }
}
 
int main()
{
  freopen("Distribution.in","r",stdin);
  freopen("Distribution.out","w",stdout);

  cin>>N;
  split(N,1);//�ӵ�1λ����ʼ��� 
  cout<<total<<endl;
  return 0;
}
