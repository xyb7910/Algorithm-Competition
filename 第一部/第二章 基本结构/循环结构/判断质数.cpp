//�ж�����
# include <iostream>
# include <math.h>
using namespace std;

int main()
{
  int number,i,k;
  cin>>number;
  k=sqrt(number); //kΪ��������ƽ����,��һ��Ϊʲô�� 
  for(i=2;i<=k;i++) //���������ô�2��k��һ��һ������������
    if(number%i==0) 
      break;  //ֻҪ�ܱ�������������forѭ��
  if(i>k)  
    cout<<number<<"��һ������\n";
  else
    cout<<number<<"����һ������\n";
  system("pause");
  return 0;  
}
