//���ı���
#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
  char c;
  while((c=getchar())!='\n')
  {
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))//���ַ�ΪӢ����ĸʱ
    {
      c=c+4;
      if(c>'Z' && c<='Z'+4 || c>'z')  
        c=c-26;
    }
    cout<<c;
  }
  system("pause");
  return 0;
}
