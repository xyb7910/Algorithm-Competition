//��������
#include<iostream>
using namespace std;

int n,m,t,two;
bool a[1000000][2],in;  //�������� 

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i][0];   //���� 
    while(t<m)
    {
        two=-1;
        while(t+(1<<two+1)<=m)
            two++;      //�ҵ�����t+2^k<=m 
        for(int i=0;i<n;++i)
            a[i][in^1]=a[i][in]^a[(i-(1<<two)%n+n)%n][in];   //״̬ת�� 
        in^=1;
        t+=(1<<two);
    }
    for(int i=0;i<n;++i)
        cout<<a[i][in];
    cout<<"\n";    
    return 0;

}
