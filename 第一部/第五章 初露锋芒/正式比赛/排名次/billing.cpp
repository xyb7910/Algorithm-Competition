//������
#include <iostream>
using namespace std;
#define n 10000
int i,j,mingci;
int a[n+1];

int main()
{
  freopen("billing.in","r",stdin);
  freopen("billing.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>a[i];
  for(i=1;i<=n;i++)
  {
    mingci=1;//�����iλͬѧ�ǵ�1�� 
    for(j=1;j<=n;j++)//������ͬѧ�Ƚϣ������Լ� 
      if(a[j]>a[i])//���гɼ����Լ��ߵģ����μ�1 
        mingci=mingci+1;
    cout<<a[i]<<' '<<mingci<<endl;
  }
  return 0;
}
