//check 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
bool work(int d[4],int b[3],int c[3])
{
    int i,j;
    int e[3]={0,0,0};
    int *a[4]={d,d+1,d+2,d+3};
    for(i=0,j=0;i<3;i++,j++)
    {
        switch(b[i])
        {
            case 1:
                e[j]=*a[c[i]]+*a[c[i]+1];
                break;
            case 2:
                e[j]=*a[c[i]]-*a[c[i]+1];
                break;
            case 3:
                e[j]=*a[c[i]]**a[c[i]+1];
                break;
            case 4:
                if(*a[c[i]+1]==0 || *a[c[i]]%*a[c[i]+1]!=0) return 0;
                e[j]=*a[c[i]] / *a[c[i]+1];
                break;
        }
        if(i==1&&c[0]==1)
        {
            if(c[i]==0)
                a[c[i]+2]=&e[j];
            else
                a[c[i]-1]=&e[j];
        }
        a[c[i]+1]=a[c[i]]= &e[j];
    }
    if(e[2]!=24) return 0;
    return 1;
}
bool check(int a[])
{
    int b[3];
    int c[3]={0,1,2};
    do
    {
        for(b[0]=1;b[0]<=4;b[0]++) 
        for(b[1]=1;b[1]<=4;b[1]++)
        for(b[2]=1;b[2]<=4;b[2]++)
        if(work(a,b,c))
            return 1;
    }while(next_permutation(c,c+3));
    return 0;
}

int main()
{
    FILE *in1=fopen("24.out","r");
    FILE *in2=fopen("24.in","r");
    int hash[100000]={0},i,a,b,c;
    int *h=&hash[50000];//ģ�⸺�±����飬��¼һ�����ֿ���ʹ�õĴ���,���һ������ʹ�ô���������ʹ�õĴ���,�������� 
    int k[4];
    char op1,op2;
    
    for(i=1;i<=4;i++)
    {
        fscanf(in2,"%d",&k[i-1]);
        h[k[i-1]]++;//��������ֿ�ʹ�ô������� 
    }
    
    if(check(k)==0)//���ñ���ж��Ƿ��޽⣬��Ϊ�н�ʱ������������ܲ�ͬ,ֻ���޽�ʱ�����NO 
    {
        char t[100]="";
        fscanf(in1,"%s",t);
        if(   strcmp(t,"No")==0
            ||strcmp(t,"NO")==0
            ||strcmp(t,"nO")==0
            ||strcmp(t,"no")==0)
            return 0;
        return 1;//���أ���ʾ���г���,������������� 
    }
    
    for(i=1;i<=3;i++)
    {
        fscanf(in1,"%d%c%d%c%d",&a,&op1,&b,&op2,&c);//����𰸲��� 
        if(op2!='=') return 1;
        h[a]--;
        h[b]--;
        if(h[a]<0 || h[b]<0) return 1;//����ʹ�ó�����,��𰸴��� 
        h[c]++;//�����µ����� 
        
        switch(op1)
        {
            case '+':
                if(a+b!=c) return 1;
                break;
            case '-':
                if(a-b!=c) return 1;
                break;
            case '*':
                if(a*b!=c) return 1;
                break;
            case '/':
                if(b==0 || a%b!=0) return 1;
                if(a/b!=c) return 1;
                break;
        }
    }
    
    if(c!=24) return 1;
    
    printf("Right!\n");
    return 0;
}
