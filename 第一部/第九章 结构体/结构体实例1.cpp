# include <iostream>
using namespace std;

struct student
{
  int num;
  char name[20];
  char sex;
  int age;
  float score;
  char addr[50];
}a={10001,"������",'M',16,95.0,"����·134��"},//ע��˴�Ϊ����
 b={10002,"���̹�",'F',16,92,"�Ž�·66��"};//����Ϊ�ֺ�
 
int main()
{
  cout<<a.num<<a.name<<a.sex<<a.age<<a.score<<a.addr<<endl;     
  cout<<b.num<<b.name<<b.sex<<b.age<<b.score<<b.addr<<endl;    
}
