//������������εĵݹ��� 
#include <iostream>
using namespace std;

void trangle(char c,int n)
{  
  if(n>0)
  {
    cout<<c;
    trangle(c,n-1);
  }   
}

int main()
{
  int n,i;
  cin>>n;
  for(i=1;i<=n;++i)
  {
    trangle(' ',n-i);//����ո� 
    trangle('*',2*i-1);//����Ǻ� 
    cout<<endl;
  }
  system("pause");
}
