//�޳���������-�Ƕ��ַ� 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char v;
const int MAXN=10010;
char s[MAXN];
bool vis[MAXN];

int l,k,x,a,b,z,s1,s2,s3,y;
int Right;

void op(int k)//�жϵı��������е���ͼ�������� 
{
  for(int i=k;i<=Right;i++)
  {
    v=s[i];
    if(v == '-' || v == '+')
      return;
  }
}

void FirstLeft()//����������ҵ���һ�������� 
{
  for(int j=l-1;j>=0;j--)
    if(s[j] == '(')
    {
      s2=j;
      break;
    }
}

int FindRight(int Left)//Ѱ��һ�����ŵ�ƥ������ 
{
  int i;
  int ll;
  int count=1;
  for(i=Left+1;i<l;++i) 
  {
    if(i==l-1)
      ll=i; 
    if(!count)//�ҵ���ƥ��������ţ����˳� 
    {
      ll=i-1;
      break;
    }
    else
      if(s[i] == '(')
        count++;
      else if(s[i] == ')')
        count--;
  }
  return ll;
}

void desion()//�ж����ڲ������Ƿ��ɾ�� 
{
  for(int i=s2;i>=0;i--)//�����м�����ſ�ʼ����� 
  {
     if(s[i]=='(')
     {
       Right=FindRight(i);//�ҵ���ƥ��������� 
       op(i);//�ҵ���ͼ��������        
       if(i==0)//���������һ���ַ�����Ϊ����  
       {
         vis[i]=true;//�����ſ���ɾ�� 
         vis[Right]=true;//�����ſ���ɾ�� 
       }
       if(s[i-1]=='/')//��������ǰΪ/���򲻿�ɾ�� 
         continue;
       else if(s[i-1]=='*' || s[i-1]=='-' && v=='+' || v=='-')
         continue;//��������ǰΪ*,-������������������Ϊ+,-�򲻿�ɾ�� 
       else if(s[Right+1]=='/' || s[Right+1]=='*' && v=='+' || v=='-')
         continue;//��������Ϊ/��*,����������������Ϊ+,- �򲻿�ɾ�� 
       else//��ƥ�������bool��Ϊ�� 
       {
         vis[i]=true;
         vis[Right]=true;
       }
     }
  }      
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);  
  scanf("%s",s);
  l=strlen(s);
  FirstLeft();
  desion();
  for(int i=0;i<l;i++)
    if(!vis[i])//�����Ϊ����� 
       printf("%c",s[i]); 
  cout<<endl;
  system("pause");
  return 0;    
}
