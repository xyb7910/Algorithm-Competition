//��kС��
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int x,num;
} a[100001];

int m,k;

void Swap(int i,int j)
{
  swap(a[i].x,a[j].x);//��Ԫ�ػ���
  swap(a[i].num,a[j].num);
  swap(i,j);//ָ�뻥��
}

void Operation(int START,int END)
{
  int i=START;
  int j=END;
  while(i!=j)//��ָ��δ�غ�ʱ
  {
    if(i<j)//��iָ����jָ����
    {
      if(a[i].x>a[j].x)
        Swap(i,j);
      else
        --j;//jָ������
    }
    else//��iָ����jָ���ң�ָ���ѻ�����
    {
      if(a[i].x<a[j].x)
        Swap(i,j);
      else
        ++j;//jָ������
    }
  }
  if(i<k) //��ʱi��j���غ�
    Operation(i+1,END);//ȡ�ұ�����ݹ����
  else if(i==k)//�����ҵ���kС��
  {
    cout<<a[i].num<<"\n";//����𰸼�ԭλ��
    return;
  }
  else
    Operation(START,i-1);//ȡ�������ݹ����
}

int main()
{
  freopen("K17.in","r",stdin);
  freopen("K17.txt","w",stdout);
  scanf("%d%d",&m,&k);
  for(int i=1; i<=m; i++)
  {
    scanf("%d",&a[i].x);
    a[i].num=i;
  }
  Operation(1,m);//��1~m֮�俪ʼ���ֲ���
  return 0;
}

