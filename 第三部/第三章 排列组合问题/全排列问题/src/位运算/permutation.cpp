//ȫ����λ���� 
#include<iostream>
using namespace std;
int N,a[33],full,bitmod[39],amount;

void print()
{
  for(int i=1;i<N;++i)
    cout<<a[i];
  cout<<a[N]<<'\n';
}

void dfs(int dep,int layout)
{
  if(layout==full)//�������ֵ����ȡ�ߣ������һ������ 
  {
    print();
    ++amount;
  }
  else
  {
    int p,CanPut=(~layout)&full;//��õ�ǰ��ȡ���� 
    while(CanPut)
    {
      p=CanPut&(-CanPut);//�ҵ����ұ�Ϊ1���� 
      CanPut-=p;//������ȡ�� 
      a[dep]=bitmod[p%37];//��������ӵ�λ�� 
      dfs(dep+1,layout+p);
    }
  }
}

int main()
{
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout);     
  cin>>N;
  for(int i=0;i<N;++i)
    bitmod[(1<<i) % 37]= i+1;//������ϣ�� 
  full=(1<<N)-1;//��ʼΪ111111...111111����ʾ����������ȡ�� 
  dfs(1,0);
  cout<<amount<<'\n';
  return 0;
}
