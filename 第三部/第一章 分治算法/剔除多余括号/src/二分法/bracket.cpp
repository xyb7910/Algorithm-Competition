//�޳���������-���ַ� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[1024];//a,s������Ԫ��һһ��Ӧ��a[i]���s[i]�Ƿ���� 
char s[1024];

int cal(int begin, int end, int prev_min)
{
  int t, min=4, min_i;
  for (int i=begin; i<=end; i++)//ɨ�������ַ���,�ҳ��������� 
  {
    switch (s[i])
    {
      case '^':
		if (min>3) 
          min=3, min_i=i;//���"^"��������ȼ�Ϊ3 
        break;
      case '*': 
      case '/':
		if (min>2) 
          min=2, min_i=i;//���"*"��"/"��������ȼ�Ϊ2 
		break;
      case '+': 
      case '-':
	    if (min>1) 
          min=1, min_i=i;//���"+"��"-"��������ȼ�Ϊ1 
		break;
      case '('://���������ţ����ҵ���֮ƥ��������ţ������������ڵ��ַ� 
		i++;
		for (t=1;t!=0;i++)
		{
		  if (s[i]=='(') //�������ڶ��������ź������ŵĴ��� 
            t++;
		  if (s[i]==')') 
            t--;
		}
		i--;
		break;
    };
  }

  if (min==4)//ȥ���Ų��� 
  {
     if (s[begin]=='(' && s[end]==')')//�����β��Ϊ���� 
     {
        t=cal(begin+1,end-1,0);//�����ȥ��β���ż����ݹ�ķ���ֵmin 
        if (t>=prev_min)
        {
          a[begin]=a[end]=1;//����β�����ű��Ϊ���� 
          return t;
        }
     }
     return 4;
  }

  cal(begin,min_i-1,min);//�ݹ���������ǰ�˵�ʽ�� 
  if (s[min_i]=='+' || s[min_i]=='*')
    cal(min_i+1,end,min);//�ݹ�����������˵�ʽ�� 
  else
    cal(min_i+1,end,min+1);//�ݹ����ȥ������˵�ʽ�ӣ����������ȼ�+1 
  return min;
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);  
  cin>>s;
  int sc=strlen(s);
  cal(0,sc-1,0);
  for (int i=0;i<sc;i++) 
    if (!a[i])//��ǰλ���Ϊ0������� 
      cout<<s[i];   
  cout<<'\n';
  return 0;
}
