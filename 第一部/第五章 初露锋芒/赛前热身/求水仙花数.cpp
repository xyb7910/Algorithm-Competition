//��ˮ�ɻ���
#include <iostream>
using namespace std;

int main()
{
  int i,j,k,n;
  for(n=100;n<1000;n++)
  {
     i=n/100;       //ȡ��λ��
     j=n/10-i*10;    //ȡʮλ��
     k=n%10;        //ȡ��λ��
     if(i*100+j*10+k==i*i*i+j*j*j+k*k*k)
       cout<<n<<' ';                  
  }              
  system("pause");
  return 0;        
}
