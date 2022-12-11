// �������������
#include <iostream>
#define MAXN 32768 //2^15
using namespace std;
int tree[MAXN];//�����������1��ʼ 

int create(int _tree[],int _node[],int len)
{
  int i,MAX=1;
  _tree[1]=_node[1];
  int level=1;
  for(i=2;i<=len;i++)
  {
    level=1;
    while(_tree[level]!=0)//�жϵ�ǰλ���Ƿ���ֵ 
    {
      if(_node[i]<_tree[level])
        level=level*2;
      else
        level=level*2+1; 
      if(MAX<level)//�ж����һ��Ԫ��ռ������±� 
        MAX=level;                      
    }
    _tree[level]=_node[i];                 
  } 
  return MAX;    
}

int main()
{
  freopen("arraytree.in","r",stdin);
  freopen("arraytree.out","w",stdout);
  int n,num;
  cin>>n;
  int node[n+1];
  for(int i=1;i<=n;i++)
    cin>>node[i];
  num=create(tree,node,n); 
  for(int i=1;i<=num-1;i++)
    cout<<tree[i]<<' ';
  cout<<tree[num]<<endl; 
  return 0;        
}
