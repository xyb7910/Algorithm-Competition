//�������� 
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;
#define N 10001
int f[N],a[N],longC,Count;//longcΪ�������,CountΪ׼������ 
//ע��count��ҪСд 
int main()
{
  int i,j,n=1;
  freopen("missile.in","r",stdin);
  freopen("missile.out","w",stdout);
  while(scanf("%d",&a[n])!=EOF) 
     n++;  //�������� 
  //�����������ڷ����LIS 
  for(i=1;i<n;i++) 
  {
    f[i]=1;
    for(j=1;j<=i;j++)
      if(a[i]<a[j]&&f[i]<f[j]+1)
        f[i]=f[j]+1;
    if(longC<f[i]) 
      longC=f[i];
  }  
  memset(f,0,sizeof(f));  
  //����½������� 
  for(i=1;i<=n;i++)
  {
    f[i]=1;
    for(j=1;j<=i;j++)
      if(a[i]>a[j]&&f[i]<f[j]+1)               
        f[i]=f[j]+1;       
    if(Count<f[i])                 
      Count=f[i];
  }
  printf("%d %d\n",longC,Count);       
  return 0;    
}
