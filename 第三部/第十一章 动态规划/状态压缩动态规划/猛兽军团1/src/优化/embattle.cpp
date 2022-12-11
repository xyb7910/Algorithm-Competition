//���޾���1���Ż� 
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXN 2000
#define MAXK 1100

long long f[2][MAXN][MAXK],Ans;
int N,K;
int s[MAXN],num[MAXN];
int next[MAXN*10],h[MAXN*10],st[MAXN],flag;

inline int getnum(int x)//�õ����޸���
{
  int t=0;
  while(x>0)
  {
    x=x&(x-1);
    t++;
  }
  return t;
}

void DFS(int len,int now)//�ٶȽ�����Կ죬�������� 
{
  if(len==N)//�ѵ���һ��״̬ 
  {
    ++s[0];
    s[ s[0] ]=now;
    num[ s[0] ]=getnum(now);
    return ;
  }
  DFS(len+1,now<<1);//���������޵���� 
  if((now&1)!=1)//�������޵����,ǰ��now��ż��������λ����1��
    DFS(len+1,(now<<1)|1);
}

void add(int one,int two)//�������ӱ�洢
{
  next[++flag]=st[one];
  h[flag]=two;
  st[one]=flag;
}

void init()
{
  cin>>N>>K;
  DFS(0,0);//���ѵõ�s[]
  int s1,s2;
  add(1,1);//s[1]=00000 (n��0)
  for(int i=1;i<=s[0];i++)//������з�����Ԥ����߱߹�ϵ����
    for(int j=i+1;j<=s[0];j++) 
    {
      s1=s[i],s2=s[j];
      if(((s2<<1) & s1) || ((s2>>1) & s1) || (s1&s2))//���г�ͻ 
        continue;//���� 
      add(i,j);add(j,i);
    }
}

void Dp()
{
  f[0][1][0]=1;
  int s1,s2,m=1,dm;
  for(int i=1;i<=N;i++)//��ѭ��
  {
    dm=m^1;//ͨ�����ʵ�ֹ��������±�m��0,1֮����� 
    for(int a=1;a<=s[0];a++)//��������ÿ�ζ���Ҫ��ʼ��
      for(int b=0;b<=K;b++) 
        f[m][a][b]=0;
    for(int a=1;a<=s[0];a++)//ö�ٴ���״̬
      for(int k=0;k<=K-num[a];k++)//ö�����޸���
        for(int b=st[a];b!=0;b=next[b])//ö����һ��״̬
        {
          s2=h[b];
          f[m][a][k+num[a]]+=f[dm][s2][k];
        }
    m=dm;
  }
  m=m^1;
  for(int i=1;i<=s[0];i++)//ͳ�ƴ�
    Ans+=f[m][i][K];
  cout<<Ans<<endl;
}

int main()
{
  freopen("embattle.in","r",stdin);
  freopen("embattle.out","w",stdout);  
  init(); 
  Dp();
  return 0;
}
