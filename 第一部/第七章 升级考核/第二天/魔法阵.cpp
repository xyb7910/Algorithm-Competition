//ħ���� 
#include<iostream>
#include<cmath>
using namespace std;

int main()
{	
  double data[3][2];	
  double a[3],p;//�洢�����ߵĳ��ȡ�	
  int i;	
  for(i=0;i<3;i++)	
  {		
    cout<<"�������"<<i+1<<"����"<<endl;		
    cin>>data[i][0]>>data[i][1];	
  }	
  p=pow(data[0][0]-data[1][0],2)+pow(data[0][1]-data[1][1],2);	
  a[0]=sqrt(p);	
  p=pow(data[0][0]-data[2][0],2)+pow(data[0][1]-data[2][1],2);	
  a[1]=sqrt(p);	
  p=pow(data[1][0]-data[2][0],2)+pow(data[1][1]-data[2][1],2);	
  a[2]=sqrt(p);	
  //�ж��ܷ񹹳�������	
  if(a[0]+a[1]<=a[2]||a[0]+a[2]<=a[1]||a[1]+a[2]<=a[0]) 
    return 0;	
  //���ú��׹�ʽ��s=sqr(p*(p-a)(p-b)(p-c));	
  p=(a[0]+a[1]+a[2])/2;	
  double s=sqrt(p*(p-a[0])*(p-a[1])*(p-a[2]));	
  cout<<"�����:"<<s<<endl;	
  system("pause");
  return 0;
}
