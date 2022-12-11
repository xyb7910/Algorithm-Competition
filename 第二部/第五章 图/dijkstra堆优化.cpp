//dijkstra���Ż� 
#include<iostream>
using namespace std;
#define Max 0xfffffff
int n,m,ms;
int map[1000+1][1000+1];//�洢ͼ 
int visit[1000+1];//���÷��ʱ�� 
int d[1000+1];//Դ�㵽���ڵ����С���� 
int heap[1000+1];//�� 
int pos[1000+1],posh[1000+1];//pos[i]�洢���е�i����ͼ�е�λ�ã�posh[i]�洢ͼ�еĵ�i�ڶ��е�λ�� 

void minheap(int x)//ά����С�� 
{
  int l,r,t;
  t=x;
  l=t<<1;
  r=(t<<1)+1;
  if(l<=ms && heap[l]<heap[t])
    t=l;
  if(r<=ms && heap[r]<heap[t])
    t=r;
  if(t!=x)
  {
    swap(heap[x],heap[t]);
    swap(posh[pos[x]],posh[pos[t]]);
    swap(pos[x],pos[t]);
    minheap(t);
  }
}

void build()//������ 
{
  int i;
  for(i=1;i<=n;i++)
    pos[i]=posh[i]=i;
  for(i=n>>1;i>=1;i--)
    minheap(i);
}

void insert(int x)//�ı����ĳ��Ԫ�ص�ֵ 
{
  while(x>1 && heap[x]<heap[x>>1])
  {
    swap(heap[x],heap[x>>1]);
    swap(posh[pos[x]],posh[pos[x>>1]]);
    swap(pos[x],pos[x>>1]);
    x>>=1;
  }
}

void Dijkstra(int x)//���x�㵽�����ĵ�Դ���·�� 
{
  int i,j,Min,p,q;
  for(i=1;i<=n;i++)//��ʼ������Ԫ�� 
    heap[i]=map[1][i];
  heap[x]=0;
  build();//����
  for(i=1;i<n;i++)
  {
    p=pos[1];//����С��Ԫ�������������Ǹõ� 
    q=heap[1];
    visit[p]=1;
    swap(heap[1],heap[ms]);
    swap(posh[pos[1]],posh[pos[ms]]);
    swap(pos[1],pos[ms]);//������Ԫ�غ���С��Ԫ�ؽ�������������ά���� 
    ms--;//ÿȷ��һ���㣬�Ѷ�����С1 
    minheap(1);//ά����С�� 
    for(j=1;j<=n;j++)//����δ���Ҷ������С�����ܺ� 
      if(!visit[j] && q+map[p][j]<heap[posh[j]])
      {
        heap[posh[j]]=q+map[p][j];
        insert(posh[j]);//�޸�j���ڶ����λ�� 
      }
  }
  for(i=1;i<=n;i++)//��ӡ���·�� 
    cout<<heap[posh[i]]<<' ';
  cout<<endl;
}

void init()
{
  cin>>n;//n���ڵ� 
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      cin>>map[i][j];
      if(map[i][j]==0)//��������·��,��Ϊ+��,����ʱҪС����� 
        map[i][j]=Max;
    }
  ms=n;
} 
                    
int main()
{
  init(); //����ͼ 
  Dijkstra(1); 
  return 0;
}
