//�����㷨��߾��Ƚ׳�
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
  FILE *in=fopen("factorial.in","r");
  FILE *out=fopen("factorial.out","w");
  int data[50001]={0};
  int digit=1;//λ��
  int i,j,n;
  data[1]=1;
  fscanf(in,"%d",&n);
  for(i=1;i<n+1;i++)
  {
    for(j=1;j<digit+1;j++)//�׳����� 
      data[j]*=i;
    for(j=1;j<digit+1;j++)
       if(data[j]>=10)  //��ĳλ��>=10ʱ������������
         for(int r=1;r<digit+1;r++)
         {
           if(data[digit]>=10)//λ������1 
             digit++;
           data[r+1]+=data[r]/10;
           data[r]=data[r]%10;
         }
  }
  fprintf(out,"%d!=",i-1); //��ӡ���
  for(int k=digit;k>0;k--)
    fprintf(out,"%d",data[k]);
  fprintf(out,"\n");
  fclose(in);
  fclose(out);
  return 0;  
}
