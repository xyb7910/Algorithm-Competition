//��13��13�η��������λ��
#include<iostream>
using namespace std;

int main()
{
  int i,x,y,last=1;    /*����last����˻��ĺ���λ*/
  cin>>x>>y;
  for(i=1;i<=y;i++)    /*X�Գ�Y��*/
    last=last*x%1000;  /*��last��X���1000ȡģ��������ĺ���λ*/
  cout<<last%1000<<endl; /*��ӡ���*/
  system("pause");
  return 0;
}
