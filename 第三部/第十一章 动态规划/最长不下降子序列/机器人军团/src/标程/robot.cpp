//�����˾���-�����㷨
#include <iostream>
#include <cstdlib>
using namespace std;

int n,longest ;
int a[10001],dp[10001] ;

int main()
{
//  freopen("robot.in","r",stdin);
//  freopen("robot.out","w",stdout);
  cin >> n ;
  longest = 1 ;
  for (int i=1 ; i<=n ; i++)//��ʼ��
  {
    cin >> a[i] ;
    dp[i] = 1 ;
  }
  for (int i=2 ; i<=n ; i++ )//˳��ԭ��һ��
  {
    for (int j=1 ; j<i ; j++)
      if(a[i]>a[j])
        dp[i] = max (dp[j]+1 , dp[i]) ;
    longest = max (dp[i],longest) ;
  }
  cout << longest << endl;
  return 0;
}
