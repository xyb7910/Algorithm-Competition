#include<fstream>
#include<iomanip>
#define MAX 1577
using namespace std;
ifstream cin("encounter.in");
ofstream cout("encounter.out");
int n,m;
double f[MAX][MAX>>1];//Ϊ���㶯�棬�����������1��ʼ 
int inline d(int x,int y){return 2+(x>1 && x<n)+(y<m);}//��(x,y)��ѡ���� 
int inline minn(int ax,int bx){return ax<=bx?ax:bx;} //ȡ������Сֵ 
int inline maxn(int ax,int bx){return ax>=bx?ax:bx;}//ȡ�������ֵ 
int inline absn(int ax){return ax>=0?ax:-ax;}
double Dp(){
    if(m&1^1)//��ʼ��ż�ж� 
        return 0;
    int i,j,k,end_k,end_j;
    for(i=n;i>=0;f[i--][0]=1)//����   
        for(j=maxn(i,m+1-i),end_j=minn(n,m+1+i);j<=end_j;++j){//�Ż�6���Ż�7 
            if(j-i&1^1)//���������ϵĸ��ӵ�ת�� 
                f[j][0]=(f[j][1]+f[j][1]+f[j+1][0]+f[j-1][0])/d(j,0);
            for(k=2-(j-i&1),end_k=minn(minn(j-i,m),i-absn(m+1-j));k<=end_k;k+=2)
            //k=2-(j-i&1)�ҵ�ͬɫλ��;j-iΪ�Ż�7 ; m���ƾ����Ż���ľ���;
            // i-absn(m+1-j)Ϊ�Ż�6;��������Ϊ2,�Ż�3 
                f[j][k]=(f[j+1][k]+f[j-1][k]+f[j][k+1]+f[j][k-1])/d(j,k);
                //���������ϵĸ��ӵ�ת�� 
        }
    return f[m+1][0];
}
int main(){
    cin>>n;
    m=n>>1;
    cout<<fixed<<setprecision(4)<<Dp()<<'\n';
    return 0;
}
