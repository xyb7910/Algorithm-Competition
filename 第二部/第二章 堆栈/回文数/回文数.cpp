//�жϻ�����
#include <iostream>
using namespace std;
#define MAXCHAR 40
struct node
{
  char data;
  struct node *next;
};

int ishs(struct node *head,int n)
{
  char stack[MAXCHAR/2];
  struct node *p=head;
  int top=0;
  while (top<n/2)   /*��ǰ�벿��Ԫ����ջ*/
  {
    stack[top]=p->data;
	top++;p=p->next;
  }
  if (n%2==1)  /*nΪ����*/
    p=p->next;
    top--;
  while (top>=0 && p!=NULL && stack[top]==p->data)  /*����ջ�߱Ƚ�*/
  {
    top--;p=p->next;
  }
  if (top==-1 && p==NULL)  /*��ջ��������Ƚ����,���ǻ�����*/
    return(1);
  else
    return(0);    /*�����ǻ�����*/
  }
 
int main()
{
  char s[MAXCHAR];
  struct node *head=NULL,*p,*q;
  int i=0;
  printf("����һ����:");
  scanf("%s",s);
  while (s[i]!='\0')  /*�����ַ����ĵ�����*/
  {
	p=(struct node *)malloc(sizeof(struct node));
	p->data=s[i];p->next=NULL;
	if (head==NULL)
	{
	   head=p;q=p;  /*q����ָ�����һ�����*/
	}
	else
	{
	  q->next=p;q=p;
	}
	i++;  /*iΪhead����ĳ���*/
  }
  if (ishs(head,i))
    printf("%s�ǻ�����\n",s);
  else
    printf("%s���ǻ�����\n",s);
  system("pause");  
}
