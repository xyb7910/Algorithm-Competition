#include <bits/stdc++.h>
using namespace std;

inline int read()//���ַ�����ʽ�������ֿ�����
{
  int x=0,f=1;//fΪ�Ƿ������
  char c=getchar();
  while(c<'0' || c>'9')
  {
    if(c=='-') f=-1;
    c=getchar();
  }
  while(c<='9' && c>='0')
  {
    x=(x<<3)+(x<<1)+c-'0';//λ�����Ż���x*8+x*2=x*10
    c=getchar();
  }
  return x*f;
}

const int N = 50400;
int n,ans;
int t[N],a[N],b[N];

inline void add(int x)//inline��ʾ��������,������
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
  int size=unique(a+1,a+n+1)-a-1;//uniqueȥ�أ���ֵͬ���ص����棩 
  for(int i=1; i<=n; i++)
    b[i]=upper_bound(a+1,a+size+1,b[i])-a-1;//�����a[]����b[i]�Ĳ���λ�� 
  for(int i=1; i<=n; i++)
  {
    add(b[i]);//�˴�ʹ���˱�Ž�����ɢ������
    ans+=i-getnum(b[i]);
  }
  printf("%d\n",ans);
  return 0;
}

