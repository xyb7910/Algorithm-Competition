//ѭ������
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
int i,j,h,person,n;
int a[32+1][32+1];

int main()
{
  freopen("competition.in","r",stdin);
  freopen("competition.out","w",stdout);
  cin>>n;
  person=1;
  a[1][1]=1;
  h=1;
  for(i=1;i<=n;i++)
    person=person*2;
  do
  {
    for(i=1;i<=h;i++)
      for(j=1;j<=h;j++)
      {
        a[i][j+h]=a[i][j]+h;//�������ϽǷ���
        a[i+h][j]=a[i][j+h];//�������½Ƿ���
        a[i+h][j+h]=a[i][j];//�������½Ƿ���
      }
    h=h*2;
  }while(!(h==person));
  
  for(i=1;i<=person;i++)
  {
    for(j=1;j<=person;j++)
      cout<<setw(4)<<left<<a[i][j];
    cout<<"\n";
  }
  return 0;
}
