//�����Ȼ���ݹ��㷨 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int Num[100],Count=0;

void print(int k)
{
  int i;
  cout<<Num[0]<<"="<<Num[1];
  for(i=2;i<=k;i++)
    cout<<"+"<<Num[i];                 
  cout<<"\n";
  Count++;   
}

void split(int k,int n)
{
  int i;
  if(n<=0) //���޷��ٲ�֣����ӡ 
    print(k);
  else
    for(i=Num[k];i<=n;++i)
      if(i>=Num[k])//�����ֵ�������ǰһ����
      {
        Num[k+1]=i;//��ɹ� 
        split(k+1,n-Num[k+1]);//��������һ�����ĵݹ�           
      }          
}

int main()
{
  freopen("Distribution.in","r",stdin);
  freopen("Distribution.out","w",stdout);
  cin>>Num[0];
  for(int i=1;i<=Num[0]/2;++i)//�Ȳ�ֳ���λ���� 
  {
     Num[1]=i;
     split(1,Num[0]-Num[1]);  
  }
  cout<<Count<<"\n";
  return 0;
}
