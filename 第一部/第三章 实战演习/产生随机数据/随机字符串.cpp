//����ָ�����ȵ�����ַ��� 
#include <iostream>
using namespace std;

int main()
{
  int i,n,m;//���n��m���ַ�������ַ���
  string str;
  cin>>n>>m; 
  srand((unsigned)time(NULL));
  for(i=1;i<=n;i++)
  {
    str="";//����ַ���
    for(int j=1;j<=m;j++)
    {
      int temp=rand()%2;//������������д��Сд��ĸ
	  if (temp==0)		
        str+=(char)(rand()%(26)+1+64);//'A'=65,'Z'=90
      else
	    str+=(char)(rand()%(26)+1+96);//'a'=97,'z'=122
    }
    cout<<str<<endl;
  }	
  system("pause");
  return 0;
}
