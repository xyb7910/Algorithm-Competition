//�����ַ���
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s = "abc";
  s.insert(0,"ͷ��");            //��ͷ������
  s.insert(s.size(),"β��");    //��β������
  s.insert(s.size()/2,"�м�");//���м����
  cout<<s<<endl;
  cin.get();
}
