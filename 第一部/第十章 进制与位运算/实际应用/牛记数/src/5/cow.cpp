//ţ����4
#include <iostream>
using namespace std;
int s,t;
int bit[1<<16];//bit[65536]

int main()
{
  freopen("cow.in","r",stdin);
  freopen("cow.out","w",stdout);
  for(int i=0;i<65536;++i)//Ԥ���� 
  {
    int cc=0;
    for(int x=i;x>0;x/=2)
      cc+=x%2;
    bit[i]=cc;
  }      
  cin>>s>>t;
  int c=0;
  for(int i=s;i<=t;++i)
    c+=( bit[(i>>16)] + bit[(i & 0xffff)] )<=4;
  cout<<c<<endl;
  system("pause");
}
