//͹����ηָ� 
#include <iostream>
#include <math.h>
#include<iomanip.h>
using namespace std;
int i,j,s,k,n;
double x[50],y[50],d1[50][50],c[50][50]; //x[i]��ź����꣬y[i]��������꣬d1[i][j]����룬c[i][j]��ʾ��j�Ŷ��㿪ʼ��i���ε�Snp

double D(int i,int j) //��ȡ�����ľ���
{
  double d;     
  d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));      
  return d;
}

int main()
{
  freopen("excision.in","r",stdin);
  freopen("excision.out","w",stdout);
  cin>>n;  
  for(i=0;i<=n-1;i++) 
    cin>>x[i]>>y[i];
  for(i=0;i<=n-1;i++)
    for(j=0;j<=n-1;j++)
      if((fabs(i-j)==1)||(fabs(i-j)==n-1)) //�����������
        d1[i][j]=0;
      else
        d1[i][j]=D(i,j);
        
  for(s=1;s<=3;s++)
    for(j=1;j<=n-1;j++) //�����λ򹹲���ͼ��Ϊ0
      c[i][j]=0;
  for (s=4;s<=n;s++) //�����ʼ��Ϊ����
    for (i=0;i<=n-1;i++)
      c[s][i]=1e300;
  for(s=4;s<=n;s++)
    for(i=0;i<=n-1;i++)
      for(k=1;k<=s-2;k++)
        if(c[s][i]>c[k+1][i]+c[s-k][i+k]+d1[i%n][(i+k)%n]+d1[(i+k)%n][(i+s-1)%n]) 
        //��̬�滮��%n������n�����
          c[s][i]=c[k+1][i]+c[s-k][i+k]+d1[i%n][(i+k)%n]+d1[(i+k)%n][(i+s-1)%n];
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<c[n][0]; 
  return 0;
}
