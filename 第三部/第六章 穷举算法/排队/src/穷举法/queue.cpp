/*
�������ƣ���ţ�Ŷ� 
*/ 
#include <iostream>
using namespace std;
int a[30001],i,n,num,minx;

int main()
{
  freopen("queue.in","r",stdin);
  freopen("queue.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>num;
    a[i]=a[i-1]+num-1;//a[i]��ʾ�ӵ�1ͷ����iͷ���Ϊ2����ţ���� 
  }
  minx=n;
  for(i=0;i<=n;i++) //���i��λ�� 
    if(minx>a[i]+n-i-(a[n]-a[i]))//��1~iͷ��ţ���ȫ��Ϊ���1��
        minx=a[i]+n-i-(a[n]-a[i]);//��i+1~nͷ��ţȫ��Ϊ���2 
  
  if(n==a[i])//���ȫΪ2������ı� 
    minx=0;
  cout<<minx<<endl;
  return 0;             
}
