/*��Կ*/
#include <stdio.h>
struct Node
{
  int data;
  struct Node *next;
};

int main()
{
   struct Node *head,*s,*q,*t;
   int n,m,count=0,i;
   printf("������Ӹ���n m��:");
   scanf("%d,%d",&n,&m);
   for (i=1;i<=n;i++)
   {
     s=(struct Node *)malloc(sizeof(struct Node)); /*�������s*/
     s->data=i;
     s->next=NULL;
     if (i==1)  /*������ͷ���*/
     {
       head=s,q=head; /*head��Ϊ��ͷ���,q����ָ����������һ�����*/
     }
     else  /*�����������*/
     {
	   q->next=s;
	   q=q->next;
     }
   }
   q->next=head;  /*����ѭ��������*/
   printf("����ǰ:");
   q=head;  /*q��ָ���ͷ���*/
   while (q->next!=head)  /*��ʾ����ǰ��˳��*/
   {
     printf("%d ",q->data);q=q->next;
   }
   printf("%d\n",q->data);
   printf("���Ӻ�:");
   q=head;  /*q��ָ���ͷ���*/
   do
   {
     count++;  /*��������1*/
     if (count==m-1) /*��i�������˳�*/
     {
  	    t=q->next;        /*tָ��Ҫɾ���Ľ��*/
	    q->next=t->next;  /*ɾ�����t*/
	    count=0;          /*����������0*/
	    printf("%d ",t->data);
     }
	 q=q->next;
   } while (q->next!=q);    /*ѭ��ֱ��ֻʣһ�����*/
   printf("%d\n",q->data);  /*��ʾ����һ�����ֵ*/
   system("pause");
   return 0;
}
