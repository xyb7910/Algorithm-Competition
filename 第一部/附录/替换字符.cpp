//�滻�ַ�
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s = "abcdefg";
  s.replace(2,3,"123456789");//������2��ʼ3���ֽڵ��ַ��滻��"123456789"  
  cout<<s<<endl;  //���Ϊab123456789fg
  cin.get();
}
