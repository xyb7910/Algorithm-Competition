//����������������Ż��� 
#include<iostream>
#include<iomanip>
#define MAX 1555
using namespace std;
int n,m;
//MAX>>1�൱��MAX/2��Ҳ��λ���㣬����ʹ�þ���ֻ�迪��һ��Ŀռ� 
double f[MAX][MAX>>1];
int inline d(int x,int y)//��������(x,y)λ������չ������·����
{ 
  return 2+(x>1 && x<n)+(y<m);//�ж��Ƿ�Խ�磬����չ����·��������Ϊ2 
}
int inline minn(int ax,int bx)//����ax,bx�Ľ�Сֵ 
{
  return ax<=bx?ax:bx;
}
int inline maxn(int ax,int bx)//����ax,bx�Ľϴ�ֵ
{ 
  return ax>=bx?ax:bx;
}

int inline absn(int ax)//����ax�ľ���ֵ
{ 
  return ax>=0?ax:-ax;
}

double Dp()//������� 
{
  if(m&1^1)//��ʼ��ż���жϣ�ʹ����λ���� 
    return 0;
  int i,j,k,end_k,end_j;
  for(i=n;i>=0;f[i--][0]=1)//�˴���ʼ���ƣ����Ƶĳ�ʼλ�õĸ���Ϊ1 
    for(j=maxn(i,m+1-i),end_j=minn(n,m+1+i);j<=end_j;++j)
    {//�˴�ͨ��maxn(i,m+1-i)�����쾵��ͬʱ�Թ����ķ�Χ���м�֦ 
      if(j-i&1^1)//�����е���ż���ж�,�˴�ʹ��λ���㣬��ʾ��i��jͬ��żʱ����1 
        f[j][0]=(f[j][1]+f[j][1]+f[j+1][0]+f[j-1][0])/d(j,0);
      for(k=2-(j-i&1),end_k=minn(minn(j-i,m),i-absn(m+1-j));k<=end_k;k+=2)
        //��j-i&1ͬ���ǹ����е���ż���жϣ���i+jΪż��ʱ����0�����򷵻�1
        //��minn(j-i,m)Ϊ����ѡ��ͬ��Ҳ�ǹ���׷�����ӵļ�֦ ��absn(m+1-j)Ϊ������Χ��֦ 
        f[j][k]=(f[j+1][k]+f[j-1][k]+f[j][k+1]+f[j][k-1])/d(j,k);//�˴�Ϊ��������ĺϲ� 
    }
  return f[m+1][0];//���ع����ĳ�ʼλ�ø���ֵ 
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);    
  cin>>n;
  m=n>>1;
  cout<<fixed<<setprecision(4)<<Dp()<<'\n';
  return 0;
}
