//��������������m��n,�������Լ������С������
# include <iostream>
using namespace std;

int main()
{
  int a,b,m,n,temp;
  cin>>m>>n;
  if(m<n) //��һ��������ȵڶ�����С
  {
    temp=m;  m=n;  n=temp;  //ͨ����ʱ����temp����m,n��ֵ����
  }
  a=m,b=n;
  while(b!=0)
  {
    temp=a%b;
    a=b;
    b=temp;
  }
  cout<<"���Լ��Ϊ"<<a<<endl;
  cout<<"��С������Ϊ"<<m*n/a<<endl;
  system("pause");
  return 0;
}
