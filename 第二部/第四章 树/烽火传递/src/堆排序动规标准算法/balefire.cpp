//��𴫵� 
#include <iostream>
using namespace std;
const int size=100;
int n,m,r,value[size],heap[size],pos[size],home[size],opt[size];
//heap[i]��ʾ��˳������洢�Ķ�heap�е�i��Ԫ�ص�ֵ
//pos[i]��ʾopt[i]�ڶ�heap�е�λ�ã���heap[pos[i]]=opt[i]
//home[i]��ʾheap[i]������opt�е�λ�ã���opt[home[i]=heap[i]

void swap(int i,int j)//�������еĵ�i���͵�j��Ԫ��
{
  int tmp;
  pos[home[i]]=j;
  pos[home[j]]=i;
  tmp=heap[i];
  heap[i]=heap[j];
  heap[j]=tmp;
  tmp=home[i];
  home[i]=home[j];
  home[j]=tmp; 
} 

void add(int k)//�ڶ��в���opt[k]
{
  int i;
  r++;
  heap[r]=opt[k];
  pos[k]=r;
  home[r] = k;
  i=r;
  while((i>1) && (heap[i]<heap[i/2]))
  {
    swap(i,i/2);
    i/=2;
  } 
}

void remove(int k)//�ڶ���ɾ��opt[k]
{
  int i,j;
  i=pos[k];
  swap(i,r);
  r--;
  if(i==r+1)
    return;
  while((i>1) && (heap[i]<heap[i/2]))
  {
    swap(i,i/2);
    i/=2;
  }
  while(i+i<=r)
  {
    if((i+i+1<=r) && (heap[i+i+1]<heap[i+i]))
      j=i+i+1;
    else
      j = i + i;
    if(heap[i]>heap[j])
    {
      swap(i, j);
      i=j;
    }
    else 
      break;
  }
} 
        
int main()
{
  int i;
  freopen("balefire.in","r",stdin);
  freopen("balefire.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=n;i++)
    cin>>value[i];
  r=0;  
  for(i=1;i<=m;i++)
  {
    opt[i]=value[i];
    add(i);                
  }  
  for(i=m+1;i<=n;i++)
  {
    opt[i]= value[i] + heap[1];
    remove( i - m);
    add(i);
  } 
  cout<<heap[1]<<endl;
  return 0;
}  
