//�����е����ֵ�ĵݹ��� 
#include <iostream>
using namespace std;

int maxn(int a[],int n)
{  
  if(n==1)
    return a[n-1];
  else//�˴�����һ��ʱ��������ʱ����Ż� 
    return maxn(a,n-1)>a[n-1]?maxn(a,n-1):a[n-1];    
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;++i)
    cin>>a[i];
  cout<<maxn(a,n)<<endl;//������ֵ  
  system("pause");
}
