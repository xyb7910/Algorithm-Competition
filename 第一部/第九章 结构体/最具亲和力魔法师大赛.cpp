//����׺���ħ��ʦ���� 
# include <iostream>
using namespace std;

struct person
{
  char name[20];//����
  int count;//��Ʊ��
}leader[3]={"Mike",0,"John",0,"Smith",0};//��ʼ����ѡ��

int main()
{
  int i,j;
  char name[20];  //�˴��ı���name��ṹ�����name������ͻ
  for(i=1;i<=10;i++)
  {
    cin>>name;
    for(j=0;j<3;j++)
       if(strcmp(name,leader[j].name)==0)//�����������ѡ�������Ƚ�
          leader[j].count++;        //��Ʊ����1
  }
  cout<<endl;
  
  for(i=0;i<3;i++)
      cout<<leader[i].name<<" "<<leader[i].count<<" "; //��ӡͳ�ƽ��
}
