//�ݹ�������
# include <iostream>
using namespace std;

int age(int n)
{
  int c;
  if(n==1)  //�ݹ����������
    return 10;
  else 
     c=age(n-1)+2; //��������
  return c;
}

int main()
{
  cout<<age(5)<<' ';
  system("pause");
  return 0; 
}
