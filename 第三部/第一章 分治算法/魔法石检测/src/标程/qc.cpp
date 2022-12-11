//�������ʼ�Ա 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long LL; 

LL n,m,s;
int value[200005],weight[200005];
int ST[200005],END[200005];//�������� 
LL sum[200005],sumv[200005];

void work(LL S)
{
  sum[0]=sumv[0]=0ll;//long long�ͺ������ҪҪll 
  for(int i=1;i<=n;i++)
    if(weight[i]>=S)
    {
      sum[i]=sum[i-1]+1;//ǰ��ͼ��� 
      sumv[i]=sumv[i-1]+value[i];
    }
    else 
      sumv[i]=sumv[i-1],sum[i]=sum[i-1];
}
LL calc(LL MID)//�����ֵ 
{
  LL checkans=0ll;
  for(int i=1;i<=m;i++)
    checkans+=(sum[END[i]]-sum[ST[i]-1])*(sumv[END[i]]-sumv[ST[i]-1]);
  return checkans;
}

LL myabs(LL num)//ȡnum�ľ���ֵ 
{
  if(num>0) 
    return num;
  else 
    return -num;
}

LL max(LL a,LL b)
{
  if(a>b) 
    return a;
  else 
    return b;
}

int main()
{
  freopen("qc.in","r",stdin);
  freopen("qc.out","w",stdout);  
  LL start=0ll,end=0ll;//�Ͻ���½� 
  cin>>n>>m>>s;
  for(int i=1;i<=n;i++)
  {
    scanf("%d %d",&weight[i],&value[i]);
    end=max(weight[i],end);//�ҳ����ص� 
  }
  for(int i=1;i<=m;i++) 
    scanf("%d %d",&ST[i],&END[i]);
  LL ans=9223372036854775807ll; 
  while(start<=end)//���ֲ��� 
  {    
    LL mid=(start+end)/2;
    work(mid);
    LL t=calc(mid);
    if(myabs(t-s)<ans) 
      ans=myabs(t-s);
    if(ans==0) 
      break;
    if(s<t) 
      start=mid+1;
    else 
      end=mid-1;      
  }
  cout<<ans<<endl;
  return 0;
}
