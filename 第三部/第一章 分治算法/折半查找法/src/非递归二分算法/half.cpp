//�ǵݹ���۰���ҷ�
#include <iostream>
#include <cstdlib>
#define MAXN 10001
using namespace std;
int key,top,bot,mid,n,a[MAXN];

void half()//���ֲ��ҷ� 
{
  top=1;
  bot=n;
  while (top<=bot)
  {
    mid=(bot+top)/2;
    if (key==a[mid])//��������ҵ� 
    {
      cout<<mid<<endl;
      exit(0);
    }
    else if (key<a[mid])//ѡ���Ұ�� 
      bot=mid-1;
    else               //ѡ������ 
      top=mid+1;
  }
  cout<<-1<<endl;
}

int main () 
{
  freopen("half.in","r",stdin);
  freopen("half.out","w",stdout);  
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i]; 
  cin>>key;
  if (key<a[1] || key>a[n])
    cout<<-1<<endl;
  else  
    half();
  return 0;
}
