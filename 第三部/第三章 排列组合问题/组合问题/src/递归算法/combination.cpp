//�������ݹ��㷨 
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
using namespace std;
int buff[21];     //����ϵ�����,�ӣ���ʼ
int M,N;

void print()
{
  for( int i=1;i<=N;i++)
    cout<<buff[i];
  cout<<"\n";      
}

void combin(int M,int N)
{ 
  if(N==0)  //�ݹ�������� 
    print();
  else
    for(int i=M;i>=N;i--)//����ֵ,��������������Խ��ԽС 
    {
      buff[N]=i;
      combin(i-1,N-1);
    }
}

main()
{    
  //freopen("combination.in","r",stdin);
  //freopen("combination.out","w",stdout);   
  cin>>M>>N;//����M��Ԫ����ѡ��N��Ԫ��
  combin(M,N);
  return 0;
}
