//Blah����
#include <bits/stdc++.h>
using namespace std;
int  q[1000005];

int main()
{
  freopen("blah.in","r",stdin);
  freopen("blah.out","w",stdout);
  int a,n,num=1,p2=1,p3=1,t2,t3;
  cin>>a>>n;
  q[1]=a;
  while(num<n)
  {
    t2=q[p2]*2+1;
    t3=q[p3]*3+1;
    if(t2>t3)
    {
      q[++num]=t3;
      p3++;
    }
    if(t2==t3)//�����ȵ������
    {
      q[++num]=t2;//ֻ�ܷ�һ��
      p2++;//��t2ָ��Ҫ����
      p3++;//t3ָ��ҲҪ����
    }
    if(t2<t3)
    {
      q[++num]=t2;
      p2++;
    }
  }
  cout<<q[n]<<endl;
  return 0;
}

