//�򵥱������⣲-��� 
#include <iostream>
#include <cstdlib>
using namespace std;
int a[30+1];//״̬Ϊ0-1��װ��Ϊ1����װ��Ϊ0 
long v,n,i,j,s,f;
long t[30+1];//����ÿ��Ʒ����� 
int main()
{
  freopen("pack2.in","r",stdin);
  freopen("pack2.out","w",stdout);  
  scanf("%ld%ld",&v,&n);
  for(i=1;i<=n;i++)
    scanf("%ld",&t[i]);
  memset(a,0,sizeof(a));
  s=0;
  while(a[0]==0)//��� 
  {
    f=0;
    for(i=1;i<=n;i++)
      f=f+a[i]*t[i];//���㲻ͬ״̬�������� 
    if((f>s)&&(f<=v)) 
      s=f;
    j=n;
    while(a[j]==1)//��λ 
      j=j-1;
    a[j]=1;
    for(i=j+1;i<=n;i++)
      a[i]=0;
  }
  printf("%ld\n",v-s);
  return 0;
}
