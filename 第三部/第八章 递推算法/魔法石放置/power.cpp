//Ä§·¨Ê¯·ÅÖÃ
#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int Cal(int m,int n)
{
  if(m==0||n==1)
    return 1;
  if(m<n)
    return Cal(m,m);
  return Cal(m,n-1)+Cal(m-n,n);
}
int main()
{
  int k,m,n;
  cin>>k;
  while(k--)
  {
    cin>>m>>n;
    cout<<calculate(m,n)<<endl;
  }
  return 0;
}

