//freopen��ʽ��д�ļ� 
#include <iostream>
#include <cstdlib>//���бؼӣ�����linux�¿��ܳ����� 
using namespace std;
int main()
{
  int a,b;  
  freopen("sum.in","r",stdin); //��sum.in�ж�ȡ����
  freopen("sum.out","w",stdout);//�����sum.out�ļ�
  cin>>a>>b;
  cout<<a+b<<endl;
  //system("pause"); һ��Ҫ���˾�ע�͵� 
  return 0;
}
