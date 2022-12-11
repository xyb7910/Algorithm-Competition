#include <iostream>
#include <math.h>
using namespace std;

#define m 100 
int i,j,s,k,n;
double x,y,Min;
double yy1;
double p[m+1][2+1];//��ŵ������ 
double d1[m-1+1][m-1+1];//���Pi,Pj���� 
double c[m+1][m-1+1];//C[s,i]��ʾS�߱��i�߿�ʼ����СSnp 

double d(int i1,int j1)
{
  double d;   
  d=d1[i1%n][j1%n];// if(i1>n)i1=i1-n;  if(j1>n) j1=j1-n);
  return d;
}

double Getd(int i,int j) 
{
  double d;     
  d=sqrt((p[i][1]-p[j][1])*(p[i][1]-p[j][1])+(p[i][2]-p[j][2])*(p[i][2]-p[j][2]));      
  return d;
}

int main()
{
	freopen("excision.in", "r", stdin);
	freopen("excision.out", "w",stdout);
	
  cin>>n;  
  for(i=0;i<=n-1;i++)//��ʼ�� 
    scanf("%lf%lf",&p[i][1],&p[i][2]);
  for(i=0;i<=n-1;i++)
    for(j=0;j<=n-1;j++)
      if((fabs(i-j)==1)||(fabs(i-j)==n-1))//���������� 
        d1[i][j]=0;
      else
        d1[i][j]=Getd(i,j);
        
  for(s=1;s<=3;s++)
    for(j=1;j<=n-1;j++)
      c[i][j]=0;//���������ڵľ���ʼ��Ϊ�� 
  for(s=4;s<=n;s++)
    for(i=0;i<=n-1;i++)
    {
      Min=100000;
      for(k=1;k<=s-2;k++)
      {
        if(k+1<4)
          x=0;
        else
          x=c[k+1][i];
        if(s-k<4)
          y=0;
        else
          y=c[s-k][i+k];
        yy1=x+y+d(i,i+k)+d(i+k,i+s-1);
        if(Min>yy1)
          Min=yy1;
      }
      c[s][i]=Min;
    }
  printf("%.2lf\n",c[n][0]);
  return 0;
}
