/*
�������ƣ�N�ʺ����⣨�ǵݹ�+�����Ż��� 
����˵����
 
�������ߣ�ZXH (2010-3-30)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 

#include <iostream>
using namespace std;
const int MAXN=20;
int n,n1;//���̴�С 
int a[MAXN];//���浱ǰ��
short pre[MAXN],next[MAXN];//˫�������Ż�
short cd1[2*MAXN],cd2[2*MAXN];//�Խ����Ż�
long s=0,s1=0;//�����ܷ����� 

void init()
{
  cin>>n;
  n1=n/2+1;
  memset(cd1,0,sizeof(cd1));//�Խ��߳�ʼ�� 
  memset(cd2,0,sizeof(cd2));
  for(int i=1;i<=n;i++)//�����ʼ�� 
  {
    pre[i]=i-1;
    next[i]=i+1;
  }
  pre[n+1]=n;next[0]=1;//�ڱ�
}

void Doit()
{
  int dp=1,flag=0;
  do
  {
    if(a[1]<=n1)
    {
      if(dp>n)
      {
        if(a[1]==n1)
          s1++;
        else
          s++;
        dp--;
        cd1[dp-a[dp]+n]=0;
        cd2[dp+a[dp]]=0;
        next[pre[a[dp]]]=a[dp];
        pre[next[a[dp]]]=a[dp];
        a[dp]=0;
        dp--;
      }
      else
      {
        if(a[dp]!=0)
        {
          cd1[dp-a[dp]+n]=0;
          cd2[dp+a[dp]]=0;
          next[pre[a[dp]]]=a[dp];
          pre[next[a[dp]]]=a[dp];
        }
        int i=a[dp];
        i=next[i];
        while(i<=n && (cd1[dp-i+n] || cd2[dp+i]))
          i=next[i];
        if(i>n)
        {
          a[dp]=0;
          dp--;
          continue;
        }        
        cd1[dp-i+n]=1;
        cd2[dp+i]=1;
        next[pre[i]]=next[i];
        pre[next[i]]=pre[i];
        a[dp]=i;
        dp++;
      }
    }
  }while(a[1]<=n1);      
}


int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  init();
  Doit();
  
  if(n%2==0)//������ 
    s*=2;
  else
    s=2*s+s1;
  cout<<s<<endl; 
  return 0;
}           


