//���ӵ����� 
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node
{
  long long v;//ֵ 
  int x,y;//���������� 
  int Long;//��¼���� 
}n[101][501];

int M,N;
long long f[101][501],ans;

int main()
{
  freopen("approval.in","r",stdin);
  freopen("approval.out","w",stdout);  
  int i,j;
  int w,x,y;
  unsigned long long tmp;
  scanf("%d%d",&M,&N);
  for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
      scanf("%lld",&n[i][j].v);
  if(M==1)//ֻ��һ������ 
  {
    ans=n[1][1].v;
   	tmp=1;
   	for(i=1;i<=N;i++)
   	  if(ans>n[1][i].v)
   	  {
  	  	ans=n[1][i].v;
  	  	tmp=i;
   	  }
    cout<<tmp;
  }
  else
  {
   	for(i=1;i<=M;i++) 
   	  f[i][0]=f[i][N+1]=10000000000001LL;
   	for(i=1;i<=N;i++) 
    {
      f[M][i]=n[M][i].v;
      n[M][i].Long=1;
    }
    for(i=M-1;i>=1;i--)//DP���飬
    //����f[i][j]=max(f[i+1][j],f[i][j-1],f[i][j+1])+n[i][j].v
    //�������ֻ��Ҫÿ���ȴ������Ҷ����ٴ������󶯹� 
    {
   	  for(j=1;j<=N;j++)//�������Ҷ��� 
      {
       	if(f[i+1][j]>f[i][j-1])
   	    {
  	  	  f[i][j]=n[i][j].v+f[i][j-1];
  	  	  n[i][j].x=i;//��¼ǰ�� 
  	  	  n[i][j].y=j-1;
  	  	  n[i][j].Long=n[i][j-1].Long+1;//��¼���� 
   	    }
   	   	else if(f[i+1][j]<f[i][j-1])
   	    {
  	      f[i][j]=n[i][j].v+f[i+1][j];
  	  	  n[i][j].x=i+1;
  	  	  n[i][j].y=j;
  	  	  n[i][j].Long=n[i+1][j].Long+1;
   	    }
   	   	else//�����߷�����ͬʱ��ѡ�񳤶ȸ��̵� 
   	    {
  	  	  if(n[i+1][j].Long>n[i][j-1].Long)
  	  	  {
    	  	f[i][j]=n[i][j].v+f[i][j-1];
    	  	n[i][j].x=i;
    	  	n[i][j].y=j-1;
    	  	n[i][j].Long=n[i][j-1].Long+1;
  	  	  }
  	  	  else
  	  	  {
 	        f[i][j]=n[i][j].v+f[i+1][j];
      	  	n[i][j].x=i+1;
      	  	n[i][j].y=j;
      	  	n[i][j].Long=n[i+1][j].Long+1;
  	  	  }
   	    }
      }
   	  for(j=N;j>=1;j--)//�������󶯹� ��ͬ�� 
      {
 	   	if(f[i][j]>f[i][j+1]+n[i][j].v)
   	    {
  	      f[i][j]=n[i][j].v+f[i][j+1];
  	  	  n[i][j].x=i;
  	  	  n[i][j].y=j+1;
  	  	  n[i][j].Long=n[i][j+1].Long+1;
   	    }
   	   	else if(f[i][j]<f[i][j+1]+n[i][j].v)
  	  	  continue;
   	   	else
   	    {
  	  	  if(n[i][j].Long>n[i][j+1].Long+1)
  	  	  {
 	  	  	f[i][j]=n[i][j].v+f[i][j+1];
    	  	n[i][j].x=i;
    	  	n[i][j].y=j+1;
    	  	n[i][j].Long=n[i][j+1].Long+1;
  	  	  }
  	  	  else
  	  	    continue;
   	    }
      }
    }
    ans=f[1][1];
    w=n[1][1].Long;
    tmp=1;
    for(i=1;i<=N;i++)//�� 
    {
   	  if(ans>f[1][i]||(ans==f[1][i]&&n[1][i].Long<w))
   	  {
  	  	ans=f[1][i];
  	  	w=n[1][i].Long;
  	  	tmp=i;
   	  }
    }
    x=1;
    y=tmp;
    cout<<y<<"\n";
    while(n[x][y].Long!=1)
    {
   	  tmp=x;
   	  x=n[x][y].x;
   	  y=n[tmp][y].y;
   	  cout<<y<<"\n";
    }
  }
  return 0;
}
