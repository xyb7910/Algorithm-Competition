//�򵥸߾��ȼ���
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXN 5001
using namespace std;

void sub(int x[],int y[],int len,int on)//on���Ƿ���������Ŀ��� 
{ 
  for(int i=0;i<len;i++) //�������� 
  {
     x[i]-=y[i];//�˳����ǽ�������Ǳ��������е�x[]����
     if(x[i]<0)
     {
       --x[i+1];//��λ 
       x[i]+=10;
     }
     if(x[len-1]==0) 
       --len;
   }
   for(int i=len-1;i>=0;--i)//����ǰλ����Ϊ0,����ȥ 
   {
     if(x[i]==0) 
       len--;
     if(x[i]!=0)
        break;
   }
   if (on==1) 
     x[len-1]=-x[len-1];//����Ϊ����,����ǰһλ��Ϊ���� 

   for(int i=len-1;i>=0;--i)  //������ 
     cout<<x[i];
   cout<<"\n";
}

void init(int x[],char temp[],int len)//�ַ�����ת��Ϊ�������� 
{
  for(int i=0;i<len;i++)
    x[i]=temp[len-1-i]-48;//����ת�� 
}

int main()
{
  freopen("sub.in","r",stdin);//ʹ���ļ��ض�����ͷ�ļ������stdio.h,stdlib.h 
  freopen("sub.out","w",stdout);//����linux�����¿��ܻ���벻ͨ�� 
  char str1[MAXN],str2[MAXN];
  int la,lb,k,a[MAXN]={0},b[MAXN]={0};
  cin>>str1>>str2;
  la=strlen(str1);
  lb=strlen(str2);
  init(a,str1,la);//��ʼ�� 
  init(b,str2,lb);

  if(la>lb)//���a��λ����b��λ���� 
    sub(a,b,la,0);//�����a-b��ֵ,0��ʾ���Ϊ��ֵ 
  else if(la<lb) 
    sub(b,a,lb,1);//�������b-a��ֵ��1��ʾ���Ϊ��ֵ 
  else //���������λ����ͬ 
  {
    k=strcmp(str1,str2);//�Ƚ����ַ������С 
    if(k==0)
      cout<<"0\n";
    else if(k>0)
      sub(a,b,la,0);
    else
      sub(b,a,lb,1);   
  } 
  return 0;
}  
