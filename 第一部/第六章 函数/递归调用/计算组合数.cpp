//combination.cpp���������c(m,n)�ĵݹ��� 
#include <iostream>
using namespace std;

int combin(int m,int n)
{
  int com;
  if (n<2*m)
    m=n-m;
  if (m==0) 			/*��ֹ�ݹ���õ�����*/
    com=1;
  else if (m==1)
    com=n;
  else
    com=combin(m,n-1)+combin(m-1,n-1);	/*�ݹ����*/
  return com;							/*����ֵΪcom*/
}

int main() 
{ 
  int m,n;
  cin>>m>>n;//����4 7 ���Ϊ35 
  cout<<combin(m,n)<<endl;	
  system("pause");
} 
