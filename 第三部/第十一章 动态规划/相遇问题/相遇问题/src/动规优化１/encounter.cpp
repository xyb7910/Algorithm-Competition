//����������������Ż��� 
#include<stdio.h>
int n;
int Dir(int x,int y)
{
  if((x==0&&y==0)||(x==n-1&&y==n-1)||(x==0&&y==n-1)||(x==n-1&&y==0))
    return 2;
  else if(x==0||y==0||x==n-1||y==n-1)
    return 3;
  else
    return 4;
}
int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);
  scanf("%d",&n);
  int i,j,k;
  double p[2][n][n],x=0;
  for(i=0;i<n;i++)  //��ʼ��f 
    for(j=0;j<n;j++) //p[0][i][j]��ʾ�������쵽��ͼ�Ϻ�����Ϊi,������Ϊj�ĸ��ӵĸ��� 
      p[0][i][j]=0,p[1][i][j]=0;//p[1][i][j]��ʾ�����ڶ��콫����ͼ��i,j�ĸ��ӵĸ��� 
  p[0][n/2][n/2]=1;   //��һ�칫����n/2��n/2�ĸ����ϣ����ĸ���Ϊ1 
  int w=0;  //w�����ã��ɽ�Լ�����������໥���������ʱ��  0��ʾ��������,1��ʾ��һ�������� 
  for(k=0;k<n;k++,w=1-w)  //w=1-w ��ʵ��1��0���л�, 
  {
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        p[1-w][i][j]=0;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
      {
        if(i-1>=0)//��ֹԽ��
          p[1-w][i-1][j]+=p[w][i][j]/Dir(i,j);
        if(j-1>=0)
          p[1-w][i][j-1]+=p[w][i][j]/Dir(i,j);
        if(i+1<n)
          p[1-w][i+1][j]+=p[w][i][j]/Dir(i,j);
        if(j+1<n)
          p[1-w][i][j+1]+=p[w][i][j]/Dir(i,j);
      }
    x+=p[1-w][n/2][k],p[1-w][n/2][k]=0;
  }
  if(x<1e-4)
    printf("%.0f\n",x);
  else
    printf("%.4f\n",x);
  return 0;
}
