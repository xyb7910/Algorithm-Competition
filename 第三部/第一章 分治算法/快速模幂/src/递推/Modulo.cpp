//����ģ��-���� 
#include<iostream>
using namespace std;

int a,b,n;
int a_b_mod_n(int a,int b,int n)
{
    int digit[32]={};
    int i,k,result=1;
    i=0;
    //��b����2����,������ΪҪ֪��b��ʱ������2��������Ҫ��������
    //��һ������Ĳ�����ֻ����֤b�Ķ����Ƹ�λ��0 ����1 �Ϳ����ˣ�
    //�������һ����������֤�����ԣ��������һ�����
    while(b)//����b=103,������Ϊ1100111,��digit[]��Ϊ11100110000......   
    {
       digit[i++]=b%2;
       b>>=1;
    } 
   
    for(k=i-1;k>=0;k--) //����a^b mod n
    {  
       result=(result*result)%n;
       if(digit[k]==1)
         result=(result*a)%n;
    }
    return result;
}

int main()
{
  freopen("Modulo.in", "r", stdin);
  freopen("Modulo.out","w",stdout);    
  cin>>a>>b>>n;
  cout<<a_b_mod_n(a,b,n); 
  return 0;   
}
