//�ӣУƣ��㷨 
#include <iostream>
#define MAX 99999999
using namespace std;
struct node//������洢�߽��Ϳռ临�Ӷȣ���������ɽ��ʹ��븴�Ӷ�
{
  int n;
  int v;//�ߵ�Ȩֵ 
  node *next;
  node()//��ʼ�� 
  {
    n=0;
    next=NULL;
  }
}*e[1001];//���ÿһ���㵽��ĵ�ı� 
int d[1001];//����ֵ 
bool c[1001];//�жϸö����Ƿ�����ڶ��� 
int line[2002];//����
int rear;//����ĩβ 
int n,m;//nΪ��������mΪ���� 

void init()
{
  cin>>n>>m;
  node *p;
  int i,j;
  int x,y,v;
  for(i=1;i<=m;i++)
  {
    cin>>x>>y>>v;
    p=new node();
    p->n=y;
    p->v=v;
    if(e[x]==NULL)
      e[x]=p;
    else
    {
      p->next=e[x]->next;
      e[x]->next=p;
    }
  }
}

void add(int x)
{
  rear++;
  line[rear]=x;
}

void SPFA(int x)
{
  int i,j;
  node *p;
  add(x);//����ʼ�������� 
  for(i=1;i<=n;i++)
    d[i]=MAX;//��ʼ������ֵ 
  d[x]=0;
  for(i=1;i<=rear;i++)//��ȡ���� 
  {
    p=e[line[i]];//��line[i]�����ӵı� 
    while(p!=NULL)//������бߵĻ� 
    {
      if(d[line[i]]+p->v<d[p->n])//��ͨ��line[i]�㵽��p->n��ľ����ԭ���� 
      { 
        d[p->n]=d[line[i]]+p->v;//���¾��� 
        if(!c[p->n])//���p->n�㲻�ڶ�����
        { 
          c[p->n]=1;//���Ϊ�Ѽ������
          add(p->n);//������� 
        }
      }
      p=p->next;//����i�����һ��� 
    }
    c[line[i]]=0;//line[i]����� 
  }
  for(i=1;i<=n;i++)//��ӡ��x�㵽��������̾��� 
    cout<<d[i]<<' ';
  cout<<endl;
}

int main()
{
  init();
  SPFA(1);
  return 0;
}
