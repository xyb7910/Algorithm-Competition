//��°ͺղ���
#include<iostream>
#include<math.h>
using namespace std;

int fflag(int i)           /*�ж��Ƿ�Ϊ����*/
{
  int j;
  if(i<=1)
    return 0;
  if(i==2)
    return 1;
  if(!(i%2))//�����ż�� 
    return 0;     
  for(j=3;j<=(int)(sqrt((double)i)+1);j+=2)
    if(!(i%j))
      return 0;
  return 1;      /*���������,return 1*/
}

int main()
{
  int i,n;
  for(i=4;i<=2000;i+=2)
  {
    for(n=2;n<i;n++)   /*��ż��i�ֽ�Ϊ��������*/
      if(fflag(n))     /*�ֱ��ж����������Ƿ��Ϊ����*/
        if(fflag(i-n))
        {
          cout<<i<<"="<<n<<"+"<<i-n<<endl;/*���������������*/
          break;
        }
      if(n==i)  
        cout<<"error %d\n";
  }
  system("pause");
  return 0;
}
