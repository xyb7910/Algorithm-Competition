//�����ַ�
#include <iostream>
using namespace std;

void reverse(int n)
{
  char next;
  if(n<=1)     //�ݹ�Ľ�������
  {
    next=getchar();//�Ӽ��̻��һ���ַ�
    printf("\n");
    putchar(next);//��Ϊֻʣ���һ���ַ��ˣ���������ֱ�Ӵ�ӡ����
  }
  else
  {
    next=getchar();//�Ӽ��̻��һ���ַ�
    reverse(n-1);  //�ݹ�����������һ���ַ�
    putchar(next);//ֻ�еȵ�n-1���ַ�������ӡ�󣬸��ַ��ű���ӡ
  }
}

int main()
{
  int i=5;
  reverse(i);
  system("pause");
}
