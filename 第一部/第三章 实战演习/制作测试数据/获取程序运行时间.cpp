/*
�������ƣ���ȡ��������ʱ�� 
����˵����Ӧ�ú���clock() 
*/ 
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
  clock_t time;//��������жϸó�������ȫ��ʱ�䣬��������time�� 
  time=clock();//��ĩ��ֱ�����clock()��ֵ���� 
  cout<<time<<endl;
  Sleep(1000);//����1�룬Sleep����ĸӦ��д 
  cout<<clock()-time<<"����"<<endl;
  system("pause");
  return 0;      
}
