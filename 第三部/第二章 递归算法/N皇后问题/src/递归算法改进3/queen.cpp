#include <iostream>
#define odd(num)  (num&1)/*�����ж���Ͷ�����λ�ķ���*/
using namespace std;

int a[20+1];
char x1[40+1];
char x2[40+1];
int next[20+1];//�������� 
long total,num;
int n,head;

void place(int x,int y)
{
  int i,pre;
  if(x==n+1)
    total++;
  else
  {
    i=next[0];
    pre=0;
    while((i>0)&&(i<=y))
    {
      if((!x1[x+i]) &&(!x2[x-i+n]))
      {
          x1[x+i]=1;
          x2[x-i+n]=1;
          next[pre]=next[i];
          a[x]=i;
          if((x==1)&& odd(n)&& (a[1]==(n+1)/2))
            place(2,n/2-1);
          else
            place(x+1,n);
          x1[x+i]=0;
          x2[x-i+n]=0;
          next[pre]=i;
      }
      pre=i;
      i=next[i];
    }
  }
}
int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  cin>>n;
  total=0;
  num=0;

  for(head=0;head<=n-1;head++)
    next[head]=head+1;//ÿ����㶼ָ����һ����㣬���һ��ָ��0 
  place(1,(n+1)/2);
  cout<<total*2<<endl;
  return 0;
}
