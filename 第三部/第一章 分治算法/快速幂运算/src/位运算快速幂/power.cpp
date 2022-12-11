//位优化快速幂运算
#include <bits/stdc++.h>
using namespace std;

long long Pow(long long x, long long n)
{
  long long result=1;
  if (n == 0)
    return 1;
  else
    while (n != 0)
    {
      if (n & 1)
        result *= x;
      x *= x;
      n >>= 1;
    }
  return result;
}

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  long long x,n;
  cin>>x>>n;
  cout<<Pow(x,n)<<endl;
  return 0;
}
