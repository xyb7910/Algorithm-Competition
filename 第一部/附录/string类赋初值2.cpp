// string�ำ��ֵ
#include <string> 
#include <iostream>
using namespace std;

int main()  
{ 
  string s(10,'k');    //����10���ַ�,��ֵ����'k'  
  cout<<s<<endl; 
  s = "hehehehe";  //���¸�ֵ,sֵΪhehehehe 
  cout<<s<<endl; 
  s.assign("kdje");//����ֵ,sֵΪkdje 
  cout<<s<<endl;
  s.assign("fkdhfkdfd",5);//���·���ָ���ַ�����ǰ5��Ԫ������,��sֵΪfkdhf 
  cout<<s<<endl; 
  cin.get();
}
