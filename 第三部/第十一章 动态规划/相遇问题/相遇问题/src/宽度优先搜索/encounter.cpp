//��������������ɹ��������Ե�
#include<iostream>
#include<iomanip>
#define MAX 10000000
using namespace std;
int X1,Y1,day,way[101][101];
int pa,pb;//paΪ���е�βָ�룬�����ݣ�pbΪ���е���ָ�룬������ 
int n;
float lv,ans=0;
struct X
{
  int d,x,y;//dΪ������x,yΪ����
  float m;//��ԭ�㵽��ʱ�˴��ļ���
}a[MAX+1];//�����õ���ѭ������
 
void pop()//���� 
{
  X1=a[pa].x;
  Y1=a[pa].y;
  lv=a[pa].m;
  day=a[pa].d;
  pa++;
  if(pa>MAX)
    pa=0;
}

void push(int x2,int y2,int day2,float mm)//���� 
{
  if(x2==day2 && y2==(n>>1)+1)//���������������ʣ�����ѹ����� 
  {
    ans+=mm;
    return ;
  }
  a[pb].x=x2;
  a[pb].y=y2;
  a[pb].d=day2;
  a[pb].m=mm;
  pb++;
  if(pb>MAX)
    pb=0;
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);   
  int k1,k2;
  cin>>n;
  if(n%4==1)
    cout<<0<<endl;
  else
  {
    float t;
    for(int i=2;i<=n-1;i++)
    {
      for(int j=2;j<=n-1;j++)
        way[i][j]=4;
      way[1][i]=way[i][1]=way[n][i]=way[i][n]=3;
    }
    way[1][1]=way[1][n]=way[n][1]=way[n][n]=2;
    X1=Y1=a[1].x=a[1].y=(n>>1)+1;//��ʼ������λ�ò������ 
    a[1].d=0;
    a[1].m=1;
    pa=1;
    pb=2;
    while(pa!=pb)
    {
      pop();
      k1=day>(n>>1)+1-day?day:(n>>1)+1-day; //��֦
      k2=(k1==day?n:n+1-k1);
      if(day>n||X1<k1||X1>k2)//�糬��Χ�򲻿���Ӱ�����˳�����ѭ��
        continue;
      t=lv/way[X1][Y1];//�Ӵ�ʱ�˴������ܵĸ���
      if(way[X1+1][Y1])//�ĸ���������չ����Ϊ�棬����� 
        push(X1+1,Y1,day+1,t);
      if(way[X1-1][Y1])
        push(X1-1,Y1,day+1,t);
      if(way[X1][Y1+1])
        push(X1,Y1+1,day+1,t);
      if(way[X1][Y1-1])
        push(X1,Y1-1,day+1,t);
    }
    cout<<setprecision(4)<<ans<<endl;
  }
  return 0;
}
