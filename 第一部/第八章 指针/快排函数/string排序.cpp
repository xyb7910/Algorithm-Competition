//string���� 
#include <iostream>
using namespace std;

int cmp(const void *a,const void *b)//��������
{
  return strcmp((*(string*)a).data(),(*(string*)b).data());//������ 
  //return strcmp((*(string*)b).data(),(*(string*)a).data());//������ 
}

int main()
{
  string *str=new string[10];//string����
  for(int i=0;i<10;i++)
    cin>>str[i];
  qsort(str,10,sizeof(string),cmp);
  //qsort(&str[3],5,sizeof(str[3]),cmp);//�Բ������� 
  cout<<endl;
  for(int i=0;i<10;i++)
    cout<<str[i]<<endl;
  system("pause");  
}
