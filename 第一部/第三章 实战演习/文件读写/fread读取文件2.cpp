//fread��ȡ�ļ�2
#include <iostream>
using namespace std;
FILE *in=fopen("i.txt","rb");
int mark=0;
char a[10];

int getnum()//��char����ת��Ϊint����
{
    int obj=0;
    while(!(a[mark]>='0' && a[mark]<='9'))
      mark++;
    while(a[mark]>='0' && a[mark]<='9')
        obj=obj*10+a[mark++]-'0';
    return obj;
}

int main()
{
  freopen("p.txt","w",stdout); //�ļ����
  int s=1,i;
  fread(a,6,1,in); //�ڶ��������������������С���������þͺ�
  for(i=0;i<3;i++)
    s*=getnum();
  cout<<s<<endl;
  return 0;
}
