//ÇĞ¸î½ğÊô¹÷
#include<bits/stdc++.h>
using namespace std;
int n,k;
double l,r,mid,a[10005];

inline bool Try(double x)
{
  int count=0;
  for(int i=1; i<=n; i++)
    count+=floor(a[i]/x);
  return count>=k;
}

int main()
{
  freopen("cut.in","r",stdin);
  freopen("cut.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1; i<=n; i++)
    scanf("%lf",&a[i]),l=l<a[i]?l:a[i],r=r>a[i]?r:a[i];
  while(r-l>1e-6)
  {
    mid=(l+r)/2;
    Try(mid) ? l=mid:r=mid;
  }
  printf("%.2lf",floor(r*100)/100);
  return 0;
}
