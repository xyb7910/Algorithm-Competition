//��תδ�� 
#include<iostream>
#include <cstdlib>
using namespace std;
const int MAX_N = 208;

struct  Tree
{ int lastSon;//���һ������ 
  int left;//����(�� 
  int right;//�ֵܣ��ң� 
  int value;//Ȩ��
}tree[MAX_N];

int idx,N,M;
int dp[MAX_N][MAX_N];

inline int MAX(int a,int b)
{ 
  return a>b?a:b;
}

void Init()
{ 
  int i,j; 
  for(i=0;i<=N;i++) //��ʼ��
  {  
    tree[i].lastSon=-1;  
    tree[i].right=-1;  
    tree[i].left=-1;  
    tree[i].value=0;  
    for(j=0;j<=N;j++)     
      dp[i][j]=-1;  
  }
}

void BuildTree(int son,int parent)//���� 
{ 
  if(tree[parent].lastSon==-1)//���� 
  {  
    tree[parent].left=son; 
  } 
  else //���ֵ�
  {  
    tree[tree[parent].lastSon].right=son; 
  } 
  tree[parent].lastSon=son;
}

bool Read()//�������� 
{ 
  int p,i; 
  if(scanf("%d%d",&N,&M)&&!N&&!M) 
    return false; 
 
  Init(); 
  for(M++,i=1;i<=N;i++)
  {  
    scanf("%d%d",&p,&tree[i].value);  
    BuildTree(i,p); 
  } 
  return true;
}

int DP(int node,int k)
{ 
  if(node==-1||k==0) //���node����k==0
  {  
    return 0; 
  } 
  if(dp[node][k]!=-1)//����Ѿ����ֵ��  
  { 
    return dp[node][k];//��ֱ�ӷ��� 
  } 
  int i,tmp; 
  dp[node][k]=DP(tree[node].right,k); 
  for(i=1;i<=k;i++) 
  {  
    tmp=DP(tree[node].left,i-1)+tree[node].value+DP(tree[node].right,k-i);  
    dp[node][k]=MAX(dp[node][k],tmp); 
  } 
  return dp[node][k];
}

int main()
{ 
  freopen("reverse.in","r",stdin);
  freopen("reverse.ans","w",stdout);  
  while(Read())
  {  
    DP(0,M); 
    printf("%d\n",dp[0][M]);
  }
  return 0;
}
