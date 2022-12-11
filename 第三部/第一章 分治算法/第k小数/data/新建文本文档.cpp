//第k小数
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int x,num;
} a[100001];

int m,k;

void Swap(int i,int j)
{
  swap(a[i].x,a[j].x);//两元素互换
  swap(a[i].num,a[j].num);
  swap(i,j);//指针互换
}

void Operation(int START,int END)
{
  int i=START;
  int j=END;
  while(i!=j)//当指针未重合时
  {
    if(i<j)//如i指针在j指针左
    {
      if(a[i].x>a[j].x)
        Swap(i,j);
      else
        --j;//j指针左移
    }
    else//如i指针在j指针右（指针已互换）
    {
      if(a[i].x<a[j].x)
        Swap(i,j);
      else
        ++j;//j指针右移
    }
  }
  if(i<k) //此时i和j已重合
    Operation(i+1,END);//取右边数组递归查找
  else if(i==k)//若已找到第k小数
  {
    cout<<a[i].num<<"\n";//输出答案即原位置
    return;
  }
  else
    Operation(START,i-1);//取左边数组递归查找
}

int main()
{
  freopen("K17.in","r",stdin);
  freopen("K17.txt","w",stdout);
  scanf("%d%d",&m,&k);
  for(int i=1; i<=m; i++)
  {
    scanf("%d",&a[i].x);
    a[i].num=i;
  }
  Operation(1,m);//在1~m之间开始二分查找
  return 0;
}

