//��������Ż�һ
#include <iostream>
using namespace std;
int a[3][3],b[3][3];

int main()
{
    int i,tx,ty;
    int x=0,y=1;
    a[0][1]=1;//��1���ڵ�0�е�1�� 
    for(i=2;i<=9;i++)//���η�2->9 
    {
        tx=(x+2)%3;
        ty=(y+1)%3;
        if(a[tx][ty]==0)//���б�Ϸ�δ������ 
        {
          a[tx][ty]=i;//xΪ�У�yΪ��
          x=tx;
          y=ty;
        }
        else//�����������·� 
        {
          x=(x+1)%3; 
          a[x][y]=i;
        }   
    }
  for(i=0;i<=3;i++)
  {
    cout<<a[0][0]<<a[0][1]<<a[0][2]<<endl;
    cout<<a[1][0]<<a[1][1]<<a[1][2]<<endl;
    cout<<a[2][0]<<a[2][1]<<a[2][2]<<endl;        
    cout<<endl;
    cout<<a[2][0]<<a[2][1]<<a[2][2]<<endl; //���·�ת 
    cout<<a[1][0]<<a[1][1]<<a[1][2]<<endl;
    cout<<a[0][0]<<a[0][1]<<a[0][2]<<endl;
    cout<<endl;     
    
    for(int ii=0;ii<3;ii++)//������������b������ת 
      for(int jj=0;jj<3;jj++)
        b[jj][2-ii]=a[ii][jj];
    for(int ii=0;ii<3;ii++)
      for(int jj=0;jj<3;jj++)
        a[ii][jj]=b[ii][jj];    
  }
  system("pause");
  return 0;
}
