//�򵥸߾��ȳ˷� 
#include<iostream>
#define MAXN 5001
using namespace std;

char str1[MAXN],str2[MAXN];
int a[MAXN],b[MAXN];

void multiply(int a[],int b[],int la,int lb) 
{
  int c[MAXN]={0},len,i,j,k,MaxLen=la+lb;
  for(i=0;i<lb;++i)       //��һ������
  { 
    for(j=la-1;j>=0;--j) //�ڶ�������
      c[j+i]+=b[i]*a[j]; //ע��˻������λ�� 
      
    for(k=0;k<MaxLen;++k)//��ĳλ��>=10��������������˴������Ż� 
      if(c[k]>=10)
      {
         c[k+1]+=c[k]/10;
         c[k]%=10; 
      }       
  } 
   
  for(i=k;c[i]==0;--i);//�������λ����ע��˴��и��ֺ� 
  len=i+1;//�˾���forѭ���޹� 

  for(i=len-1;i>=0;--i) //������ 
    cout<<c[i]; 
  cout<<'\n';       
}

void init(int x[],char str[],int len)//�ַ���תΪ�������� 
{
  for(int i=0;i<len;i++)
    x[len-i-1]=str[i]-'0';
}

int main()
{
  freopen("mul.in","r",stdin);
  freopen("mul.out","w",stdout);     
  int la,lb;
  std::ios::sync_with_stdio(false);//ȡ��cin��stdin��ͬ���Լӿ��ȡ�ٶ� 
  cin>>str1>>str2;
  la=strlen(str1);
  lb=strlen(str2);
  if((la==1 && str1[0]=='0')||(lb==1 && str2[0]=='0')) 
    cout<<"0\n";
  else
  {  
    init(a,str1,la);//��ʼ��Ϊ�������� 
    init(b,str2,lb);
    multiply(a,b,la,lb);
  }
  return 0;
}
