//���������Σ�λ���� 
#include <stdio.h>			
#include <stdlib.h>		
#define maxn 50             //���ʵ�ʲ�����31����������

int a[maxn][maxn],N,total,Max,b;
 
void f()					
{							
  int i,j,t=1<<(N-1),s=0; //t����ȡֵ��sΪ�ܺ�
  for (i=j=0;i<N;i++)     //i,j�ֱ��ʾ�С��� 
  {						
    if (b&t) //�����ǰλΪ1������
      j++;       
    s+=a[i][j];			//���� 
    t>>=1;				//1������һλ�Ƚ� 
  }						
  if (s>Max)
    Max=s;       //�ҳ����ֵ 
}							

int main()
{
  FILE *in =fopen("tower.in","r");
  FILE *out =fopen("tower.out","w");
  int i,j,all;
  fscanf(in,"%d",&N); 	
  all=1<<(N-1);           //���ܵ���Ŀ 
  for (i=0;i<N;i++)       //���루��0��ʼ�� 
    for (j=0;j<=i;j++) 
      fscanf(in,"%d",&a[i][j]);  
  for (b=0;b<all;b++)     //������п��� 
    f();                //���㵱ǰ�����С 
  fprintf(out,"%d\n",Max);   
  return 0; 				
}							
