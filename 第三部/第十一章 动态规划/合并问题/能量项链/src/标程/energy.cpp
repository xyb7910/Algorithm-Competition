//�������� 
#include <stdio.h>
#include <stdlib.h>

int m[200][200];
int n,temp,p[200];

void matrixch(int p[],int n) //�����㷨
{
  int i,j,r,k;
  for(r=2;r<=n;r++)
    for(i=1;i<=n;i++)
    {
      j=i+r-1;
      m[i][j]=0;//��ʼΪ0 
      for(k=i;k<j;k++)//Ѱ��K 
	  {
        if(k+1>n)//���� 
	      m[k+1][j]=m[k+1-n][j-n];
        temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if(temp>m[i][j])
	      m[i][j]=temp;
	  }
   }
}

int main()
{
  int i;  
  freopen("energy.in","r",stdin);
  freopen("energy.out","w",stdout);

  scanf("%d",&n); 
  for(i=0;i<=n-1;i++)//��0��ʼ 
    scanf("%d",&p[i]);
  for(i=n;i<2*n;i++)//����һ������ 
    p[i]=p[i-n];
  matrixch(p,n);//���ú����㷨 
  
  for(i=1;i<=n;i++)
    if(m[i][i+n-1]>temp) 
      temp=m[i][i+n-1];
  printf("%d\n",temp);
  return 0;
}
