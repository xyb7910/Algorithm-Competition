//����� 
#include <iostream>
using namespace std;

int main()
{
  int grade;//ע��˴������� 
  cin>>grade;
  switch(grade)  //�Ƚ�gradeֵ��gradeֵΪһ���ַ�
  {
    case 5:
      cout<<"����\n"; break; 
    case 4:
      cout<<"��\n";  break; 
    case 3:
      cout<<"����\n";  break; 
    case 2:
      cout<<"������\n";  break; 
    default:cout<<"̫�����\n"; // �˴����Բ���break���
  }
  system("pause");
  return 0;  
}
