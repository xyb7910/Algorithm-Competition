//ţ����3
#include <iostream>
using namespace std;
int s,t,c;

int dfs(int i,int c,int x)//�ݹ飬i��ʾλ����c��ʾ1�ĸ�����x��ʾ���� 
{
  if(i>24)//���24λ�������� 
    if(x>=s && x<=t)//�ж��Ƿ��������� 
      return 1;
    else
      return 0;
   int ans=dfs(i+1,c,x);
   if(c<4)//��1�ĸ���С��4ʱ 
     ans+=dfs(i+1,c+1,x+(1<<i));//1<<i��ʾ������1��λ�������� 
   return ans;          
}

int main()
{
  cin>>s>>t;
  cout<<dfs(0,0,0)<<endl; 
  system("pause");
  return 0;
}
