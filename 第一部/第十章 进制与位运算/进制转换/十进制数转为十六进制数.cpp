//ʮ������תΪʮ��������
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int number,m,i;
  string s;
  cin>>number;
  for(i=0;i<=7;i++)
  {
    m=number>>(i*4) &15;//��15�������������������λ 
    if(m<10) 
      s=char(m+48)+s;//�������֣�ע����ӵ�ǰ��˳�� 
    else  
      s=char(55+m)+s;//������ĸ 
   }
   while(s[0]=='0')
     s.erase(0,1);  //ɾ��ǰ��0 
   cout<<s;    
   system("pause");
}
