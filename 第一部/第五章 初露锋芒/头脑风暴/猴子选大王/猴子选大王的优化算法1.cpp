//����ѡ�������Ż��㷨1
#include <iostream>
using namespace std;
#define MAX 10000000
long a[MAX+1];
long m,n,i,Count,k;
int main()
{
  freopen("monkey.in","r",stdin);
  freopen("monkey.out","w",stdout);  
  cin>>m>>n;
  for(i=1;i<=m-1;i++)
    a[i]=i+1;
  a[m]=1;//���һֻ����ָ���һֻ  
  k=m;//����ǰ��ָ��ñ�����ǰһֻ���� 
  for(i=1;i<=m;i++)//��ȦMֻ���� 
  {
    for(Count=1;Count<=n-1;Count++)//ֻ�뱨��n-1�Σ�a[k]ָ��ó�Ȧ���� 
      k=a[k];
    a[k]=a[a[k]];                              
  }
  cout<<k<<endl;//���һֻ��Ȧ���Ǵ��� 
  return 0;
}
