//������Ϸ-�ݹ����� 
#include <iostream>
#include <cstdlib>
using namespace std;
int n,m,sum;

void pp(int k,int step)
{
  if(step==m)//�������m�� 
  {
    if(k==1)//ǡ�ô����������������1 
      sum++;
    return;
  }
  if(k==n)//������ڵ�n������� 
  {
    pp(1,step+1);//�����ߴ�����һ���� 
    pp(k-1,step+1);//�����ߴ���n-1�� 
  }
  if(k==1)//������ڵ�һ������ 
  {
    pp(n,step+1);//���ߴ�����n�� 
    pp(k+1,step+1);//���ߴ�����2�� 
  }
  if(k>1 && k<n)//�����1��n֮����κ�һ�� 
  {
    pp(k+1,step+1);//���ߴ����ұ� 
    pp(k-1,step+1);//���ߴ������ 
  }
}

int main()
{
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);  
  cin>>n>>m;
  pp(1,0);
  cout<<sum<<endl;
  return 0;
}
