//��������-�ݹ�ⷨ 
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXN 40

int W[MAXN];//����Ʒ����

int knapsack(int s,int n)//sΪʣ��������nΪʣ���ѡ��Ʒ��
{
  if(s==0)// �������װ�� 
    return 1;
  if(s<0||(s> 0 && n<1))//��s<0��n<1�������
    return 0;
  if(knapsack(s-W[n],n-1))//�Ӻ���ǰװ��װ��W[n]����ʣ����Ʒ���н�
  {
    cout<<W[n]<<" ";//��װ����n�����������
    return 1;
  }
  return knapsack(s,n-1);//��װ�˵�n�����󣬵����޽⣬��ɾ���ð������Ե�n-1��
}

int main()
{
  freopen("Backpack.in","r",stdin);
  freopen("Backpack.out","w",stdout);    
  int S,N;  
  cin>>S>>N; 
  for(int i=1;i<=N;++i)
    cin>>W[i]; 
  if(knapsack(S,N))
    cout<<"\n";
  else 
    cout<<"Failed!\n";
  return 0;
}
