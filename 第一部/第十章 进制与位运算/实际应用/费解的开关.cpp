//�ѽ�Ŀ���
#include<iostream>
using namespace std;

int n,sum;
int atjin[1000000],ans[1000000];    //��ϣ�͹�ϣ�����ֵ 
bool a,b[7][7];
int x[6],y[6];

int haxi(int x)     //��ϣ�� 
{
    int at=x%813289;
    while(atjin[at]!=x && atjin[at]!=0)
        at++;
    atjin[at]=x;
    return at;
}

void fst(int h,int xx,int yy)
{
    if(h>=6 || yy>=5)
    {
        for(int j=1;j<=5;++j)
            for(int k=1;k<=5;++k)
                b[j][k]=1;
        for(int i=0;i<h;++i)    //״̬�ı� 
        {
            b[x[i]][y[i]]^=1;
            b[x[i]+1][y[i]]^=1;
            b[x[i]-1][y[i]]^=1;
            b[x[i]][y[i]+1]^=1;
            b[x[i]][y[i]-1]^=1;
        }
        sum=0;
        for(int j=1;j<=5;++j)
            for(int k=1;k<=5;++k)
                sum=(sum<<1)+b[j][k];   //����״̬ѹ�����ֵ 
        ans[haxi(sum)]=h;
        return ;
    }
    x[h]=xx;
    y[h]=yy;
    fst(h+1,(xx+1)%5,yy+(xx+1)/5);
    fst(h,(xx+1)%5,yy+(xx+1)/5);
}

int main()
{
    memset(ans,-1,sizeof(ans));
    fst(0,0,0);     //��������״̬����С���� 
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        sum=0;
        for(int i=1;i<=5;++i)
            for(int j=1;j<=5;++j)
            {
                cin>>a;
                sum=(sum<<1)+a;
            }
        cout<<ans[haxi(sum)]<<"\n"; 
    }
    return 0;
}
