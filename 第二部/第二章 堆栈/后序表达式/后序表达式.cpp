//����ʽֵ
#include <iostream>
using namespace std;
#define MAX 100
char exp[MAX];   /*�洢ת���ɵĺ�׺���ʽ*/

void trans()     /*���������ʽת���ɺ�׺���ʽ*/
{
  char str[MAX];   /*�洢ԭ�������ʽ*/
  char stack[MAX]; /*��Ϊջʹ��*/
  char ch;
  int sum,i,j,t,top=0;
  /*t��Ϊexp���±�,top��Ϊstack���±�,i��Ϊstr���±�*/
  printf("***************************************************************\n");
  printf("* ����һ����ֵ�ı��ʽ,��#������ֻ�ܰ���+,-,*,/������������� *\n");
  printf("***************************************************************\n");
  printf("�������ʽ:");
  i=0;   /*��ȡ�û�����ı��ʽ*/
  do
  {
    i++;
    scanf("%c",&str[i]);
  }
  while (str[i]!='#' && i!=MAX);
  sum=i; /*��¼������ʽ�ܵ��ַ�����*/
  t=1;
  i=1;
  ch=str[i];
  i++;
  while (ch!='#')
  {
    switch(ch)
    {
      case '(':  /*�ж�Ϊ������*/
        top++;
        stack[top]=ch;
        break;
      case ')':  /*�ж�Ϊ������*/
        while (stack[top]!='(')
        {
          exp[t]=stack[top];
          top--;
          t++;
        }
        top--;
        break;
      case '+':   /*�ж�Ϊ�Ӽ���*/
      case '-':
        while (top!=0 && stack[top]!='(')
        {
          exp[t]=stack[top];
          top--;
          t++;
        }
        top++;
        stack[top]=ch;
        break;
      case '*':  /*�ж�Ϊ'*'��'/'��*/
      case '/':
        while (stack[top]=='*' || stack[top]=='/')
        {
          exp[t]=stack[top];
          top--;
          t++;
        }
        top++;
        stack[top]=ch;
        break;
      case ' ':
        break;
      default:
        while (ch>='0' && ch<='9') /*�ж�Ϊ����*/
        {
          exp[t]=ch;
          t++;
          ch=str[i];
          i++;
        }
        i--;
        exp[t]='#';
        t++;
    }
    ch=str[i];
    i++;
  }
  while (top!=0)
  {
    exp[t]=stack[top];
    t++;
    top--;
  }
  exp[t]='#';
  printf("\n\tԭ�����ʽ:");
  for (j=1; j<sum; j++) printf("%c",str[j]);
  printf("\n\t��׺���ʽ:",exp);
  for (j=1; j<t; j++)
    printf("%c",exp[j]);
}

void compvalue()  /*�����׺���ʽ��ֵ*/
{
  float stack[MAX],d; /*��Ϊջʹ��*/
  char ch;
  int t=1,top=0;  /*t��Ϊexp���±�,top��Ϊstack���±�*/
  ch=exp[t];
  t++;
  while (ch!='#')
  {
    switch (ch)
    {
      case '+':
        stack[top-1]=stack[top-1]+stack[top];
        top--;
        break;
      case '-':
        stack[top-1]=stack[top-1]-stack[top];
        top--;
        break;
      case '*':
        stack[top-1]=stack[top-1]*stack[top];
        top--;
        break;
      case '/':
        if (stack[top]!=0)
          stack[top-1]=stack[top-1]/stack[top];
        else
        {
          printf("\n\t�������!\n");
          exit(0);/*�쳣�˳�*/
        }
        top--;
        break;
      default:
        d=0;
        while (ch>='0' && ch<='9')   /*�ж�Ϊ�����ַ�*/
        {
          d=10*d+ch-'0';  /*�������ַ�ת���ɶ�Ӧ����ֵ*/
          ch=exp[t];
          t++;
        }
        top++;
        stack[top]=d;
    }
    ch=exp[t];
    t++;
  }
  printf("\n\t������:%g\n",stack[top]);
}

int main()
{
  trans();
  compvalue();
  system("pause");
}
