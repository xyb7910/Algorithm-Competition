//���� 
#include <bits/stdc++.h>
using namespace std;

int c[32000+10];
int a[15000+10];

int lowbit(int x)
{
  return x&(-x);
}

void updata(int x,int value)
{
  for(int i=x; i<=32001; i+=lowbit(i))
    c[i]+=value;
}

int getsum(int x)
{
  int sum=0;
  for(int i=x; i>0; i-=lowbit(i))
    sum +=c[i];
  return sum;
}

int main()
{
  freopen("stars.in","r",stdin);
  freopen("stars.out","w",stdout);	
  int n,x,y;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d%d",&x,&y);//�±���ܴ�0��ʼ,����Ҫx+1,��Ϊlowbit(0)=0����ѭ��
    a[getsum(x+1)]++;   //���������С��x������stars����������¼��a��
    updata(x+1,1);      //��������
  }
  for(int i=0; i<n; i++)
    printf("%d\n",a[i]);
  return 0;
}

