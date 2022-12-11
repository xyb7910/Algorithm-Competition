//ƹ�����
#include <bits/stdc++.h>
using namespace std;

//��������
struct Link
{
  int data; //�������
  Link* next; //ָ����һ�����
  Link(int=0);
};

Link::Link(int n)//d����Link���һ�ּ̳й�ϵ
{
  data=n;
  next=NULL;
}

int n1,n2,m,ans=0;
int result[101]; //��¼n1�еĵ�ƥ��ĵ�ı��
bool state [101]; //��¼n1�е�ÿ�����Ƿ�������
Link *head [101]; //��¼n2�еĵ���ڽӽ��
Link *last [101]; //�ڽӱ����ֹλ�ü�¼

//�ж��ܷ��ҵ��ӽ��n��ʼ������·
bool find(const int boy)
{
  Link* t=head[boy];
  while (t!=NULL) //boy����δ���ҵ��ڽӽ��ʱ
  {
    if (!(state[t->data])) //����ڽӵ�t->dataδ�����ҹ�
    {
      state[t->data]=true; //���t->dataΪ�Ѿ����ҹ�
      if ((result[t->data]==0) || //���t->data������ǰһ��ƥ��M
          (find(result[t->data]))) //��t->dataƥ�䵽�Ľ�����Ѱ�ҵ�����·
      {
        result[t->data]=boy; //�ɸ���ƥ��M',����n1�еĵ�t->dataƥ��boy
        return true; //����ƥ��ɹ��ı�־
      }
    }
    t=t->next; //����������һ��n���ڽӽ��
  }
  return false;
}

int main()
{
  int t1=0, t2=0;
  cin>>n1>>n2>>m;
  for (int i=0; i<m; i++)
  {
    cin>>t1>>t2;
    if (last[t1]==NULL)
      last[t1]=head[t1]=new Link(t2);
    else
      last[t1]=last[t1]->next=new Link(t2);
  }
  for (int i=1; i<=n1; i++)
  {
    memset(state, 0, sizeof(state));
    if (find(i)) ans++;
  }
  cout<<ans<<endl;
  return 0;
}

