//����ѡ���� 
#include <iostream>
using namespace std;
#define MAX 100000
long a[MAX+1];
long m,n,i,Count,k;
int main()
{
  //freopen("monkey.in","r",stdin);
  //freopen("monkey.out","w",stdout);
  cin>>m>>n;
  for(i=1;i<=m;i++)
    a[i]=1;
  k=m;//����ǰ��ָ��ñ�����ǰһֻ���� 
  for(i=1;i<=m;i++)//��ȦMֻ���� 
  {
    Count=0;//����ǰ������Ϊ0 
    while(Count<n)//��ǰ����<n���������� 
    {
      if(k==m)//����һ��λ���Ƶ���һ��λ�� 
        k=1;
      else
        k++;
      if(a[k]==1)//��ǰ������Ȧ�ڣ����� 
        Count++;
    }
    a[k]=0;//����K��Ȧ 
  }
  cout<<k<<endl;//���һֻ��Ȧ���Ǵ��� 
  return 0;
}
