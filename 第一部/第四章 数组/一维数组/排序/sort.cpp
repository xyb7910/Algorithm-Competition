#include <iostream>
using namespace std;
#define N 100000+1
int i,j,n,temp,lastchange;
int a[N+1];

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>a[i];
    
  i=2;//�������ǰ�Ƚϣ���ʼ��ǰ���λ�ã���n��i�����ֱ���ǰһ�����Ƚ� 
  while((i<n))
  {
    lastchange=n;//���趨��һ��ɨ����󽻻�λ��Ϊn 
    for(j=n;j>=i;j--)//�Ӻ���ǰɨ�� 
      if(a[j]<a[j-1])//����ǰ����ں���ģ�С���ϸ�������ס����λ��j 
      {
        a[j]=a[j]^a[j-1];//��ʵ���������˴��õ���λ���� 
        a[j-1]=a[j-1]^a[j];
        a[j]=a[j]^a[j-1];
        lastchange=j;
      }
    i=lastchange;//��һ�֣�ֻ��Ҫ�����Ƚϵ���һ����󽻻���λ��lastchange 
  } 
  for(i=1;i<n;i++)//��� 
    cout<<a[i]<<' ';
  cout<<a[n]<<'\n';  
  return 0;
}
