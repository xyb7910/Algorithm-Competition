//N�������ӷ�����
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a,b,w;
  int x[100],y[100];
  int i,k,N;
  cin>>N;
  for(i=0;i<=N-1;i++)
  {// 
    if(i<10)
     w=w+char(i+48);//���ֵĴ��� 
    else
     w=w+char(55+i);//��ĸ�Ĵ���                    
  }
  //cout<<w<<endl;//���0123...ABC...���� 
  cin>>a>>b;
  while(a.length()<b.length())
    a='0'+a;
  while(b.length()<a.length())
    b='0'+b;
  a='0'+a;//ǰ����һλ�����ڽ�λ    
  b='0'+b;
  //cout<<a<<endl<<b<<endl<<endl;//�������Ƿ���ȷ 
  for(i=a.length()-1;i>=0;i--)
  {  
    x[i]=w.find(a[i],0);//����a[i]��W�е�λ�û����ʵ������ 
    y[i]=w.find(b[i],0);//ת����x,y������׼����� 
  } 

  for(i=a.length()-1;i>=0;i--)//��λ�ӷ� 
  {     
    x[i]=x[i]+y[i];
    if(x[i]>=N)
    {
      k=i;         
      while(x[k]>=N)
      {
        x[k]=x[k]-N;
        x[k-1]++;
        k--;
      }                           
    }  
  }  

  for(i=a.length()-1;i>=0;i--)
    a[i]=w[x[i]];//ת��ΪN��������a���Ǽӷ��������� 
  
  while(a[0]=='0')
     a.erase(0,1);  //ɾ��ǰ��0 
  cout<<a<<endl;  
  system("pause");  
}
