/*����ѡ����-��Ч�㷨1
����˵���� 
�������ߣ�ZXH (2010-4-20)
����ע�������ļ�Ϊmonkey.in,����ļ�Ϊmonkey.out,M,N<=10000000
*/ 
#include <iostream>
using namespace std;
unsigned long m,k,n,r,q;
int main()
{
  freopen("monkey.in","r",stdin);
  freopen("monkey.out","w",stdout);  
  cin>>m>>k;
  n=m*k;//�������ձ���Ϊk*m
  while(n>m)
  {
    r=(n-m)%(k-1);
    if(r==0)
      r=k-1;
    q=(n-m-r)/(k-1);
    n=k*q+r;            
  }
  cout<<n<<endl;
  return 0; 
}
