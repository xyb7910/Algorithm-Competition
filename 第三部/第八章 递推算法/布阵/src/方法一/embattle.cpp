//���� -����1 
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ 
  freopen("embattle.in","r",stdin);
  freopen("embattle.out","w",stdout);    
  long long n,i,fn=0,fn_1,fn_2;
  cin>>n;
  if(n==1)
    fn=3; //��ʼ����n=1��n=2ʱ���ٽ����� 
  else if(n==2)
    fn=7;
  else
  { 
    fn_1=7;
    fn_2=3;
    for(i=3;i<=n;i++)
    {
      fn=2*fn_1+fn_2; //��n>=3ʱfn��ͨʽ 
      fn_2=fn_1;//����fn_1��fn_2��ֵ 
      fn_1=fn;
    }
  }
  cout<<fn<<'\n';
  return 0;
}
