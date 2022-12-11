//������ 
#include<iostream>
#define MAXN 100
using std::cin;
using std::cout;
int a[MAXN],n,heapsize;

void maxheapify(int i)/*������ڵ�*/
{
  int l,r,largest,t;
  /*����ýڵ�����Һ���*/
  l=i<<1;    
  r=(i<<1)+1; 
  /*��¼���Ԫ�ص��±�*/   
  if(l<=heapsize and a[i]<a[l])
    largest=l;
  else
    largest=i;
  if(r<=heapsize and a[r]>a[largest])          
    largest=r;
  /*�������Ԫ����i��ֵ,�����еݹ��齻����Ľڵ��Ƿ�������������*/  
  if(largest != i)
  {
    t=a[i];a[i]=a[largest];a[largest]=t;
    maxheapify(largest);
  }
  return ;         
}

void BuildMaxHeap()//���� 
{
  int i;
  heapsize=n;    
  for(i=n/2;i>=1;i--)
     maxheapify(i);
  return ;       
}

void heapsort()
{
  int i,t;
  BuildMaxHeap();/*��������*/    
  for(i=n;i>=2;i--)
  {
    t=a[1];a[1]=a[i];a[i]=t;/*��a[i]��a[1]����*/
    --heapsize; /*�޳��������Ԫ��a[i]*/               
    maxheapify(1);/*ά����������*/                
  }    
  return ;      
}

int main()
{
  int i;
  cin>>n;
  for(i=1;i<=n;i++)
     cin>>a[i];
  heapsort();
  for(i=1;i<=n;i++)
     cout<<a[i]<<" ";   
  system("pause");        
  return 0;         
}
