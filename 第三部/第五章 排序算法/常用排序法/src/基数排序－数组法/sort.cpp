//�����������鷨 
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <cstring>
#include <iostream>
#define MAXN 100001
using namespace std;
 
int N[10],n; 
int array[MAXN];//������� 
int bucket[10][MAXN];//Ͱ 

int maxbit(int IntMax)//�����λ��
{
  int digit=1;
  while(IntMax>0)
  {
    digit++;
    IntMax/=10;
  }
  return digit-1;
}
   
void RadixSort(int *array,int Exp)//�������� 
{ 
  int Where,m=0; 
  for(int i=0;i<10;i++)//��Ͱ��������� 
    N[i]=0; 
  for(int i=0;i<n;i++) //���������Ͱ
  {  
    Where=array[i]/(int(pow(10,Exp)+0.001))%10;//ȡ�ø�λ��ֵ��ȷ�������ĸ�Ͱ  //����0.001 
    bucket[Where][N[Where]++]=array[i];//���������� 
  }
  for(int i=0;i<10;i++) //˳���ռ�Ͱ�е�����array[] 
    for(int j=0;j<N[i];j++) 
      array[m++]=bucket[i][j];
} 
 
int main() 
{ 
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int IntMax=0,len;
  cin>>n; 
  for(int i=0;i<n;i++) 
  {
    cin>>array[i];
    if(array[i]>IntMax)//�ҳ������ 
      IntMax=array[i];
  }
  len=maxbit(IntMax);//����������λ�� 
  for(int i=0;i<len;++i)//���ζ�ÿһλ���л������� 
    RadixSort(array,i); 
  for(int i=0;i<n;i++)//array[M]��Ԫ��������������С  
    printf("%d ",array[i]); 
  return 0;
}  
