//���ļ��� 
#include <iostream>
using namespace std;

int ans[1001];
int i,n;

void count(int m)
{
  int i;
  if(ans[m]!=-1)//������ֵ������ݹ飬ֱ������ 
    return;
  ans[m]=1;
  for(i=1;i<=m/2;i++)
  {
    count(i);
    ans[m]+=ans[i];
  }
}

int main()
{
  freopen("people.in","r",stdin);
  freopen("people.out","w",stdout);    
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    ans[i]=-1;
  count(n);
  printf("%d\n",ans[n]);
  return 0;
}
