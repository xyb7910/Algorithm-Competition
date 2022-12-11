//��г���ֲ��Ż��㷨 
#include<stdio.h>
#include<stdlib.h>
int a[100001];//aֵ 
int b[100001];//bֵ 
int link[100001];
int Long[100001];
int p[100001];
int n,max;

void swap(int &a,int &b)
{
  int temp;
  temp=a,a=b,b=temp;
}

void sort(int L,int R)//���� 
{
  if(L>=R)  return;
  int i=L,j=R;
  int cmp=p[(L+R)/2];
  while(i<=j)
  {
    while(a[p[i]]<a[cmp]||(a[p[i]]==a[cmp]&&b[p[i]]>b[cmp])) i++;
    while(a[p[j]]>a[cmp]||(a[p[j]]==a[cmp]&&b[cmp]>b[p[j]])) j--;
    if(i<=j)
      swap(p[i++],p[j--]);//ע��˴���λ�� 
     }
  sort(L,j);
  sort(i,R);
}

int find(int key)//���ֲ��� 
{
  int L=1,R=max,mid;
  while(L<=R)
  {
    mid=(L+R)/2;
    if(b[Long[mid]]<key)
      L=mid+1;
    else R=mid-1;
  }
  return L-1;
}

int main()
{
  freopen("Beautiful.in","r",stdin);
  freopen("Beautiful.out","w",stdout); 
  int i,j,k,l;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d%d",&a[i],&b[i]);
    p[i]=i;//���±� 
  }
  sort(1,n);//��A���п���,�����ı��±�p��λ��,A,Bλ�ò��� 
    
  max=1;//������� 
  Long[max]=p[1];//��ʼΪ��1��Ԫ�� 
  link[1]=p[1];//��ʼ��Ϊ��1��Ԫ�� 
  for(i=2;i<=n;i++)
  {
    if(b[p[i]]>b[Long[max]]) 
    {
      max++;
      Long[max]=p[i];
      link[p[i]]=Long[max-1];
    }
    else
    {
      l=find(b[p[i]]);
      Long[l+1]=p[i];
      link[p[i]]=Long[l];
    }
  }
  printf("%d\n",max);//���������� 
  k=max;i=Long[max];
  while(max>0)
  {
    Long[max]=i;
    i=link[i];
    max--;
  }
  for(i=1;i<=k;i++)
    printf("%d ",Long[i]);
  return 0;  
}
