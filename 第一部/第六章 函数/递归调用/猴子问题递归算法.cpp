//�ݹ��㷨
#include <iostream>
using namespace std;
int m,k;
int Josephus(int m)//kΪ��ʼ����λ�� 
{
int ans;
   if(m==1)
    return 1;
   else 
    ans=(Josephus(m-1)+k-1)%m+1;
   //cout<<ans<<' ';  
   return ans; //������һ�ֺ���λ��
}
int main()
{   
  cin>>m>>k;
  cout<<Josephus(m)<<endl;
  system("pause");
}   
