//��д�ļ�����3 
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
  int a,b,c;  
  ifstream fin("in.txt");
  ofstream fout("out.txt");
  fin>>a>>b>>c;
  fout<<a*b*c<<endl;//ע��cin��cout�ı仯
  fin.close();
  fout.close();
  return 0;
}
