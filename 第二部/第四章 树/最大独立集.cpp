//�������� 
#include <bits/stdc++.h>
using namespace std;

int Dp[6010][2];//״̬

vector<int>Edg[6010];

void MIS(int x,int fa)
{
  Dp[x][1]=1;
  for(int i=0; i<Edg[x].size(); i++) //ö�ٶ���
  {
    int v=Edg[x][i];
    if(v==fa)//������ӵ��ڸ���
      continue;//����
    MIS(v,x);//�ݹ�����²�ڵ�
    Dp[x][1]+=Dp[v][0];
    Dp[x][0]+=max(Dp[v][0],Dp[v][1]);
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<n; i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);//�����Զ���ĸ��׺Ͷ��ӽ��
    Edg[x].push_back(y);
    Edg[y].push_back(x);//��������
  }
  MIS(1,0);//�ѽ��1���ɸ�������Ϊ0
  printf("%d\n",max(Dp[1][0],Dp[1][1]));
}
