//�򵥱������⣲-���棲 
#include <iostream>
#include <cstdlib>
using namespace std;
int f[20001];//f[j]��ʾǰi����Ʒװ���õ�������

int main()
{
  freopen("pack2.in","r",stdin);
  freopen("pack2.out","w",stdout);
  int V,n,i,j;
  cin>>V>>n;
  int a[n+1];
  for(i=1;i<=n;i++)
    cin>>a[i];
  for(i=1;i<=n;i++)
    for(j=V;j>=1;j--)
      if(j<a[i])
        f[j]=max(f[j-1],f[j]);//��Ȼf[j]���Ǵ���f[j-1],����䲻����
      else 
        f[j]=max(f[j],f[j-a[i]]+a[i]);
  cout<<V-f[V];
  return 0;
}
