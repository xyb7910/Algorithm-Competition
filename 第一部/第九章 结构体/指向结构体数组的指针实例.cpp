//ָ��ṹ�������ָ��ʵ�� 
# include <iostream>
using namespace std;

struct student
{
  int num;
  char name[20];
  char sex;
  float score;
};
struct student stu[2]={{10001,"������",'M',95.0},
 {10002,"���̹�",'F',92}};//����Ϊ�ֺ�

int main()
{
 struct student *p;
 for(p=stu;p<stu+2;p++)//pΪָ��ṹ���ָ�룬����ӣ���ָ����һ���ṹ��Ԫ��
  cout<<p->num<<p->name<<p->sex<<p->score<<endl;     
}
