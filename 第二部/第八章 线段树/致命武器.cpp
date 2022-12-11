//��������
#include <bits/stdc++.h>
using namespace std;
#define lson l,m,k<<1
#define rson m+1,r,k<<1|1
#define N 100001

int st[N<<2];//st���������¼���Ǳ�ǣ�0,1,2,3;0������ɫ�����Ǵ�ɫ
int flag;

void down(int &k)
{
  st[k<<1]=st[k<<1|1]=st[k];//����Ӻ��Ҷ��Ӿ���Ϊ����ɫ
  st[k]=0;//��Ϊ��ɫ
}

void build(int l,int r,int k)//���߶���������ʼΪ1
{
  st[k]=flag;
  if(l==r)
    return ;
  int m=(l+r)>>1;//����
  build(lson);
  build(rson);
}

void updata(int &L,int &R,int l,int r,int k)//����L-R��Ҫ��1-n,st[1]��ʼ
{
  if(L<=l && R>=r)//������²���ǡ�ñ�������ĳ�߶�����
  {
    st[k]=flag;//������һ�ζ�����Ϊ����ɫ
    return ;
  }
  if(st[k])//����ý��Ϊ��ɫ�������Ҷ�����ɫҲΪ�ô�ɫ
    down(k);
  int m=(l+r)>>1;
  if(L<=m)
    updata(L,R,lson);//�ݹ���������
  if(R>m)
    updata(L,R,rson);//�ݹ�����Ҷ���
}

int query(int l,int r,int k)
{
  if(st[k])  //Ϊ��ɫʱ��ֱ�ӳɶ���˵ó������������
    return st[k]*(r-l+1);
  int m=(l+r)>>1,t1,t2;
  t1=query(lson);
  t2=query(rson);
  return t1+t2;
}

int main()
{
  int T,n,t=1;
  int L,R,q;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&q);
    flag=1;
    build(1,n,1);
    while(q--)
    {
      scanf("%d%d%d",&L,&R,&flag);
      updata(L,R,1,n,1);
    }
    printf("Case %d: The total value of the hook is %d.\n",t++,query(1,n,1));
  }
  return 0;
}

