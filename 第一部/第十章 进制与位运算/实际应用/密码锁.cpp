//������
#include <iostream>
using namespace std;

int main()
{
  char a[9];//�洢��λ��3��������a[0]Ϊ��ֹ��� 
  int i,j,N,s;
  char fuhao[3]={'+','-','*'};
  bool f=0;//�Ƿ��н�ı�� 
  memset(a,0,sizeof(a));
  cin>>N;
  while(a[0]!=1)//�����λΪ1ʱ����˵��������������Ϊ3������� 
  {
    s=1;
    for(i=1;i<=8;i++)//����˸���������������a[i]���� 
    {
      if(a[i]==0)//Ϊ�Ӻ�ʱ 
        s+=i+1;
      else if(a[i]==1)//Ϊ����ʱ 
        s-=i+1;
      else if(a[i]==2)//Ϊ�˺�ʱ 
        s*=i+1;                     
    }          
    if(s==N)//����ȣ����ӡ��� 
    {
      f=1;//���Ϊ�н� 
      cout<<1;
      for(i=1;i<=8;i++)
        cout<<fuhao[a[i]]<<i+1;                 
      cout<<'='<<N<<endl;        
    }  
    a[8]++;//���һλ���ۼ�1
    j=8;
    while(a[j]==3)//ѭ����λ 
    {
      a[j]=0;//��λ��Ϊ�� 
      a[j-1]++;//��һλ��һ 
      j--;     //ָ��ָ����һλ         
    } 
  }
  if(f==0)
    cout<<"No answer!";
  system("pause");  
}
