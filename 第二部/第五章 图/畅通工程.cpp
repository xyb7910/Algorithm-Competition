//��ͨ����
#include <bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
int Line[10010], dis[205], w[205][205], b[205][205];
bool vis[205];
int n,m,s,t;

void spfa(int s)
{
  for(int i=0; i<=n; i++)
    dis[i]=MAX;
  dis[s]=0;//���еĳ�ʼ״̬,sΪ���
  vis[s]=1;
  Line[1]=s;
  int v, head=0, tail=1;
  while (head<tail) //���в�Ϊ��ʱ
  {
    v=Line[++head];//ȡ����Ԫ��
    vis[v]=0;//�ͷŽ�㣬����
    for(int i=1; i<=b[v][0]; i++)
      if (dis[b[v][i]] > dis[v]+w[v][b[v][i]])
      {
        dis[b[v][i]] = dis[v]+w[v][b[v][i]];//�޸����·
        if (vis[b[v][i]]==0) //��չ������
        {
          Line[++tail]=b[v][i];
          vis[b[v][i]]=1;
        }
      }
  }
}

int main()
{
  cin>>n>>m;
  int x,y,z;
  for(int i=0; i<m; i++)
  {
    cin>>x>>y>>z;
    if (w[x][y]!=0 && z>w[x][y])//�������������С��һ��·
      continue;
    b[x][++b[x][0]]=y;//b[x,0]��ʾ��xΪһ�����ı���
    b[y][++b[y][0]]=x;
    w[x][y]=w[y][x]=z;
  }
  cin>>s>>t;
  spfa(s);
  dis[t]==MAX?printf("-1\n"):printf("%d\n",dis[t]);
  return 0;
}


