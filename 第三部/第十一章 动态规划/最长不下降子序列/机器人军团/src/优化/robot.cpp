//����½����У������Ż��㷨 
#include <cstdlib>
#include <iostream>
using namespace std;
int a[100001];
int Link[100001];//����,ע��linux����һ��link�ĺ���������ĸ��д�Է�ֹ��ͻ 
int Long[100001];
int n,Max;

int find(int key)//���ֲ��� 
{
  int L=1,R=Max,mid;
  while(L<=R)
  {
     mid=(L+R)/2;
     if(a[Long[mid]]<key)
       L=mid+1;
     else R=mid-1;
  }
  return L-1;
}

int main()
{
  freopen("robot.in","r",stdin);
  freopen("robot.out","w",stdout);  
  int i,j,k,l;
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>a[i];
  Max=1;//��ʼ������Ϊ1 
  Long[Max]=1;//��ʼΪ��һ��Ԫ�� 
  Link[1]=1;//��ʼ��Ϊ��һ��Ԫ�� 
  for(i=2;i<=n;i++)
  {
    if(a[i]>=a[Long[Max]])//���ڼȶ�����֮�� 
    { 
      Max++;
      Long[Max]=i;
      Link[i]=Long[Max-1];
    }
    else//�ڼȶ������в���λ�ò����� 
    {
      l=find(a[i]);
      Long[l+1]=i;
      Link[i]=Long[l];
    }
  }
  cout<<Max<<'\n';
  k=Max;
  i=Long[Max];
  while(Max>0)
  {
    Long[Max]=a[i];//��Ϊ Long[max]=i �������� 
    i=Link[i];
    Max--;
  }
  //for(i=1;i<=k;i++)
  //cout<<Long[i]<<' ';
  //system("pause");
  return 0;
}
