//��ά������к���Ԫ�ػ���
#include <iostream>
using namespace std;

int main()
{
  int a[2][3]={{1,2,3},{4,5,6}};
  int b[3][2],i,j;
  cout<<"a����Ԫ��Ϊ��"<<endl;
  for(i=0;i<=1;i++)//��ӡa��Ԫ��
  {
     for(j=0;j<=2;j++)
     {
        cout<<a[i][j]<<"  ";
        b[j][i]=a[i][j];//Ԫ�����л���
     }
     cout<<endl;
  }
  cout<<"b����Ԫ��Ϊ��\n";
  for(j=0;j<=2;j++)  //��ӡb��Ԫ��
  {
    for(i=0;i<=1;i++)
      cout<<b[j][i]<<"  ";
    cout<<endl;
  }
  system("pause");
  return 0;
} 
