//��ά���������������ά��������Ԫ��ֵ
# include <iostream>
using namespace std;

int Max(int a[][4]) //�β��������������Ϊ��
{
  int i,j,Max;
  Max=a[0][0];
  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
       if(a[i][j]>Max)
         Max=a[i][j];
  return Max;  
}

int main()
{
  int a[][4]={1,2,3,4,5,6,7,8,9,-1,-2,-3};//�˴���ʡ�Ե�һά��ֵ��С 
  cout<<"���ֵΪ "<<Max(a)<<endl; //������������
  system("pause");
  return 0;
}
