//���ȶ��� 
#include<iostream>
#include<windows.h>
#define MAXH 100000/*�������Ԫ������ + 1*/
#define INF 0xffffff
using std::cin;
using std::cout;

int n,heapsize;/*�ѵĴ�С*/
int a[MAXH];/*����Ԫ�ص�ֵ*/

void maxheapify(int i)//ά������
{
  int l,r,largest,t;
  
  l=i<<1; //����ýڵ�����Һ��� 
  r=(i<<1)+1;    
  
  if(l<=heapsize && a[i]<a[l])//��¼���Ԫ�ص��±�
    largest=l;
  else
    largest=i;
  if(r<=heapsize && a[r]>a[largest])          
    largest=r; 
  //�������Ԫ����i��ֵ,�����еݹ��齻����Ľڵ��Ƿ�������������
  if(largest != i)
    {
      t=a[i];a[i]=a[largest];a[largest]=t;
      maxheapify(largest);
    }
  return ;         
}

void BuildMaxHeap()//��������
{
  int i;
  heapsize=n;    
  for(i=n/2;i>=1;i--)
    maxheapify(i);
  return ;       
}

int ExtractMax(int a[])//���������ض������Ԫ��
{
  int max;   
  max=a[1];
  a[1]=a[heapsize]; 
  a[heapsize]=-1;  
  heapsize--;
  maxheapify(1);//ά��������ѵ�����   
  return max;    
}

void HeapIncreaseKey(int i,int key)//�ı�ڵ㵱ǰ��ֵ
{
  int t;
  if(a[i]>key)//���ĵ�ֵ����Ҫ���ڵ�ǰ��ֵ
  {
    cout<<"CURRENT VERX BIGGER THAN KEY\n";
    return;
  }
  a[i]=key;   
  while(i>1 and a[i>>1]<a[i])/*��ת�����ֶѵ�����*/
  {
    t=a[i];a[i]=a[i>>1];a[i>>1]=t;i=i>>1;
  }   
  return ;    
}

void MaxHeapInsert(int key)//�����в���һ��Ԫ��
{
  heapsize++;
  a[heapsize]=-INF;//��ʼ������Ԫ��
  HeapIncreaseKey(heapsize,key);//����Ԫ��
  return;   
}

int main()//��ʾ����
{
  int i,key,v;       
  cin>>n;
  for(i=1;i<=n;i++)        
    cin>>a[i];     
  BuildMaxHeap();//������ 
   
  while(1)
  { 
    system("cls");    
    cout<<"Please Insert A Instruction:\n";
    cout<<"1.Show max verx\n";//�����������ֵ 
    cout<<"2.push max verx\n";//�������ֵ���� 
    cout<<"3.Change verx\n";//�ı�ĳԪ�ص�����ֵ 
    cout<<"4.Insert new Verx\n";//�����µ�Ԫ�� 
    cout<<"Other.Exit\n";  
    Gout(1,40,6,0,20);  
    cin>>i;
    if(i==1)
	  cout<<a[1]<<"\n";
    else if(i==2)
	  cout<<ExtractMax(a)<<"\n";
    else if(i==3)
    {
      cin>>v>>key;
      HeapIncreaseKey(v,key);
    }
    else if(i==4)
    {
      cin>>key;
      MaxHeapInsert(key);
    }
    else
	  break;    
    getchar();    
  }
}
