//����������
#include <bits/stdc++.h>
using namespace std;
#define MAXN 90000

struct img
{
  int x;
  int y;
} a[MAXN];

int main()
{
  freopen("area.in","r",stdin);
  freopen("area.out","w",stdout);
  char temp;
  int dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0}; //��������ƫ������
  int m,n,xing=0,ttxx,ttyy;
  cin>>m>>n;
  bool pos[n+2][m+2];
  memset(pos,0,sizeof(pos));

  for(int i=1; i<=n; ++i) //����ͼ��
    for(int j=1; j<=m; ++j)
    {
      cin>>temp;
      if(temp=='*')//ͳ��*������
      {
        pos[i][j]=1;
        xing++;
      }
      if(temp=='0')
        pos[i][j]=0;
    }
  for(int i=1; i<=n+1; ++i)//���߿�Χ����
    pos[i][m+1]=1,pos[i][0]=1;
  for(int i=1; i<=m+1; ++i)
    pos[n+1][i]=1,pos[0][i]=1;

  int sum=1,front,rear;
  int tt=1;
  int kk=1;
  a[1].x=1;
  a[1].y=1;
  pos[1][1]=1;

  while(tt<=kk)//�����в�Ϊ��ʱ,�����������
  {
    for(int i=0; i<=3; ++i) //�����������һ��
    {
      front=tt%MAXN;
      ttxx=a[front].x+dx[i];
      ttyy=a[front].y+dy[i];
      if(pos[ttyy][ttxx]==0)
      {
        kk++;
        rear=kk%MAXN;
        a[rear].x=ttxx;
        a[rear].y=ttyy;
        sum++;
        pos[ttyy][ttxx]=1;
      }
    }
    tt++;
  }
  cout<<m*n-sum-xing<<endl;
  return 0;
}

