//���� 
#include <iostream>
using namespace std;

int a[10+1];
int pow(int k,int n)//k��n�η� 
{
  int temp=k,x;
  if (n==0)
    return 1;
  for(int i=1;i<n;i++)
    k=k*temp;
  return k;
}

int main()
{
  int n,i=-1,j,k,ans=0;
  cin>>k>>n;
  do//��nתΪ������ 
  {
    i=i+1;
    a[i]=n%2;
    n=n/2;
  }while(!(n==0));
    
  for(j=0;j<=i;j++)//�ۼ� 
    if(a[j]==1)
      ans+=pow(k,j);
  cout<<ans<<endl;
  return 0;
} 
