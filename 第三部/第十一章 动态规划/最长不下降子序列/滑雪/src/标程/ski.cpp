//��ѩ 
#include <stdio.h>
#include<iostream>
const int dx[4]={-1,0,1,0};//x���������� 
const int dy[4]={0,1,0,-1};//y���������� 
long r,c,i,j,p,t,ans;
using namespace std;
unsigned int m[100+1][100+1];
unsigned int f[100+1][100+1];

unsigned int search(long x,long y)//��[x,y]����·�� 
{
  unsigned int result;
  long i,t,tmp,nx,ny;
  if(f[x][y]>0)  //��˵㳤����������򲻱ؽ��еݹ顣��֤ÿ���㳤��ֻ��һ�� 
    return f[x][y];
  t=1;
  for(i=0;i<=3;i++)//���ĸ��������ܵ���[x,y]�ĵ� 
  {
    nx=x+dx[i];//���Ϻ��������� 
    ny=y+dy[i];//�������������� 
    if((nx>=1)&&(nx<=r)&&(ny>=1)&&(ny<=c)&&(m[x][y]<m[nx][ny]))//�߽����� 
    {
      tmp=search(nx,ny)+1;//�ݹ���м��仯���� 
      if(tmp>t)
        t=tmp;
    }
  }
  f[x][y]=t;
  return t;
}

int main()
{
  freopen("ski.in","r",stdin);
  freopen("ski.out","w",stdout);
  scanf("%ld%ld",&r,&c);
  for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
      scanf("%u",&m[i][j]);
  ans=0;
  for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
    {
      t=search(i,j);
      f[i][j]=t;
      if(t>ans)
        ans=t;
   
      
    } 
  printf("%ld\n",ans);
  return 0;
}
