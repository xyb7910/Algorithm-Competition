//�ж��ַ����Ƿ�Ϊ��
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s ; 
  if (s.empty())
    cout<<"s Ϊ��."<<endl;  
  else 
    cout<<"s ��Ϊ��."<<endl;

  s = s + "abcdefg";
  if (s.empty())
    cout<<"s Ϊ��."<<endl;
  else   
    cout<<"s ��Ϊ��."<<endl;
  cin.get();
}
