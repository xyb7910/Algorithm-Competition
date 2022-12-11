//数独游戏
#include <bits/stdc++.h>
using namespace std;

int graph[9][9];
bool x_used[9][10];
bool y_used[9][10];
bool flag=false,error=false;

void Print()
{
  for(int i=0; i<9; i++)
  {
    if(i!=0 && i%3==0)
      printf("\n");
    for(int j=0; j<9; j++)
    {
      if(j!=0 && j%3==0)
        printf("  ");
      printf("%d ",graph[i][j]);
    }
    printf("\n");
  }
}

bool Test(int x,int y,int num)            //判断数num在3*3小格中是否可用
{
  x=x/3*3;
  y=y/3*3;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(graph[x+i][y+j]==num)
        return false;
  return true;
}

void Search(int step)                     //搜索填数独
{
  if(step>80)
  {
    flag=true;
    return;
  }
  int i=step/9,j=step%9,num;
  if(graph[i][j]!=0)
    Search(step+1);
  else
  {
    for(num=1; num<10; num++)             //依次尝试每个数
      if(!x_used[i][num] && !y_used[j][num] && Test(i,j,num))
      {
        graph[i][j]=num;
        x_used[i][num]=true;
        y_used[j][num]=true;
        Search(step+1);
        if(flag)
          return;
        graph[i][j]=0;
        x_used[i][num]=false;
        y_used[j][num]=false;
      }
  }
}

void init()                            //输入数独，判断输入是否正确
{
  int num;
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    {
      scanf("%1d",&num);
      if(num!=0)
        if(!Test(i,j,num) || x_used[i][num] || y_used[j][num])
          error=true;
        else
        {
          x_used[i][num]=true;
          y_used[j][num]=true;
        }
      graph[i][j]=num;
    }
}

int main()
{
  init();
  if(!error)
  {
    Search(0);
    Print();
  }
  return 0;
}

