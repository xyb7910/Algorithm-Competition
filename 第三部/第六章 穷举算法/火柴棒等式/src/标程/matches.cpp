//������ʽ 
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int need[]={6,2,5,5,4,5,6,3,7,6};//����ʮ������ʹ�õĻ���� 
int M[2000];
int ans;

int match(int cur)//����ʹ�õĻ���� 
{
  int ans=0,ret;
  if(cur==0) 
    return 6;
  while(cur>0)
  {
    ret=cur%10;
    ans+= need[ret];
    cur/=10;
  }
  return ans;
}

void GetMatch()//���Ƚ����ִ�0��1999ʹ�õĸ��Ի�����浽match[] 
{
  for(int i=0;i<=1999;++i)
    M[i]=match(i);   
}

int main()
{
  //freopen("matches.in","r",stdin);
  //freopen("matches.out","w",stdout);
  int n=24;
  scanf("%d",&n);
  GetMatch();
  for(int i=0;i<=1000;i++)
    for(int j=i;j<=1000;j++)//�˴��и��Ż� 
    {
      int a=M[i];  
      int b=M[j];
      if(a+b>n-6)//�ұ�������Ҫ������񣬣���+����Ҫ�ĸ���� 
        continue;
      int d=M[i+j];
      if(a+b+d+4==n && i!=j) 
        ans+=2;
      if(a+b+d+4==n && i==j)
        ans++;  
    }
  printf("%d\n",ans);
  return 0;
}
