//�����Ϸ
#include <iostream>
using namespace std;

int main()
{
  int num=21,man,computer;
  while(num!=1)
  {
    cout<<"����"<<num<<"�����,������ȡ���ٸ����?(1-4)\n";           
    cin>>man;
    if(man>4 ||man<1)
      continue;  
    cout<<"\n�����ȡ"<<5-man<<"�����,��ʣ"<<num-5<<"�����\n";
   num=num-5;
  }  
  cout<<"������! ";
  system("pause");
  return 0;  
}
