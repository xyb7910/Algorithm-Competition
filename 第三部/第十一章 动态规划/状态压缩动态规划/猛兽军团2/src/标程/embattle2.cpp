//���޾���2 
#include <iostream>
#include <cstdlib>
#define MOD 100000000
using namespace std;

int M,N,line[13];
int put[13][1000];
int f[13][1000],Ans=0;

void init()
{
  cin>>M>>N;
  for(int x,i=1;i<=M;i++)
    for(int j=1;j<=N;j++)//ѹ��ÿ���ܷ���õ�״̬
    {
      cin>>x;
      line[i]=(line[i]<<1)+1-x; 
    }
    
  for(int i=1;i<=M;i++)//���ÿһ�����п���״̬
    for(int j=0;j<(1<<N);j++)
    {
      if( (j<<1)&j || (j>>1)&j || j&line[i] ) 
        continue;
      put[i][0]++;
      put[i][put[i][0]]=j;
    }
}

void Dp()
{
  int s1,s2;
  f[0][1]=1;
  put[0][0]=1;//��ʼֵ  �����ж�������
  for(int i=1;i<=M;i++)   //ö����
    for(int a=1;a<=put[i-1][0];a++)//ö����һ�е�״̬
    {
      s1=put[i-1][a];
      for(int b=1;b<=put[i][0];b++)//ö�ٴ���״̬
      {
        s2=put[i][b];
        if(s1&s2) 
          continue;//������ͻ
        f[i][b]+=f[i-1][a];
        f[i][b]%=MOD;
      }
    } 
  for(int i=1;i<=put[M][0];i++)//ͳ�����һ��
    Ans+=f[M][i],Ans%=MOD;
  cout<<Ans<<endl;
}

int main()
{
  freopen("embattle2.in","r",stdin);
  freopen("embattle2.out","w",stdout);  
  init();
  Dp();
  return 0;
}
