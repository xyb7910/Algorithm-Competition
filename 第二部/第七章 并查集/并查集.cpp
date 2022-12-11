//���鼯
#include <bits/stdc++.h>
using namespace std;

int father[20001];

int find(int x) //�ж�x�����ļ���
{
  int root=x;
  while(father[root]>=0)//�ҵ����յĸ����
    root=father[root];
  while(root!=x) //ѹ��·��
  {
    int temp=father[x];
    father[x]=root;
    x=temp;
  }
  return root;
}

void Union(int a,int b) //�ϲ�������ͬ���ϵ�Ԫ��
{
  if(father[a]>father[b])
    father[a]=b;
  else
    father[b]=a;
}

int main()
{
  int N,M,Q,a,b;
  cin>>N>>M>>Q;
  for(int i=1; i<=N; i++) //��ʼ��
    father[i]=-1; //�����ĸ�����Ϊ-1
  for(int i=1; i<=M; i++)
  {
    cin>>a>>b;
    if(find(a)!=find(b))
      Union(a,b);//��ͨ
  }
  for(int i=1; i<=Q; i++)
  {
    cin>>a>>b;
    find(a)==find(b)?cout<<"YES"<<'\n':cout<<"NO"<<'\n';
  }
  return 0;
}

