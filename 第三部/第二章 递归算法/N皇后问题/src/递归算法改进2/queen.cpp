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

void place(int x,int y)
{
  int i;
  if(x==n+1)
    total++;
  else
  {
    for(i=1;i<=y;i++)
    {
      if((!lie[i])&&(!x1[x+i])&&(!(x2[x-i+n])))//���û�г�ͻ 
      {
        a[x]=i;
        lie[i]=1;//����б��Ϊ1 
        x1[x+i]=1;//����б�߱��Ϊ1 
        x2[x-i+n]=1;//�÷�б�߱��Ϊ1
        if(n%2!=0 && x==1 && a[1]==(n+1)/2)
          place(2,(n+1)/2-1);
        else   
          place(x+1,n);
        lie[i]=0;//��ԭ 
        x1[x+i]=0;//��ԭ 
        x2[x-i+n]=0;//��ԭ 
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
  place(1,(n+1)/2);
  cout<<total*2<<endl;
  return 0;
}
