/*
�������ƣ��߾��ȷ���
����˵��������һ������(m/n)(<0<m<n<=100):")
�������ߣ�ZXH (2010-3-30)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 
#include<iostream>
using namespace std;
int Remainder[101];// remainder:��ų�����������
int quotient[101]; // quotient:���δ���̵�ÿһλ
int main()
{
  freopen("fraction.in","r",stdin);
  freopen("fraction.out","w",stdout);
  int m,n,i,j;
  scanf("%d/%d",&m,&n);      /*���뱻�����ͳ���*/
  cout<<m<<'/'<<n<<"=0.";
  for(i=1;i<=100;i++)             /*i: �̵�λ��*/
  {
     Remainder[m]=i;       /*m:��������remainder[m]:��������Ӧ���̵�λ��*/
     m*=10;                /*��������10λ*/
     quotient[i]=m/n;      /*��*/
     m=m%n;                /*������*/
     if(m==0)              /*����Ϊ0 ���ʾ������С��*/
     {
        for(j=1;j<=1;j++) 
          cout<<quotient[j];  /*�����*/
        break;             /*�˳�ѭ��*/
     }
     if(Remainder[m]!=0)     /*����������Ӧ��λ��ǰ���Ѿ����ֹ�*/
     {
        for(j=1;j<=i;j++)
          cout<<quotient[j];  /*�����ѭ��С��*/
        cout<<endl;
        cout<<"����ѭ��С��"<<"��С�����"<<Remainder[m]<<"λ��"<<i<<"λ";
        cout<<endl;
        break;  
     }
   }
}

