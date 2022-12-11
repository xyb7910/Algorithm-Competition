//��С�������� 
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define maxn 10000

struct data
{
  int x;
  int y;
  int w;
}sides[maxn+1]; //��¼�ߵ������յ㣬����Ȩֵ
int set[110];//���鼯������
bool flag[maxn+1];//��¼ĳ��������С���������Ƿ�ʹ�ù����ù���ֵΪ1

int cmp(const void *a,const void *b)
{
  return ((data *)a)->w - ((data *)b)->w;
}

int find(int x) //Ѱ�Ҹ��ڵ㣻
{
  if(set[x]==x) 
    return x;
  set[x]=find(set[x]); //Ѱ�ҵĹ����У�����set[x]��ֵ��·��ѹ����
  return set[x];
}

int main()
{
  int n,i,j,ans,t,ans1,rx,ry,before,m;
  bool OK;//��־�Ƿ��ҵ��𰸣�
  scanf("%d%d",&n,&m);
  OK=0;
  for(i=1;i<=m;i++)
    scanf("%d%d%d",&sides[i].x,&sides[i].y,&sides[i].w);
  qsort(&sides[1],m,sizeof(sides[0]),cmp);   //̰�ģ����򣬰�Ȩֵ��
  for(i=1;i<=n;i++) 
    set[i]=i;//���鼯��ʼ����
  for(i=1;i<=m;i++)//��ʼ��Ϊδ��ʹ�ù� 
    flag[i]=0;
  ans=0;
  i=0;
  j=0;
  while(i<n-1)//kruscal
  {
    j++;
    rx=find(sides[j].x);//Ѱ�Ҹ��ڵ�
    ry=find(sides[j].y);
    if(rx!=ry)
    {
      i++;
      ans+=sides[j].w;
      set[rx]=set[ry]; //�ϲ����� ��
      flag[j]=1;
    }   
  }
  if(m==n-1)//Ψһ��С��������ֱ�������� 
  {
    printf("%d\n",ans);
    return 0;
  }
  //��ʼѰ�Ҵ�С������   
  before=1;
  flag[before]=0;
  for(t=1;t<=n-1;t++) //����n-1��ɾ�ߵĲ�������
  {
    for(i=1;i<=n;i++)//�ظ��²��鼯���� 
      set[i]=i;
    i=0;
    j=0;
    ans1=0;
    while(i<n-1)//ͬ���Ĳ���������С������
    {
      j++;
      if(j!=before)//ÿ��ɾ��һ����
      {
        rx=find(sides[j].x);
        ry=find(sides[j].y);
        if(rx!=ry)
        {
          i++;
          ans1+=sides[j].w;
          set[rx]=set[ry];//����ͬһ���� 
        }   
      }
    }
    if(ans1==ans) 
    { 
      OK=1; break;
    }
    for(i=before+1;i<=m;i++)//Ѱ��һ���ߣ���ֵbefore����ɾ���õ�
      if(flag[i])//����ñ�����С�������� 
      { 
        before=i; //ȷ����һ��Ҫɾ���ı� 
        flag[before]=0; 
        break;
      } 
  }
  if(OK) 
    printf("Not Unique\n");
  else 
    printf("%d\n",ans);
  system("pause");
  return 0;
}
