//������
#include <iostream>
using namespace std;
int num,temp[100];

int size(int x)//��ȡλ�� 
{
  int lenth=0;  
  while(x>0)
  {
   x=x/10;
   lenth++;          
  }   
  return lenth;
}

unsigned int nx(int x)//�������� 
{
  unsigned int i,t,ans=0;
  t=x;
  for(i=1;i<=num;i++)//�����λ 
  {
    t=x-(x/10*10);
    temp[i]=t;
    x=x/10;                   
  }
  for(i=1;i<=num;i++)//������� 
  {
    ans=ans*10+temp[i];                 
  }  
  return ans; 
}

int ok(int x)//�ж��Ƿ���� 
{
  int mid,i,t,l;
  l=num;
  mid=num/2; 
  for(i=1;i<=num;i++)
  {
    t=x-(x/10*10);
    temp[i]=t;
    x=x/10;                   
  } 
  for(i=1;i<=mid;i++)
  {
    if(temp[i]!=temp[l])
      return 0;
    l--;
  }          
  return 1;
}

int main()
{
  unsigned int in,i,ans;
  cin>>in;
  num=size(in);
  ans=in;

  while(1)
  {
    cout<<ans<<"+"<<nx(ans)<<"="<<ans+nx(ans)<<endl;          
    ans=ans+nx(ans);
    num=size(ans);
    if(ok(ans)==1)
      break;        
  }
  system("pause");
  return 0;
}
