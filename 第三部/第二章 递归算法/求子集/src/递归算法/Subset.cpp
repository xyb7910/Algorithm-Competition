//���Ӽ�-�ݹ��㷨 
#include <iostream>
#include <cstdlib>
using namespace std;
int i,j,n;
int a[26+1];//��01����ǣ�����Nλ01��Ӧһ��Nλ����������ö�� 

void print()
{
  int i;
  cout<<"(";
  for(i=1;i<=n;i++)
    if(a[i]==1)
      cout<<char('a'+i-1)<<' ';
  cout<<")\n";
}

void Try(int digit)
{
  for(int i=0;i<=1;i++)//������е�0��1��� 
  {
    a[digit]=i;
    if(digit==n)
      print();
    else
      Try(digit+1);
    a[digit]=-1;
  }
}

int main()
{
  freopen("Subset.in","r",stdin);
  freopen("Subset.out","w",stdout);  
  cin>>n;
  for(i=1;i<=n;i++)
    a[i]=-1;
  Try(1);
  return 0;
}
