//ʵ�������㷨�� 
#include <iostream>
using namespace std;

typedef double Type;//���ݾ������ݷ�Χ��������Ҫ�õ��߾��ȣ��˴�ֻչʾ�㷨������int 

struct A
{
  Type p,q;//a[i]=p+q*a[2]
}a[70];

int n,m;
Type d,a1,an;

int main()
{
  freopen("realsn.in","r",stdin);
  freopen("realsn.out","w",stdout);
  cin>>n>>d>>m>>a1>>an;
  //��ʼ��a[1],a[2] 
  a[1].p=a1;
  a[2].q=1;
  for(int i=3;i<=n;i++)//���ݵ���ʽ����ÿһ��a[i] 
  {
    a[i].p = a[i-2].p - 2*(a[i-1].p - d);
    a[i].q = a[i-2].q - 2*(a[i-1].q - 0);
  }
  if(n==1)
    cout<<a1<<endl;
  else  //a[m]=p+q*a2 , ����a2=(an-a[n].p)/a[n].q
    cout<<int(a[m].p + a[m].q*(an-a[n].p)/a[n].q)<<endl;
  return 0;
}

