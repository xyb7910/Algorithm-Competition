//kruskal�㷨
#include<iostream>
#define MAXN 2000
#define INF 99999999
using namespace std;
int n,e;/*�����ͱ���*/
int x[MAXN],y[MAXN],w[MAXN];/*xΪ�ߵ���㣬yΪ�յ㣬wΪ�ߵ�Ȩֵ*/
int dad[MAXN];/*ÿ���ڵ����ڵĸ��׼���*/


void sort(int i,int j)//���ţ�����Ȩ����
{
  if(i>=j)     
    return ;
  int m,n,t,k;
  m=i,n=j;
  k=w[ (i+j) >> 1];//ȡ��ֵ   
  while(m<=n)
  {
    while(w[m]<k)
	  m++;
    while(w[n]>k)
	  n--;
    if(m<=n)          
	{
	  t=x[m];
	  x[m]=x[n];
	  x[n]=t;
	  t=y[m];
	  y[m]=y[n];
	  y[n]=t;
	  t=w[m];
	  w[m]=w[n];
	  w[n]=t;            
	  m++;
	  n--;             
	}        
  }
  sort(i,n);
  sort(m,j);      
}

int getfather(int x)/*���ҵ�x���ڵļ���*/
{
  if(x==dad[x]) 
    return x;                
  dad[x]=getfather(dad[x]);//���ҹ����и���x�ĸ��׼��ϣ��൱�ڲ��鼯�鲢����
  return (dad[x]);
}
 
void kruskal()
{
   int i,p,ans;/*p:�Ѿ�����ı���,ans:����ߵı�Ȩ��*/
   for(i=1;i<=n;i++)
     dad[i]=i;/*��ʼ����ļ���*/
   p=1,ans=0;//pΪ��������Ϊ�ӿ�����ٶ�p��ʼ��Ϊ1���Ե�p=nʱ��������
       
   for(i=1;i<=e;i++)   
   {
     if(getfather(x[i])!=getfather(y[i]))//����ߵ����㲻��ͬһ�������ڣ���鲢��������                
	 {
	   ans+=w[i];/*���������߲�ͳ����Ȩֵ*/                
	   dad[getfather(x[i])]=y[i];//�ϲ�Ϊͬһ���׼���,�˴���ȡy[i]��ֵ 
	   p++;                
	   if(p == n)//�����С�������еĶ���������ȫ�������� - 1
       {
         cout<<ans<<"\n";
         return ;
       } 
     }               
   }
   return ;
} 

int main()
{
  int i,j;        
  cin>>n>>e;//����ڵ����ͱ��� 
  for(i=1;i<=e;i++)
    cin>>x[i]>>y[i]>>w[i];
  sort(1,e);/*���߰�Ȩֵ��С����*/
  kruskal();
  system("pause");
  return 0;         
}
