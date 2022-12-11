//�ϲ�ħ��ʯ2������2 
#include<stdio.h>
#include<iostream>
using namespace std;
 
#define MAX_LONG 0x7fffffff
 
struct Node{ //��ǰ���еĺϲ�����
     long c; //�÷ֺ�
     int d; //�����еĶ���
};
 
long sumtype[101][101]; //sumtype[i][j] - ������[i,j]��ʯ������
Node list[101][101]; //st[i][j] - ������[i,j]�ĺϲ�����
int date[101],dt[101]; //date[i] - ��i��ʯ����,dt - �ݴ�date
int i,j,N; //N - ʯ�Ӷ���, i,j - ѭ������
 
void Print(int i,int j) //�ݹ��ӡ������[i,j]�ĺϲ�����
{
     int k,x; //k - ѭ������,x - ���������׶�ʯ�ӵ����
     if(j != 1) //�������ƺϲ�����
     {
         Print(i,list[i][j].d); //���������еĺϲ�����
         x=(i+list[i][j].d-1)%N+1; //�����������׶�ʯ�ӵ����
         Print(x,j-list[i][j].d); //���������еĺϲ�����
         for(k=1;k<=N;k++) //�����ǰ�ϲ���i��,��x��ʯ�ӵķ���
              if(date[k]>0)
                   if(i==k || k==x)
                       printf("-%d ",date[k]);
                   else
                       printf("%d ",date[k]);
         printf("\n");
         date[i]=date[i]+date[x]; //ԭ��i�Ѻ͵�x�Ѻϲ��ɵ�i��
         date[x]=-date[x]; //��ԭ��x�Ѵ�Ȧ��ȥ��
     }
}
 
void solve(int s)
{
     int i,j,k;
     long t,x;
     for(i=1;i<=N;i++) //����һ��ʯ�ӵ����в����ںϲ�
     {
         list[i][1].c=0;
         list[i][1].d=0;
     }
     for(j=2;j<=N;j++) //˳�ƺ���,���ѡ�����N��ʯ�ӵĸ������еĺϲ�����
         for(i=1;i<=N;i++) //��ǰ���Ǵӵ�i������,˳ʱ����j�ѵ�������
         {
              if(s==1) //�ϲ�[i,j]�����еĵ÷ֺͳ�ʼ��
                   list[i][j].c=MAX_LONG;
              else
                   list[i][j].c=0;
              t=sumtype[i][j]; //���һ�κϲ��ĵ÷�Ϊ[i,j]�����е�ʯ������
              for(k=1;k<=j-1;k++) //�����е�ʯ�Ӷ������ο��Ƕѡ���j-1��
              {
                   x=(i+k-1)%N+1; //���������׶����
                   if((s==1 && list[i][k].c+list[x][j-k].c+t<list[i][j].c) ||
                       (s==2 && list[i][k].c+list[x][j-k].c+t>list[i][j].c))
                       //���úϲ�����ΪĿǰ���,�����
                   {
                       list[i][j].c=list[i][k].c+list[x][j-k].c+t;
                       list[i][j].d=k;
                   }
              }
         }
     //��������[1,N],[2,N],����,[N, N]��ѡ��÷��ܺ���С(�����)��һ��������
     k=1;
     x=list[1][N].c;
     for(i=2;i<=N;i++)
         if((s==1 && list[i][N].c<x) || (s==2 && list[i][N].c>x))
         {
              k=i;
              x=list[i][N].c;
         }
     //Print(k,N); //�ɴ˳���,���ƺϲ�����
     //printf("%d\n%d\n",sumtype[1][N], x); //������һ�ν�ʯ�Ӻϲ���һ�ѵ�ʯ������
     //printf("\n");
     printf("%d",list[k][N].c);
}
 
int main()
{
     freopen("merge2.in", "r", stdin);
	freopen("merge2.out", "w", stdout);
     scanf("%d",&N); //����ʯ�Ӷ���
     for(i=1;i<=N;i++)
         scanf("%d",&date[i]); //����ÿ��ʯ����
     for(i=1;i<=N;i++) //��ÿһ�������е�ʯ����sumtype
         sumtype[i][1]=date[i];
     for(j=2;j<=N;j++)
         for(i=1;i<=N;i++)    //ע�����ļ��� 
              sumtype[i][j]=date[i]+sumtype[i%N+1][j-1];
     
     for(i=1;i<=N;i++) //�ݴ�ϲ�ǰ�ĸ���ʯ��
         dt[i]=date[i];
     solve(2); //��÷ֺ���С�ĺϲ�����
     printf(" ");
     for(i=1;i<=N;i++) //�ָ��ϲ�ǰ�ĸ���ʯ��
         date[i]=dt[i];
     solve(1); //��÷ֺ����ĺϲ�����
     printf("\n");
     return 0;
}
