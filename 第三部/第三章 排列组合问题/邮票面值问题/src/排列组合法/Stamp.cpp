//��Ʊ��ֵ���⣭������Ϸ� 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int buff[40],num[40];         /*���������ϵ�����*/
int link[200];    /*��ſ�������ϳɵ�ֵ��1�����У�0������*/
int Max=0;              /*��ʾ�������ֵ*/
int answer[40];       /*��ʾ���յ���Ʊ��ֵ*/
int N,KK,sum=0;

void sort(int k)/*��Ҫ�����������������*/
{  int t,j,i;
   for(j=0;j<k-1;j++)  
     for(i=0;i<k-j-1;i++)
      if(answer[i]>answer[i+1])
         {t=answer[i];answer[i]=answer[i+1];answer[i+1]=t;}
}
void print()
{  int i;
   for(i=0;i<KK;i++)
     printf("%d ",answer[i]);
   printf("%d\n",Max);  /*�˴�������*/
}

void finish()/*�Ƚϳ���������ֵ�����������Ʊֵ*/
{ int i;
  for(i=1;link[i]!=0;i++)
   {   } 
   if(Max<i-1)
   {
      Max=i-1;   
      for(int j=0;j<KK;j++)
        answer[j]=buff[j];
   }    
   for(i=0;i<200;i++)
      link[i]=0;
      
}

void writelink(int n,int m)/*nΪ��Ʊ������ mΪ��Ʊ����������*/
{  int i;                        /*�����п���ȡ�õ�ֵ����������*/
   if(n<0||m==0)
   { 
     sum=0;
     for(int u=0;u<KK;u++)  
        sum=sum+num[u+1]*buff[u];
     if(sum<200 && link[sum]!=1)   /*��ֹSUMֵ���󣬳������鷶Χ���ƻ���������*/
      link[sum]=1;
     
     return;
    } 
   for(i=n;i>=0;i--)  /*�ݹ��г���������*/
   {
       num[m]=i;
       writelink(n-i,m-1);      
   }    
}

void comb(int m,int k)/*��2��ʼ�ݹ����������*/
{ if(m>55||k==0)
  {  buff[0]=1;
     writelink(N,KK);
     finish();
     return;
  } 
  for( int i=m; i<= 55; i++)/*�ݹ�����������*/
  {
     buff[k] =i;
     comb(i+1,k-1);
  }
}

main()
{  
  freopen("Stamp.in","r",stdin);
  freopen("Stamp.out","w",stdout);
  scanf("%d %d",&N,&KK);
 
  comb(2,KK-1);
  sort(KK);
  print();
}
