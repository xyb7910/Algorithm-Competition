//ʮ����С��תΪN����
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

double x;
int n;
string s;

void fun(double x,int n,int m)
{
  const string a="0123456789ABCDEF";
  int u;
  s='.';
  while(x>0 && m>0)
  { 
    m--;//����С��λ����1
    x=x*n;
   
    s=s+a[int(x)];//ȡ�������ηź���
    x=x-int(x);//ȡX��С������
  }
}

int main()
{
  cin>>x>>n;   
  if (x<1)
    fun(x,n,20);
  cout<<s;
  system("pause");  
}
