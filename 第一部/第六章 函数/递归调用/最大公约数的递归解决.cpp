//���Լ���ĵݹ��� 
#include <iostream>
using namespace std;

int gcd(int m,int n)
{  
  if(n==0)
    return m;
  else
    return gcd(n,m%n);  
}

int main()
{
  int a,b,t;
  cin>>a>>b;//����36 24��gcdΪ12 
  if(a<b)
    {t=a;a=b;b=t;}
  cout<<gcd(a,b)<<endl;
  system("pause");
}
