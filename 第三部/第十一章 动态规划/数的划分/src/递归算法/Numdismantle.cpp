//���Ļ��֣��ݹ� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,k,sum=0;

//x��ʾҪö�ٵ�����kk��ʾ������nn��ʾʣ�µ���
void work(int x,int kk,int nn)
{
  if(kk==k)
    ++sum;
  else
    for(int i=x;i<=nn/(k+1-kk);++i) 
      work(i,kk+1,nn-i);//��ٵ������nn/(k+1-kk)���Ա�֤����С����
}

int main()
{
  freopen("Numdismantle.in","r",stdin);
  freopen("Numdismantle.out","w",stdout);
  cin>>n>>k;
  work(1,1,n);
  cout<<sum<<'\n';
  return 0;
}
