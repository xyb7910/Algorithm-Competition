//��Ӳ��2
#include<iostream>
#define maxx(a,b) (a>b?a:b)
using namespace std;

int n,m,ans,sum;
int num[1024];
int hun[50000]; //ÿ��״̬ 
bool a;

int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<(1<<m);++i)
        for(int j=i;j>0;j>>=1)
            num[i]+=j&1;    //���1��1023������1���� 
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            cin>>a;
            hun[i]=(hun[i]<<1)+a;
        }
    for(int i=0;i<(1<<m);++i)//ö���� 
    {
        for(int j=0;j<n;++j)//�ı�״̬ 
            hun[j]^=i;
        sum=0;
        for(int j=0;j<n;++j)//�������ֵ 
            sum+=maxx(num[hun[j]],num[hun[j]]^((1<<m)-1));
        ans=maxx(ans,sum);
        for(int j=0;j<n;++j)//״̬�Ļ� 
            hun[j]^=i;
    }
    cout<<ans<<"\n";
    return 0;
}
