//��������������棱 
#include<stdio.h>

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);  
  int Dir[301][301];//�洢�õ��м�����չ���� 
  int t,i,j,k,n;
  float p[301][301]={0},q[301][301]={0};//��Ϊ��������.�洢���� 
  float ans=0;
  scanf("%d",&n);
  k=(n+1)/2;  //�����������ʼλ��
  q[k][k]=1;  //������ʼλ�ø���Ϊ1,ʱ��Ϊ0

  for(i=0;i<=n+1;i++) //����Dir[x,y] �˴�������һȦ�Է�Խ�� 
    for(j=0;j<=n+1;j++)
    {
      if((i==1&&j==1)||(i==1&&j==n)||(i==n&&j==1)||(i==n&&j==n))
        Dir[i][j]=2;  //���ó���λ���ĸ���ʱ,�����Ϊ1/2 
      else if(i==1||j==1||i==n||j==n)
        Dir[i][j]=3;  //���ó���λ��������ʱ,�����Ϊ1/3 
      else Dir[i][j]=4;//����.�����Ϊ1/4 
    }
   
  for(t=1;t<=n;t++)//����ʱ��t,���Կɱ���ά����Ϊ��ά���� 
  {
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        p[i][j]=0;  //ˢ������p 
        
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      { 
        p[i][j]+=q[i][j-1]/Dir[i][j-1];//qΪ��һʱ��ĸ��� 
        p[i][j]+=q[i][j+1]/Dir[i][j+1];
        p[i][j]+=q[i+1][j]/Dir[i+1][j];
        p[i][j]+=q[i-1][j]/Dir[i-1][j];
      }
    
    ans+=p[k][t];
    p[k][t]=0;  //�����ظ� 
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        q[i][j]=p[i][j];//�������� 
  }
  if(ans<=0.00001)
    printf("0\n");
  else  
    printf("%.4f\n",ans);
  return 0;  
}
