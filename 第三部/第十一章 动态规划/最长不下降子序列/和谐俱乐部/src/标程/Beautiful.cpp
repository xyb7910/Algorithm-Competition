//��г���ֲ� 
#include <iostream>
#include <cstdlib>
using namespace std;
int N;
int a[5][100001];//0ά�����,1ά��a,2ά��b,3ά���������,4ά���¸����� 
int out[100001];//�������
 
void quick(int i,int j)//��a[1][n]���� 
{
 int m=i,n=j,temp,k;
 k=a[1][(i+j)/2];  /*ѡȡ���м����ֵ*/
 while(m<=n)
 {
    while(a[1][m]<k&&m<j)  m++;  /* �������ұ�k���Ԫ��*/
    while(a[1][n]>k&&n>i)  n--;  /* ���ҵ����ұ�kС��Ԫ��*/ 
    if(m<=n)
    {               /*���ҵ���������������a����ȫ����*/
       temp=a[0][m]; a[0][m]=a[0][n]; a[0][n]=temp;
       temp=a[1][m]; a[1][m]=a[1][n]; a[1][n]=temp;
       temp=a[2][m]; a[2][m]=a[2][n]; a[2][n]=temp;       
       m++;
       n--;
    }
 }
 if(m<j)  quick(m,j);  /*���õݹ�*/
 if(n>i)  quick(i,n);
}

void GetLong()//�������
{
  int i,j;   
  for(i=2;i<=N;i++)
    for(j=1;j<i;j++)//�Ƚ�ǰ������� 
    {
      if(a[1][i]>a[1][j] && a[2][i]>a[2][j] && a[3][j]+1>a[3][i])   
      {
        a[3][i]=a[3][j]+1;//���������1 
        a[4][i]=j;//�����ϸ����� 
        if(a[3][i]>a[0][0])
        { 
            a[0][0]=a[3][i];//a[0][0]����������� 
            a[1][0]=i;//Long���浱ǰ������������±� 
        }    
      }
    }
}

void OK()//������
{ int i,t;
  printf("%d\n",a[0][0]);
  t=a[1][0];
  for(i=1;i<=a[0][0];i++)//��������� 
  {      
    out[t]=a[0][t];     
    t=a[4][t]; 
  }
  for(i=1;i<=100001;i++)//������
  {   
    if (out[i]!=0)
     printf("%d ",out[i]);  
  }    
}

int main()
{
  freopen("Beautiful.in","r",stdin);
  freopen("Beautiful.out","w",stdout);  
  int i;
  scanf("%d",&N);//�����Ա��N 
  for(i=1;i<=N;i++)
  {
    a[0][i]=i;//���±�
    a[3][i]=1;//��ʼ���������Ϊ1 
    scanf("%d %d",&a[1][i],&a[2][i]);//���A,Bֵ 
  }

  quick(1,N);
  GetLong();     
  OK();
  return 0; 
}
