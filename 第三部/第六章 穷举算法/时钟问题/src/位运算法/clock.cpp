//ʱ�����⣭λ���㣬ע��˷��޷��������� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int mov[9]={18911232,19136512,2363904,16810048,2134536,262657,36936,73,4617};
const int mod=57521883;
const int Maxn=10000000;

int f[Maxn];
char g[Maxn][30];

void work()
{
  int i,j,t,rear=0,st=0,ed=0;
  for (i=1;i<=9;++i)
  {
    //��ԭ���������� f[0] ��ǰ��3λ ���ټ��� T 
    scanf("%d",&t);
	f[0]<<=3;f[0]+=t;
  }
  while(1)
  {
	/*
    ��һ�����н��Ϊ f[st] �� f[ed] ��
    ʹ��9�ֱ�÷���������б�ã��õ��µ� f[ed+1] �� f[rear] ���� g �����������
    ֪���õ� f[x] Ϊ 0 ʱ,�����. 
	*/
	for (i=st;i<=ed;++i)
	{
	  for (j=0;j<9;++j)
	  {
	    f[++rear]=(f[i]+mov[j])&mod;
	    strcpy(g[rear], g[i]);
	    g[rear][strlen(g[rear])]=49+j;
	    if (!f[rear])
	    {
		  for (i=0;i<strlen(g[rear]);++i)
			printf("%c ",g[rear][i]);
	      printf("\n");
	      return;
        }
      }
	}
	st=ed+1;
	ed=rear;
  }
}

int main()
{
  freopen("clock.in","r",stdin);
  freopen("clock.out","w",stdout);  
  work();
  return 0;
}
