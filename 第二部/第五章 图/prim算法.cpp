/*
�������ƣ�prim�㷨����ʾ���� 
����˵��������ʹ������ͼ
*/
#include<iostream>
#define MAXN 2001
#define INF 999999999
using namespace std;
int n,e;
int w[MAXN][MAXN];/*����֮��ߵ�Ȩֵ*/
int mincount[MAXN];/*�ӳ�ʼ���㵽�ö������СȨֵ*/

void prim(int s)
{
  int i,j,count=0,min;/*countΪ���������бߵ�Ȩֵ��*/           
  int k;
  for(i=1;i<=n;i++)
    mincount[i]=w[s][i];/*��ʼ������w(1,i)Ϊ��ʼ��k��i����СȨֵ�����û����Ϊ+��*/
  mincount[s]=0;

  for(i=1;i<n;i++)         
  {
    min=INF;
    for(j=1;j<=n;j++) 
	if(mincount[j]!=0 and mincount[j]<min)//��ýڵ�û�б����뵽SMT�в��Ҹõ�ȨֵΪ��ǰ��С  
    {
      min=mincount[j];
      k=j;  //��¼�õ�
    }

    mincount[k]=0;//���������뵽��С��������
    count+=min; //�������߼��뵽��С��������

    for(j=1;j<=n;j++) /*������ʼ�㵽ÿ�������СȨֵ*/
     if(w[k][j]<mincount[j])
       mincount[j]=w[k][j];       
  }
  cout<<count<<"\n";         
}

void init()
{
  int i,j,tx,ty;        
  for(i=0;i<=MAXN;i++)
    for(j=0;j<=MAXN;j++)
       w[i][j]=INF;
          
  cin>>n>>e;
  for(i=1;i<=e;i++)              
  {
    cin>>tx>>ty>>w[tx][ty];
    w[ty][tx]=w[tx][ty];   
  }
}

int main()//��ʾ����,�ӱ��Ϊ1�Ķ��㿪ʼ����������
{
  init();
  prim(1);              
  return 0;         
}
