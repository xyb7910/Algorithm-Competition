//�ݹ���۰���ҷ�
#include <bits/stdc++.h>
using namespace std;
int a[Max],key; 

int search(int bot,int top)//��bot~top��һ�β��� 
{
  int mid;
  if(top>=bot)
  {
    mid=(top+bot)/2;//ȡ�м�ֵmid 
    if(key==a[mid]) //������,���ӡ���� 
    {
      printf("%d\n",mid);
      return 0;
    }   
    else if(key<a[mid])  //��xС���м�ֵ, ��ȡǰ��� 
      search(bot,mid-1);
    else               //��x�����м�ֵ,��ȡ���� 
      search(mid+1,top);
  }      
  else 
  {
      printf("-1\n");
      return 0;
  }    
}

int main()
{
   freopen("half.in","r",stdin);
   freopen("half.out","w",stdout); 
   int n; 
   cin>>n;
   for(int i=1;i<=n;++i)
     cin>>a[i]; 
   cin>>key;
   search(1,n);
   return 0;
}



