/*最优分解
贪心算法。如果a+b=n，则|a-b|越小，那么a*b越大，可以将n分解成从2开始的连续自然数的和。
例如：输入n=10，则可以分解为 2、3、4，还剩下1不够5，把这个1倒着加，4 -> 5。
所以，最终分解为2,3,5，结果为2*3*5=30。
*/
#include <bits.stdc++.h>
using namespace std;

int a[100];//保存分解后的数

int Fun(int n)
{
  int k=1;//k指向a[]下标
  a[1]=2; //从下标1开始
  n-=2;//先减2
  while(n>a[k])   //循环减
  {
    k++;
    a[k]=a[k-1]+1;
    n-=a[k];
  }
  if(n==a[k]) //相等，最后的再加1
  {
    a[k]++;
    n--;
  }
  for(int i=0; i<n; i++) //以10为例，这里n=1，然后每个元素+1
    a[k-i]++;
  int sum=1;
  for(int i=1; i<=k; i++) //从1开始
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

