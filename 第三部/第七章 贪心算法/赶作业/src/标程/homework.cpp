//����ҵ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1002
int flag[MAX];

typedef struct node
{
  int deadline;
  int score;
}limit;

limit c[MAX];

int cmp(const void *a,const void *b)
{
  if((*(limit *)a).score!=(*(limit *)b).score)
    return (*(limit *)b).score>(*(limit *)a).score?1:-1;
  else
    return (*(limit *)a).deadline>(*(limit *)b).deadline?1:-1;
}

int main()
{
  freopen("homework.in","r",stdin);  
  freopen("homework.out","w",stdout); 
  int t,n,i,sum,j;
  scanf("%d",&t);
  while(t--)
  {
    sum=0;
    memset(flag,0,sizeof(flag));
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&c[i].deadline);
    for(i=0;i<n;i++)
      scanf("%d",&c[i].score);
    qsort(c,n,sizeof(c[0]),cmp);
    for(i=0;i<n;i++)
    {
      for(j=c[i].deadline;j>0;j--)//���������޿�ʼ����ǰ������û�б����� 
      {                           //���һֱ��������û�п���ʱ�䣬���ֻ�ܿ۷� 
        if(0==flag[j]) 
        {
          flag[j]=1;
          break;
        }
      }
      if(0==j)
         sum+=c[i].score;    
    }
    printf("%d\n",sum);                    
  }
  return 0;
}
