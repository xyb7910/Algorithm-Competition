//�������ַ��� 
#include <iostream>
using namespace std;
const int N=100;
	
int main()
{
  char str1[N],str2[N];
  int i,len;
  puts("�����ַ�����");
  gets(str1);
  puts("�������");
  len=strlen(str1);
  for(i=len-1;i>=0;i--)
    str2[len-i-1]=str1[i];
  str2[len]='\0';
  puts(str2);
  system("pause");
  return 0;
}
