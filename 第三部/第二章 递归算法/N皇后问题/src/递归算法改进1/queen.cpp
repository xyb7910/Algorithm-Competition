/*
�Ľ�1 
*/
#include <iostream>
#include <math.h>
using namespace std;

int a[20+1];
char x1[40+1];//б����Ϊ2*N+1�����ж���б��"/"�� 
char x2[40+1];//��б��"\"�����壬������� 
char lie[20+1];//����г�ͻ�������i�����壬��lie[i]=1,����һ��ʱֱ�Ӳ鿴lie[i]���� 
long total,n;

void place(int x)
{
  int i;
  if(x==n+1)
    total++;
  else
  {
    for(i=1;i<=n;i++)
    {
      if((!lie[i])&&(!x1[x+i])&&(!abs(x2[x-i])))//���û�г�ͻ 
      {
        a[x]=i;
        lie[i]=1;//����б��Ϊ1 
        x1[x+i]=1;//����б�߱��Ϊ1 
        x2[x-i]=1;//�÷�б�߱��Ϊ1 
        place(x+1);
        lie[i]=0;//��ԭ 
        x1[x+i]=0;//��ԭ 
        x2[x-i]=0;//��ԭ 
      }
    }
  }
}
int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  total=0;
  cin>>n;
  place(1);
  cout<<total<<endl;
  return 0;
}
