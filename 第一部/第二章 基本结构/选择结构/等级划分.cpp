//�ȼ����� 
#include <iostream>
using namespace std;

int main()
{
  char grade;//ע��˴����ַ��� 
  cin>>grade;
  switch(grade)  //�Ƚ�gradeֵ��gradeֵΪһ���ַ�
  {
    case 'A':
      cout<<"����\n"; break; 
    case 'B':
      cout<<"��\n";  break; 
    case 'C':
      cout<<"����\n";  break; 
    case 'D':
      cout<<"������\n";  break; 
    default:cout<<"̫�����\n"; // �˴����Բ���break���
  }
  system("pause");
  return 0;  
}
