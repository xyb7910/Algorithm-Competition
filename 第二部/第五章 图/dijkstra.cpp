//dijkstra�㷨 
#include<iostream>
using namespace std;
#define Max 0xfffffff
int n;
int map[1000+1][1000+1];//�洢ͼ 
int visit[1000+1];//���÷��ʱ�� 
int d[1000+1];//Դ�㵽���ڵ����С���� 

void Dijkstra(int x) //���x�㵽�����ĵ�Դ���·��
{
  int i,j,Min,p;
  for(i=1;i<=n;i++)//�������ʼ�㵽���������̾���
    d[i]=map[x][i];
  visit[x]=1;//��Դ��Ϊ�ѷ��ʹ�
  d[x]=0;//��������Ϊ��
  for(i=1;i<n;i++)
  {
    Min=Max;//��С�� 
    for(j=1;j<=n;j++)//�ҳ��ܺ���̵�·��
      if(!visit[j] && Min>d[j])//��û���ҹ����ڽӱ�
      {
        p=j;//�ҳ���̱�
        Min=d[j];
      }
    visit[p]=1;
    for(j=1;j<=n;j++)//����δ���Ҷ������С�����ܺ� 
      if(!visit[j] && Min+map[p][j]<d[j])
        d[j]=Min+map[p][j];
  }
  for(int i=1;i<=n;i++)//��ӡ���ӵ�x����������̾��� 
    cout<<d[i]<<' ';
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
}
                     
int main()
{
  init(); //����ͼ 
  Dijkstra(1); 
  return 0;
}
