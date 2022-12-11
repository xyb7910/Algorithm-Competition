//危险的神器
#include<bits/stdc++.h>
using namespace std;
int U[1000005];
int n,p;

bool Check(int x)
{
  int num=0;
  int l=U[1];             //l记录上一神器的位置，第一个神器先放在第一个坐标
  for(int i=2; i<=n; i++) //依次枚举每个坐标
  {
    if(U[i]-l<x)
      num++;              //若此距离不满足当前答案，把当前神器放到下一个坐标
    else l=U[i];          //否则就更新上一次的神器位置
    if(num>n-p)           // 若需要坐标数大于最大坐标数
      return false;       //此答案不可行
  }
  return true;            //反之，答案可行
}
int main()
{
  scanf("%d%d",&n,&p);
  for(int i=1; i<=n; i++)
    scanf("%d",&U[i]);
  sort(U+1,U+n+1);
  int l=1;
  int r=U[n]-U[1];
  while(l+1<r)
  {
    int mid=(l+r)/2;
    Check(mid)?l=mid:r=mid;
  }
  Check(r)?printf("%d",r):printf("%d",l);
  return 0;
}
