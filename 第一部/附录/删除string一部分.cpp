//ɾ��string�е�һ����
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s = "abcdefg";
  s.erase(0,1);    //������0��ʼɾ��ɾһ���ַ�,��ɾ������'a' 
  cout<<s<<endl;
  s.replace(2,3,"");//��replace������ִ��ɾ��,����ָ����Χ�ڵ��ַ��滻��""
  cout<<s<<endl; 
  cin.get();
}
