//fin.get()ʹ�� 
#include <iostream>
#include<fstream>
using namespace std;
int main()
{  
  int a,b,c,space;
  ifstream fin("in.txt");  //������ʽ��a b c
  ofstream fout("out.txt");  //���������λ���Ļ�
  a=fin.get()-'0'; //�ر�ע��ú����ǻ�ȡһ���ַ������ո��
  space=fin.get();
  b=fin.get()-'0';
  space=fin.get();
  c=fin.get()-'0';
  fout<<a*b*c;
  fin.close();
  fout.close();
  return 0;
}
