//��������
#include<iostream>
#define MAXN 1001
using namespace std;

int n,m;/*nΪ�ڵ���,mΪ����*/
int top;/*ջ��ָ��*/
int mark[MAXN],ind[MAXN],stack[MAXN];
/*mark�ڵ��������,indΪ�ڵ�������,stackΪһ��ջ*/
bool w[MAXN][MAXN];/*�ڽӱ�*/

void sort()
{
  int i,u,t;
  top = -1;
  /*�����Ϊ0�Ľڵ���ջ�����������*/
  for(i = 1 ; i <= m ; i ++)
    if(ind[i] == 0 )
    {
	  mark[i] = 1;
	  stack[++top] = i;
	  ind[i] = -1;
    }

  /*��DFS�ķ�ʽ��ǽڵ��������*/
  do{
    /*ȡ��ջ�е�һ���ڵ㲢������ýڵ����ڵĽڵ����ȼ�1*/
    u = stack[top--];
    for(i=1;i<=n;i++)
      if(w[u][i] and ind[i] not_eq -1)
	ind[i]--;

    /*���ҵ�ǰ�Ƿ������Ϊ0��û����ջ�Ľڵ㲢������ջ*/
    for(i=1;i<=n;i++)
      if(ind[i] == 0)
  	  {
	    mark[i] = mark[u] + 1;
	    stack[++top] = i;
	    ind[i] = -1;
	  }
  }while(top >= 0);

  for(i=1;i<=n;i++)
    cout<<mark[i]<<" ";
  cout<<"\n";
  return ;
}

int main()
{
  int i,u,v;
  cin>>n>>m;//����һ�������������ͼ�Ľڵ����ͱ���n,m

  for(i=1;i<=m;i++)
  {
    cin>>u>>v;
    w[u][v] = true;
    ind[v]++;
  }
  sort();
  return 0;
}
