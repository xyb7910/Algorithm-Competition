//�����Ƶļӷ�
#include <iostream>
#include <fstream>
using namespace std;
int n,a,b,c,n9,sum,i,j;
bool first;

int main()
{
  ifstream cin("add3.in");
  ofstream cout("add3.out");  
  cin>>n;
  first=1;
  c=0;
  n9=0;//n9��ʾ֮ǰ���۵�9�ĸ�������ʼΪ0 
  for(i=1;i<=n;i++)//�Ӹ�λ��ʼ�����δ���ÿһλ 
  {
    cin>>a>>b;
    sum=a+b;
    if(sum<9)//�޽�λ��� 
    {
      if(c>0||first==0)//����ǰ��0 
        cout<<c;
      for(j=1;j<=n9;j++)//��Ϊ��λ�޽�λ����ɽ�֮ǰ���۵�999..99��� 
        cout<<9;
      first=0;
      n9=0;//���۵�999...999������������Ϊ0 
      c=sum;
    }
    else
      if(sum==9)//Ϊ9ʱ��ֻҪ��¼9�ĸ��� 
        n9++;
      else//����9����������λ��� 
      {
        c++;//��λ����� 
        cout<<c;
        for(j=1;j<=n9;j++)//��Ϊ��λ����ǰ����۵�9999..99��0000...000��� 
          cout<<0;
        first=0;
        n9=0;
        c=sum-10;//c��¼��λ����λ�����µ��� 
      }
  }
  
  cout<<c;//����ʣ�µ�һ��999...999 
  for(j=1;j<=n9;j++)
    cout<<9;
  cout<<"\n"; 
  cin.close();
  cout.close();
  return 0;
}
