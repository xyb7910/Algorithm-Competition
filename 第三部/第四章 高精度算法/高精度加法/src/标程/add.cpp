//�򵥸߾��ȼӷ� 
#include <iostream>
#include <fstream>
#define MAXN 5001
using namespace std;
ifstream fin("add.in");
ofstream fout("add.out");

int add(int x[],int y[],int z[],int len)
{
  int i,j,r;
  for(j=0;j<len;++j)//���±�0��ʼ��λ��ӵ�len-1 
  { 
    z[j]+=x[j]+y[j];//��ӽ���浽z[] 
    for(i=j;i<len;++i)
    {
       if(z[i]>=10)//�����ǰλ����ֵ������10����Ҫ��λ���� 
       {	   
	      z[i+1]+=z[i]/10;//�˴����Ϊ++z[i+1]��Ч�ʸ��� 
	      z[i]-=10;       //������z[i]%=10,���ٶ����� 
          if(z[len]>0)//���λ�����λ�ˣ������λ����1 
	        len++;
	      if(z[i+1]<10)//С�Ż� 
	        break;
       }
    }
  }
  return len;//����λ�� 
}

void init(int x[],string str, int len)//�ַ���תΪ�������� 
{
  for(int i=0;i<len;i++) 
    x[len-i-1]=str[i]-'0';//����ת��     
}

void output(int z[],int len)//�����ӵĽ��
{
  for(int i=len-1;i>=0;i--)  
    fout<<z[i];
  fout<<"\n";
}

int main()
{
  string str1,str2;
  int a[MAXN]={0},b[MAXN]={0},z[MAXN]={0};//��ʼ��Ϊ0 
  int la,lb,len;
  fin>>str1>>str2;
  la=str1.size();
  lb=str2.size();
  init(a,str1,la);//��ʼ��Ϊ�������� 
  init(b,str2,lb);

  if(la>=lb)//ȷ��a��b�����λ��
    len=add(a,b,z,la); //ȡ�λ��la
  else
    len=add(b,a,z,lb);//ȡ�λ��lb
  output(z,len);
  fin.close();
  fout.close();
  return 0;
}
