//ȫ�����㷨-�����ֵ��� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool used[100];//���ĳ�������Ƿ�ʹ�ù� 
int a[100],Count,N;

void print()
{
  for(int k=1;k<N+1;k++)
    cout<<a[k];
  cout<<"\n";     
  Count++;
}

void dfs(int i)
{
  if(i>N)//�ݹ��������ӡ��� 
    print();
  else  
    for(int k=1;k<=N;k++)
      if(used[k]==0) 
      {
        used[k]=1;//����ʹ�ù��ı�� 
        a[i]=k;//��ֵ 
        dfs(i+1);
        used[k]=0;//��ԭΪδʹ�� 
      }
}

int main()
{
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout); 
  int j;
  cin>>N;
  dfs(1);
  cout<<Count<<endl;
  return 0;
}
