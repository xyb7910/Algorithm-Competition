/*
�������ƣ�N�ʺ��������ͨ�����㷨 
����˵����
�������ߣ�ZXH (2010-9-11)
����ע��
*/ 
#include <iostream>
#include <math.h>
using namespace std;
int i,j,k,n,number;
int x[20+1];//��Żʺ�λ��,�����1��ʼ 

int Try(int k)//�жϸ�λ���Ƿ�ɰ��ûʺ� 
{
  int i;
  for(i=1;i<=k-1;i++)
    if((x[i]==x[k])||(abs(x[i]-x[k])==abs(i-k)))
      return 0;
  return 1;
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  k=1;
  x[k]=0;
  cin>>n;
  while(k>0)
  {
    x[k]=x[k]+1;
    while((x[k]<=n)&&(!Try(k)))//ֱ���Ե�һ�����ʵ�λ�� 
      x[k]=x[k]+1;
    if(x[k]>n)//����Թ���n�ķ�Χ 
      k=k-1;//���ݵ�ǰһ�� 
    else
      if(k==n)//������ú����һ�лʺ� 
        number++;//print();//��ӡ��� 
      else
      {
        k=k+1;//����������һ�лʺ� 
        x[k]=0;
      }
  }
  cout<<number<<endl;
}

