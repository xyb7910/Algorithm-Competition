//�߾��������Ե;�����2
#include <iostream>
#define MAXN 100
using namespace std;
int remainder=0;//���� 
int a[MAXN+1],ans[MAXN+1];

void division(string str,int b, int *ans)
{
   int i,len; 
   len=str.size();
   for(i=1;i<=len;++i)//��ʼ��Ϊ���� 
     a[i]=str[i-1]-'0'; 
   
   for (i=1;i<=MAXN;i++ )//�������  
   {
     if(i==len+1)
       ans[0]=i;//��¼С����Ӧ���ֵ�λ�� 
     remainder = remainder * 10 + a[i];
	 ans[i] = remainder / b;
	 remainder = remainder % b;
	 if(remainder==0 && i>len)//����������������������ѱ����� 
	   break;
   }
}

void output(int *ans,int len)
{
   int i,begin=1,end=MAXN ;
   while(!ans[begin])
     begin++;//�ҳ��ʼ��λ�� 
   if (begin>ans[0])//�˴��Ƿ�ֹ����0.00000xxx���ʱ����ǰ���0���� 
     begin=ans[0];  
   while(!ans[end])
     end--;//�ҳ���ĩβ����Чλ�� 
   if(end<len)
     end=len;//��ֹ����X000000000��ʱ�򣬽���Чλ0��ȥ  
   if(ans[0]==begin)//��ֹ����0.XXXXX ��ʱ��ǰ��û�м�0. 
     cout<<'0';
   for(i=begin;i<=end;i++)
   { 
      if(i==ans[0])
        cout<<'.';   
       cout<<ans[i];
   }
   cout<<","<<remainder<<'\n';//������� 
}

int main()
{
   freopen("sample_div2.in","r",stdin);
   freopen("sample_div2.out","w",stdout);
   string str;
   int b;
   cin>>str;//����߾��ȱ����� 
   cin>>b;//����;��ȳ��� 
   if(b==0)
     cout<<"Divisor is 0"<<'\n';
   else
   {  
     division(str,b,ans);
     output(ans,str.size());
   }
   return 0;
}
