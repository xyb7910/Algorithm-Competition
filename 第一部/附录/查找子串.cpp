//�����Ӵ�
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s = "abcdefg1111"; 
  string pattern = "fg";
  int pos = s.find(pattern,0);      //������0��ʼ,���ҷ����ַ���"f"��ͷ���� 
  cout<<pos<<endl; //���5 
  string str = s.substr(pos,pattern.size());  //�Ӵ� 
  cout<<str<<endl;//���fg 
  cin.get();
}
