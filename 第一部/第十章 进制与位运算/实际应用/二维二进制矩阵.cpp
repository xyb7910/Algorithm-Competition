//��ά�����ƾ���
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int x,y,m,n,u,temp;
  cin>>m>>n;
  for(x=0;x<=((1<<m)-1);x++)
  {  u=(x^(x>>1))<<n;//������������һ��mλ��Gray��
    for(y=0;y<=((1<<n)-1);y++)
    {
      temp=u|(y^(y>>1));//����һ��nλGray��
      cout<<setw(4)<<temp;
    }
    cout<<endl;
  }    
  system("pause");
}
