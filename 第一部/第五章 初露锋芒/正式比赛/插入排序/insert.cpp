//����������,���Լ����������޸� 
#include <iostream>
using namespace std;

int main()
{
  int a[11]={1,4,6,9,13,16,19,28,40,100};
  int temp1,temp2,number,end,i,j;
  cin>>number;
  if(number>a[9])
    a[10]=number;
  else
  {
     for(i=0;i<10;i++)//��������ɨ�� 
     {
       if(a[i]>number)//�ҵ��Ȳ����������ʱ 
       {
         temp1=a[i];//���������ݴ浽temp1 
         a[i]=number;//�Ѳ��������� 
         for(j=i+1;j<11;j++)//����������κ��� 
         {
           temp2=a[j];//����ʱ���Ƚ�a[j]��ֵ�ݴ浽temp2 
           a[j]=temp1;//������ 
           temp1=temp2;//temp2��ֵ�浽temp1,������һ�εĲ��� 
         }    
         break;
        }
     }
  }
  for(i=0;i<11;i++)
    cout<<a[i]<<' ';    
  return 0;      
}           
