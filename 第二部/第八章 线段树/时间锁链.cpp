//ʱ������
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int ans;

struct node
{
  int left,right;
  int col;//������������ɫ
  int lazy; //����Ƿ����
  int mid()
  {
    return (left+right)>>1;
  }
} E[N*4];

void build(int root,int l,int r)//����
{
  E[root].left=l;
  E[root].right=r;
  E[root].col=1;
  E[root].lazy=0;//��ʼΪδ���
  if(l==r)
    return;
  else
  {
    int mid=E[root].mid();
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
  }
}

void update(int root,int l,int r,int c)//lazy˼�룬�ӳٸ���
{
  if(E[root].left==l && E[root].right==r)//ǡ��Ϊ�ö�
  {
    E[root].col=c;
    if(l!=r)
      E[root].lazy=1;
    return;
  }
  else
  {
    if(E[root].lazy==1)//����������
    {
      E[root<<1].lazy=E[root<<1|1].lazy=1;//���ӽ��Ҳ�����
      E[root<<1].col=E[root<<1|1].col=E[root].col;//���ӽ����¸������ɫ
      E[root].lazy=0;//�������
    }
    int mid=E[root].mid();
    if(r<=mid)
      update(root<<1,l,r,c);//��������
    else if(l>mid)
      update(root<<1|1,l,r,c);//�����ҽ��
    else
    {
      update(root<<1,l,mid,c);
      update(root<<1|1,mid+1,r,c);
    }
  }
  E[root].col=E[root<<1].col | E[root<<1|1].col;//λ��
}

int query(int root,int l,int r)
{
  if((E[root].left==l && E[root].right==r) || E[root].lazy==1)
    return E[root].col;
  else
  {
    int mid=E[root].mid();
    if(r<=mid)
      return query(root<<1,l,r);//�ݹ�����
    else if(l>mid)
      return query(root<<1|1,l,r);//�ݹ��ҽ��
    else
      return query(root<<1,l,mid)|query(root<<1|1,mid+1,r);//���εĺϲ�
  }
}

int Color(int x)//��xת��Ϊ��������
{
  return 1<<(x-1);//����x=7ʱ������ֵΪ64�������Ƽ�1000000
}

int uncode(int x)//��������Ƶ�x���ж��ٸ�1
{
  int t=0;
  while(x>0)
  {
    if(x%2==1)
      t++;
    x/=2;
  }
  return t;
}

int main()
{
  char c;
  int L,t,m;
  while(scanf("%d%d%d",&L,&t,&m)!=EOF)
  {
    build(1,1,L);
    for(int i=0; i<m; i++)
    {
      scanf(" %c",&c);
      if(c=='C')
      {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c=Color(c);//����ɫתΪ������
        a<b?update(1,a,b,c):update(1,b,a,c);
      }
      else if(c=='P')
      {
        int st,en;
        scanf("%d%d",&st,&en);
        if(st<en)
          ans=uncode(query(1,st,en));
        else
          ans=uncode(query(1,en,st));
        printf("%d\n",ans);
      }
    }
  }
  return 0;
}

