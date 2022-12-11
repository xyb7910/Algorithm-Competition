#include <bits/stdc++.h>
using namespace std;

inline int read()//以字符串形式读入数字可提速
{
  int x=0,f=1;//f为是否负数标记
  char c=getchar();
  while(c<'0' || c>'9')
  {
    if(c=='-') f=-1;
    c=getchar();
  }
  while(c<='9' && c>='0')
  {
    x=(x<<3)+(x<<1)+c-'0';//位运算优化即x*8+x*2=x*10
    c=getchar();
  }
  return x*f;
}

const int N = 50400;
int n,ans;
int t[N],a[N],b[N];

inline void add(int x)//inline表示内联函数,可提速
{
  while(x<=n)
    t[x]++,x+=x&(-x);
}

inline int getnum(int x)
{
  int val=0;
  for(int k=x; k>0; k-=k&(-k))
    val+=t[k];
  return val;
}

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  n=read();
  for(int i=1; i<=n; i++)
    a[i]=read(),b[i]=a[i];
  sort(a+1,a+n+1);
  int size=unique(a+1,a+n+1)-a-1;//unique去重（相同值隐藏到后面） 
  for(int i=1; i<=n; i++)
    b[i]=upper_bound(a+1,a+size+1,b[i])-a-1;//升序的a[]中找b[i]的插入位置 
  for(int i=1; i<=n; i++)
  {
    add(b[i]);//此处使用了编号进行离散化操作
    ans+=i-getnum(b[i]);
  }
  printf("%d\n",ans);
  return 0;
}

