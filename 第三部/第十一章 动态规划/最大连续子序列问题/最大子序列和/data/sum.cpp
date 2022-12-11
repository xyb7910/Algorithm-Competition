/*
�������ƣ���������к� 
����˵�����Ż��㷨�������ǰi�����ĺ�s[i]����a[i]+a[i+1]+...+a[j]=s[j]-s[i-1]
ʱ�临�Ӷ�=O(n+n^2)=O(n^2) 
�������ߣ�ZXH (2010-4-14)
����ע�������ļ�Ϊsum.in,����ļ�Ϊsum.out,N<=10000000
*/ 
#include <iostream>
using namespace std;
#define MAX 10000000
int n,i,j,maxn,s[MAX+1],a[MAX+1];

int main()
{
  freopen("sum10.in","r",stdin);
  freopen("sum10.ans","w",stdout);  
  cin>>n;
  s[0]=0;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
    s[i]=s[i-1]+a[i];
  } 
  maxn=a[1];
  for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
      if(s[j]-s[i-1]>maxn)
        maxn=s[j]-s[i-1];
  cout<<maxn<<endl;  
  return 0;
}
