/*���ŷֽ�
̰���㷨�����a+b=n����|a-b|ԽС����ôa*bԽ�󣬿��Խ�n�ֽ�ɴ�2��ʼ��������Ȼ���ĺ͡�
���磺����n=10������Էֽ�Ϊ 2��3��4����ʣ��1����5�������1���żӣ�4 -> 5��
���ԣ����շֽ�Ϊ2,3,5�����Ϊ2*3*5=30��
*/
#include <bits.stdc++.h>
using namespace std;

int a[100];//����ֽ�����

int Fun(int n)
{
  int k=1;//kָ��a[]�±�
  a[1]=2; //���±�1��ʼ
  n-=2;//�ȼ�2
  while(n>a[k])   //ѭ����
  {
    k++;
    a[k]=a[k-1]+1;
    n-=a[k];
  }
  if(n==a[k]) //��ȣ������ټ�1
  {
    a[k]++;
    n--;
  }
  for(int i=0; i<n; i++) //��10Ϊ��������n=1��Ȼ��ÿ��Ԫ��+1
    a[k-i]++;
  int sum=1;
  for(int i=1; i<=k; i++) //��1��ʼ
    sum*=a[i];
  return sum;
}

int main()
{
  freopen("unpack.in","r",stdin);
  freopen("unpack.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%d\n",Fun(n));
  return 0;
}

