//��Ӳ��1
#include<iostream>
#define maxx(a,b) (a>b?a:b)
using namespace std;

int n,m,ans,sum;
int num[1024];
int hun[50000][10];     //ÿ��״̬ 
int hn[10];         //��ǰ��״̬ 
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
            cin>>hun[i][j];
    for(int i=0;i<(1<<m);++i)//ö���� 
    {
        for(int k=i,j=m;j>0;--j)
        {
            hn[j]=k&1;
            k>>=1;
        }                  
        for(int j=0;j<n;++j)//�ı�״̬ 
            for(int k=0;k<m;++k)
                hun[j][k]^=hn[k];
        sum=0;
        for(int j=0;j<n;++j) //�������ֵ 
        {
            int temp=0;
            for(int k=0;k<m;++k)
                temp+=hun[j][k];
            sum+=maxx(temp,m-temp);
        }
        ans=maxx(ans,sum);
        for(int j=0;j<n;++j)//״̬�Ļ� 
            for(int k=0;k<m;++k)
                hun[j][k]^=hn[k];
    }
    cout<<ans<<"\n";
    return 0;
}
