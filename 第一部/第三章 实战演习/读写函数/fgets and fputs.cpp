//fgets and fputs
#include <iostream>
using namespace std;

int main()
{
  FILE *in=fopen("i.txt","rb");//�����ļ�����ָ��
  FILE *out=fopen("o.txt","wb");//�����ļ����ָ��
  char a[9];
  fgets(a,10,in);
  fputs(a,out);
}
