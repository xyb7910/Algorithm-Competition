//�ڱ���� 
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int f[110][150][150];
int s[110][150];
int num[110][150];
int N,M;
bool map[1100][1100];//Ԥ��������״̬�ĳ�ͻ�������map[][]������

inline int getnum(int x)//����xת�����������ж���0 
{
  int t=0;
  while(x>0)
  {
    x=x&(x-1);
    t++;
  }
  return t;
}

void init()
{
  cin>>N>>M;
  string tmp;int q;
  for(int i=1;i<=N;i++)
  {
    cin>>tmp;
    q=0;
    for(int j=0;j<tmp.size();j++)//״̬ѹ������ 
      if(tmp[j]=='P')//�����ƽԭ��Ϊ0 
        q=(q<<1); 
      else//�����ɽ��,��Ϊ1 
        q=(q<<1)|1;
   
    for(int j=0;j<(1<<M);j++)//ö�����з���0-111..111 
    {
      if((j<<1)&j || (j<<2)&j || (j>>1)&j || (j>>2)&j ) 
        continue;//��һ�����г�ͻ�������������������������� 
      if( q&j ) //���õ�����ö�ٵĶ�������j�����г�ͻ�������� 
        continue;
      ++s[i][0];//���� 
      s[i][s[i][0]]=j;//��¼�÷��� 
      num[i][s[i][0]]=getnum(j);//��¼�÷������ڱ��� 
    }
  }
  for(int i=0;i<=(1<<M);i++)//Ԥ������i��j�Ƿ��ͻ 
    for(int j=0;j<=(1<<M);j++)
      if( !(i&j) )
        map[i][j]=true;
}

void Dp()
{
  s[0][0]=1;
  int s1,s2,m=1;
  for(int i=1;i<=N;i++,m=m^1)//���棬��i�� 
    for(int a=1;a<=s[i-1][0];a++)//a���� 
    {
      s1=s[i-1][a];//i-1�е�a���� 
      for(int b=1;b<=s[i][0];b++)//b���� 
        if( map[s1][s[i][b]] )//��a,b��������ͻ 
        {
          s2=s[i][b];//i�е�b����     
          if(i==1)//��i�ǵ�һ�� 
            f[m][a][b]=max(f[m][a][b],num[i][b]);
          else
          {    
            for(int c=1;c<=s[i-2][0];c++)//i-2�е�c���� 
              if( map[s[i-2][c]][s1] && map[s[i-2][c]][s2])//��3����������ͻ 
                f[m][a][b]=max(f[m][a][b],f[m^1][c][a]+num[i][b]);
          }  
        }
    }
  int Ans=0;
  m=m^1;
  for(int a=1;a<=s[N-1][0];a++)
    for(int b=1;b<=s[N][0];b++)
      Ans=max(Ans,f[m][a][b]);
  cout<<Ans<<endl;
}

int main()
{
  freopen("cannon.in","r",stdin);
  freopen("cannon.out","w",stdout);
  init();
  Dp();
  return 0;
}
