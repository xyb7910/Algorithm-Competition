//�������е������
#include <iostream>
using namespace std;

int Max(int a,int b) //MaxΪһ���Ӻ���
{
  if(a>b)
    return a; //����ֵΪa
  else 
    return b; //����ֵΪb
}

int main()
{
  int x,y;
  cin>>x>>y;
  cout<<Max(x,y)<<endl;//�˴�������max�������������x,yֵ���ݸ���Max������
  system("pause");
} 
