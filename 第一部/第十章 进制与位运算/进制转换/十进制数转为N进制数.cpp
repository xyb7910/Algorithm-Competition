/*
�������ƣ�ʮ������ת��ΪN������
����˵�������ó�N����ȡ��ķ�ʽ��ע����������0�Ĵ���
*/ 
#include <iostream>
using namespace std;

string fun(int x,int n)
{
  const string a="0123456789ABCDEF";
  string s="";
  if(x==0)
    return "0";
  while(x>0)
  {
    s=a[x%n]+s;//��ȡ����������ǰ�� 
    x=x/n;
  }
  return s;
}

int main()
{ 
  int x,n;
  cin>>x>>n;
  cout<<fun(x,n)<<endl;
}
