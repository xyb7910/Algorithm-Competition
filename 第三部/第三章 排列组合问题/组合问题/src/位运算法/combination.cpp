//�������-λ���� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int next_combination(int combin,int n)//����ǰһ���ö����һ���
{
  int next;//��һ����� 
  int first1 = combin & -combin;//�ҵ������һ������1��λ��
  int t=(combin+first1);//��first1��λ���ϼ�1 
  next=(((t^combin)>>2)/first1) | t;
  if ((1 << n) < next)//���Խ�磬���˳� 
    return 0;
  return next;
}

int main()
{
  freopen("combination.in","r",stdin);
  freopen("combination.out","w",stdout);  
  int M,N;
  cin>>M>>N;
  if(N==0)
  { cout<<endl;
    exit(0);
  }
  int combin=(1<<N)-1; //��ʼ��Ϊ10000...000-1=1111...1111����N��1 
  do
  {
    for (int i = 0; i<M; ++i)// ������
      if ((combin & (1 << i))>0)//�����iλΪ1,���ʾ������е�i���� 
        cout<<i+1;//��Ϊ�±��0��ʼ���������i+1 
    cout<<endl;
  }while(combin=next_combination(combin,M));
  return 0;
}
