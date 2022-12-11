/*zz
�������ƣ�N�ʺ����⣨DFS+�����Ż��� 
����˵�������Ż������еݹ飬��ʱO��1��
���Ż���˫����NOIר����10��P20ҳ����˫����ʵ���������Ż���
 
�������ߣ�ZXH (2010-3-30)
����ע�������ļ�Ϊsort.in,����ļ�Ϊsort.out,N<=100000
*/ 

#include <iostream>
#define MAXN 20
using namespace std;

int n,n1;//���̴�С 
short djx1[2*MAXN],djx2[2*MAXN];//�Խ����Ż�
short pre[MAXN],next[MAXN];//˫�������Ż�
int a[MAXN];//���浱ǰ��
long s=0,s1=0;//�����ܷ����� 

void N_QUEEN(int dp)
{
  int i=0;
  do
  {
    i=next[i];
    if(i>n)
      break;
    if(djx1[dp+i] && djx2[dp-i+n])
    { //�ԶԽ��ߺ�˫��������޸ģ�ȥ��i��� 
      djx1[dp+i]=0;djx2[dp-i+n]=0;
      next[pre[i]]=next[i];pre[next[i]]=pre[i];
      a[dp]=i;
      if(dp==n)
      {
        if(a[1]==n1)
          s1++;
        else
          s++;
      }
      else
        N_QUEEN(dp+1);
      djx1[dp+i]=1;//��ԭi���ĶԽ��ߺ�˫���� 
      djx2[dp-i+n]=1;
      next[pre[i]]=i;
      pre[next[i]]=i;
    }
  }while(a[1]<=n1);
  return;
}

void init()
{
  cin>>n;
  n1=n/2+1;
  for(int i=1;i<=n;i++)//�����ʼ�� 
  {
    pre[i]=i-1;
    next[i]=i+1;
  }
  pre[n+1]=n;next[0]=1;//�ڱ� 
  memset(djx1,1,sizeof(djx1));//�Խ��߳�ʼ�� 
  memset(djx2,1,sizeof(djx2));
  return;
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  init();
  N_QUEEN(1);
  
  if(n%2==0)//������ 
    s*=2;
  else
    s=2*s+s1;
  cout<<s<<endl; 
  return 0;
}           


