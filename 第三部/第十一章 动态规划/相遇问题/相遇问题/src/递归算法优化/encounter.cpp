//������������ݹ��㷨�Ż� 
#include<iostream>
#include<iomanip>
using namespace std;

int n;
const int MAX=312; 
float way[MAX+1][MAX+1][MAX+1];  

float go(int day,int x,int y,float m)
{
  if(way[day][x][y]==-1)//�������ǹ�������������,���� 
    return 0;
  if(day>n||way[MAX][x][y]==0)//�����ʱ���߳���Χ����������2��3��4��,��ǲ��˳� 
  {
    way[day][x][y]=-1;
    return 0;
  }
  if(way[day][x][y]!=0)//����Ѿ�����Ӵ�ʱ�̴�λ�õ����ӵļ��� ,���ؼ��� 
    return way[day][x][y];
  if(day==x && y==(n>>1)+1)//�����������������,���ؼ��� 
  {
    way[day][x][y]=m;
    return m;
  }
  float tem=0;
  tem=go(day+1,x+1,y,m)+go(day+1,x-1,y,m)+go(day+1,x,y+1,m)+go(day+1,x,y-1,m); 
  if(tem==0) //���û����������,��ǲ��˳� 
  {
    way[day][x][y]=-1;
    return 0;
  }
  way[day][x][y]=tem/way[MAX][x][y];//����,����Ӵ�ʱ�˿��������ӵļ��� 
  return way[day][x][y];
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);  
  float ans;
  cin>>n;
  if(n%4==1)
    cout<<0<<endl;
  else
  {
    for(int i=2;i<=n-1;i++)//��way[MAX][i][j]��ʼ��Ϊ·��������ΪMAX>n 
    {
      for(int j=2;j<=n-1;j++)
        way[MAX][i][j]=4;
      way[MAX][1][i]=way[MAX][i][1]=way[MAX][n][i]=way[MAX][i][n]=3;
    }
    way[MAX][1][1]=way[MAX][1][n]=way[MAX][n][1]=way[MAX][n][n]=2;
    ans=go(0,(n/2)+1,((n/2)+1),1);//��0ʱ��������((n/2)+1,(n/2)+1)�������ӵļ���
    cout<<setprecision(4)<<ans<<endl; 
  }
  return 0;
}
