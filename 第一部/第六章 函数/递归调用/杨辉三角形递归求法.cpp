//��������εݹ���
#include<iostream>
#include <iomanip>
using namespace std;/*�ӵ�0�п�ʼ*/
int c(int x,int y)/*������������е�x�е�y�е�ֵ*/
{   
   int z;
   if((y==1)||(y==x+1))
      return 1; /*��Ϊ��б�ߣ������1*/
   z=c(x-1,y-1)+c(x-1,y);/*������ֵΪǰһ���е�y-1�����y��ֵ֮��*/
   return z;
}

int main()
{
   int i,j,n=13;
   while(n>12)/*��֤�����ֵ������12�Ա�����ĻЧ��*/
   { 
      cout<<"������n��ֵ:";
      cin>>n;
   }
   for(i=0;i<=n;i++)/*�������n��*/
   {
       for(j=0;j<24-2*i;j++)
         cout<<" ";/*���������i��ǰ��Ŀո�*/
       for(j=1;j<i+2;j++)
          cout<<setw(5)<<c(i,j);/*�����i�еĵ�j��ֵ*/
       cout<<endl;
   }
   system("pause");
}
