//���캯��3
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  string temp="1010111100";
  bitset<10> bin(temp);
  for(int i=0;i<=9;i++)
    cout<<bin[i];//��ӡ��0011110101��ע�⣬�Ǵ���������������� 
  system("pause");
}
