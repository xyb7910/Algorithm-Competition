#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define bign 105

bool road[bign][bign];
int map[bign][bign];

int n,m;

void in()
{
  memset(road,0,sizeof(road));
  memset(map,0,sizeof(map));
  cin>>m>>n;
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      cin>>road[i][j];
    }
  }
}

int dfs(int y,int x,int last)
{
  map[y][x]=last;
  if(y==m&&x==n)
  {
    return 1;
  }
  else
  {


    if(y+1<=m&&map[y+1][x]==0&&road[y+1][x]==0)//////////////////////1
    {
      int jud1=dfs(y+1,x,2);
      if(jud1==1)return 1;
    }
    if(y+1<=m&&x+1<=n&&map[y+1][x+1]==0&&road[y+1][x+1]==0)///////////////2
    {
      int jud=dfs(y+1,x+1,1);
      if(jud==1)return 1;
    }
    if(x+1<=n&&map[y][x+1]==0&&road[y][x+1]==0)//////////////////////////3
    {
      int jud4=dfs(y,x+1,8);
      if(jud4==1)return 1;
    }
    if(y-1>=1&&x+1<=n&&map[y-1][x+1]==0&&road[y-1][x+1]==0)/////////////4
    {
      int jud6=dfs(y-1,x+1,7);
      if(jud6==1)return 1;
    }
    if(y-1>=1&&map[y-1][x]==0&&road[y-1][x]==0) //////////////////////5
    {
      int jud8=dfs(y-1,x,6);
      if(jud8==1)return 1;
    }
    if(y-1>=1&&x-1>=1&&map[y-1][x-1]==0&&road[y-1][x-1]==0)/////////////6
    {
      int jud7=dfs(y-1,x-1,5);
      if(jud7==1)return 1;
    }
    if(x-1>=1&&map[y][x-1]==0&&road[y][x-1]==0)////////////7
    {
      int jud3=dfs(y,x-1,4);
      if(jud3==1)return 1;
    }
    if(y+1<=m&&x-1>=1&&map[y+1][x-1]==0&&road[y+1][x-1]==0) //////8
    {
      int jud2=dfs(y+1,x-1,3);
      if(jud2==1)return 1;
    }
    return 0;
  }
}

void out(int y,int x)
{
  if(x==1&&y==1)
  {
    cout<<1<<" "<<1<<endl;
    return;
  }
  else
  {
    int a=map[y][x];
    if(a==1)out(y-1,x-1);
    if(a==2)out(y-1,x);
    if(a==3)out(y-1,x+1);
    if(a==4)out(y,x+1);
    if(a==5)out(y+1,x+1);
    if(a==6)out(y+1,x);
    if(a==7)out(y+1,x-1);
    if(a==8)out(y,x-1);

    cout<<y<<" "<<x<<endl;
  }
  return;
}

int main()
{
  freopen("labyrinth.in","r",stdin);
  freopen("labyrinth.out","w",stdout);
  in();
  int judd=dfs(1,1,0);
  if(judd==1)out(m,n);
  else cout<<-1<<endl;
  return 0;
}
