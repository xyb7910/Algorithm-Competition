//С��������
#include <iostream>
using namespace std;
#define N 100000
int a[N+1];

void adjust_down(int i,int m)//���� 
{
  int x;
  while(i*2<=m)
  {
    i=i*2;
    if((i<m)&&(a[i+1]>a[i]))//������ֵ� 
      i++;
    if(a[i]>a[i/2])
    {
      x=a[i/2];
      a[i/2]=a[i];
      a[i]=x;
    }
    else
      break;
  }
}

int main()
{
  int n,i;
  cin>>n;
  for(i=1;i<=n;i++)
    cin>>a[i];
    
  for(i=n/2;i>=1;i--)//ֻ�����һ�뼴�� 
    adjust_down(i,n);//���� 
  for(i=n;i>=2;i--)
  {
    a[i]=a[i]^a[1];//���� 
    a[1]=a[1]^a[i];
    a[i]=a[i]^a[1];
    adjust_down(1,i-1);
  }
  for(i=1;i<=n;i++)
    cout<<a[i]<<' ';
  return 0;
} 
