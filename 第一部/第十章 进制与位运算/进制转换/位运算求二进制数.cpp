//λ�������������
#include <iostream>
using namespace std;

int main()
{
  int number,i,j,m,ok=0;
  int s[50];
  memset(s,0,sizeof(s));//����������Ԫ�س�ʼ��Ϊ0
  cin>>number;
  for(i=1;i<=32;i++)  //32λ�ı����� 
  {
    m=number>>(i-1)&1;//��ÿһλ�Ƶ����Ҷ���1���������� 
    s[i]=m;
  }
  for(i=49;i>=1;i--)//������� 
  {
    if(ok==0 && s[i]==1)//����ǰ���0 
      ok=1;
    if(ok==1)  
      cout<<s[i]; 
  }     
  system("pause");     
}
