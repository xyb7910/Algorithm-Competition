//���������
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long

ll D[N];                                   //��״����D,��������
ll Dxi[N];                                 //��״���飬D[i]*i��ǰ׺��
ll A[N];                                   //��ŵ�ǰ׺��
ll n,m;

ll lowbit(ll x)
{
  return x&(-x);
}

void Modify(ll x,ll val,ll *c)
{
  for(int i=x; i<=n; i+=lowbit(i))          //nΪ���鳤��
    c[i]+=val;
}

ll Getsum(ll x,ll *c)
{
  ll sum=0;
  for(int i=x; i>0; i-=lowbit(i))
    sum +=c[i];
  return sum;
}

int main()
{
  scanf("%lld%lld",&n,&m);
  for(int i=1; i<=n; i++)
  {
    scanf("%lld",&A[i]);
    A[i]+=A[i-1];                          //ֱ�Ӵ���Ϊǰ׺������
  }
  getchar();                               //�������з�
  string option;
  for(int i=1; i<=m; i++)
  {
    cin>>option;
    ll a,b,val;
    if(option=="C")
    {
      scanf("%lld%lld%lld",&a,&b,&val);
      Modify(a,val,D);                     //Dǰ׺�͸���
      Modify(b+1,-val,D);
      Modify(a,a*val,Dxi);                 //D*i��ǰ׺�͸���
      Modify(b+1,-(b+1)*val,Dxi);
    }
    if(option=="Q")
    {
      scanf("%lld%lld",&a,&b);
      ll Ans=A[b]-A[a-1];
      Ans+=Getsum(b,D)*(b+1)-Getsum(b,Dxi);
      Ans-=Getsum(a-1,D)*(a)-Getsum(a-1,Dxi);
      printf("%lld\n",Ans);
    }
  }
  return 0;
}
