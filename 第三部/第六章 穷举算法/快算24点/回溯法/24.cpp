//���㣲���㣭���� 
#include "stdio.h"
#define INF 10000000
int a[4][4];//���ݵ�����,��Ž�� 

void put(int k)//��ӡ���躯�� 
{
  char c;
  switch(k)
  {
    case 0: c='+';
            break;
    case 1: c='-';
            break;
    case 2: c='*';
            break;
    case 3: c='/';
  }
  printf("%c",c);
  return;
}

int main()
{
  int i,j[3],k[3],l;//i�����ݵĲ�����j�洢���Ǻϲ�������λ�ã�k�洢����� 
  for(i=0;i<4;i++)
    scanf("%d",&a[0][i]);
  for(i=0;i<3;i++)
    j[i]=0,k[i]=-1;
  i=0;
  while(a[3][0]!=24)//a[3][0]��3�κϲ������ս�� 
  {
    if(i==3)//�����㣬������ 
      i--;
    k[i]++;//����һ����� 
    if(k[i]==4)//ͬ�� 
      j[i]++,k[i]=0;
    if(j[i]==3-i)//ͬ�� 
    { 
      j[i]=0,k[i]=-1;i--;
    }
    else
    {
      for(l=0;l<3;l++)//�ѽ���任����һ�� 
      {
        if(l==j[i])//�ϲ�λ�� 
        {
          switch(k[i])//ö������� 
          {
            case 0:a[i+1][j[i]]=a[i][j[i]]+a[i][j[i]+1];
                   break;
            case 1:a[i+1][j[i]]=a[i][j[i]]-a[i][j[i]+1];
                   break;
            case 2:a[i+1][j[i]]=a[i][j[i]]*a[i][j[i]+1];
                   break;
            case 3:if(a[i][j[i]+1]!=0 && a[i][j[i]]%a[i][j[i]+1]==0) 
                     a[i+1][j[i]]=a[i][j[i]]/a[i][j[i]+1];
                   else
                     a[i+1][j[i]]=INF;//�ų��������������ֵĸ��� 
          }
        }
        else if(l<j[i])
          a[i+1][l]=a[i][l];
        else
          a[i+1][l]=a[i][l+1];
      }
      i++;
    }
    if(i==0 && k[i]==-1)//�޽� 
      break;
  }
  if(i==0)
    printf("No\n");
  else
    for(i=0;i<3;i++)
    {
      printf("%d",a[i][j[i]]);
      put(k[i]);//��ӡ����� 
      printf("%d=%d\n",a[i][j[i]+1],a[i+1][j[i]]);
    }
  getchar();
  getchar();
  return 0;
}
