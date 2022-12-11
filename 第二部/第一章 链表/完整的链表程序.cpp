// ��������
#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct List *link;
typedef struct List Lnode;

struct List
{
  ElemType data;
  struct List *next;
};

link setnull(link Head)
{
  link p;
  p=Head;
  while(p!=NULL)
  {
    p=p->next;
    free(Head);
    Head=p;
  }
  return Head;
}

link insert(link Head,ElemType x,int i)
{
  link NewPoint,p=Head;
  int j=1;
  NewPoint=(link)malloc(sizeof(Lnode));
  NewPoint->data=x;
  if(i==1)
  {
    NewPoint->next=Head;
    Head=NewPoint;
  }
  else
  {
    while(j<i-1 && p->next!=NULL)
    {
      p=p->next;
      j++;
    }
    if(j==i-1)
    {
      NewPoint->next=p->next;
      p->next=NewPoint;
    }
    else  printf("����Ԫ��ʧ��,�����ֵ����!");
  }
  return Head;
}

link create(link Head)
{
  ElemType newData;
  link NewPoint;

  Head=(link)malloc(sizeof(Lnode));
  printf("����������Ԫ��ֵ: \n");
  scanf("%d",&newData);
  Head->data=newData;
  Head->next=NULL;

  while(1)
  {
    NewPoint=(link)malloc(sizeof(Lnode));
    if(NewPoint==NULL)
      break;
    printf("����������Ԫ��ֵ: ����������'-1'\n");
    scanf("%d",&newData);
    if (newData==-1)
      return Head;
    NewPoint->data=newData;
    NewPoint->next=Head;
    Head=NewPoint;
  }
  return Head;
}

int lenth(link Head)
{
  int len=0;
  link p;
  p=Head;
  while(p!=NULL)
  {
    len++;
    p=p->next;
  }
  return len;
}

ElemType get(link Head,int i)//������bug,�ܷ����� 
{
  int j=1;
  link p;
  p=Head;
  while(j<i && p!=NULL)
  {
    p=p->next;
    j++;
  }
  if(p!=NULL)
    return(p->data);
  else
    printf("�������ݴ���!");
  return -1;
}

int locate(link Head,ElemType x)
{
  int n=0;
  link p;
  p=Head;
  while(p!=NULL && p->data !=x)
  {
    p=p->next;
    n++;
  }
  if(p==NULL)
    return -1;
  else
    return n+1;
}

void display(link Head)
{
  link p;
  p=Head;
  if(p==NULL)
    printf("\n����Ϊ��\n");
  else
    do
    {
      printf("%d ",p->data);
      p=p->next;
    }
    while(p!=NULL);
  printf("\n");
}

link connect(link Head1,link Head2)
{
  link p;
  p=Head1;
  while(p->next !=NULL)
  {
    p=p->next;
  }
  p->next=Head2;

  return Head1;
}

link del(link Head,int i)
{
  int j=1;
  link p,t;
  p=Head;
  if(i==1)
  {
    p=p->next;
    free(Head);
    Head=p;
  }
  else
  {
    while(j<i-1 && p->next !=NULL)
    {
      p=p->next;
      j++;
    }
    if(p->next!=NULL && j==i-1)
    {
      t=p->next;
      p->next=t->next;
    }

    if(t!=NULL)
      free(t);
  }
  return Head;
}

int main()
{
  int l;
  link head1;
  link head2;

  head1=create(head1);
  printf("\n����1Ϊ\n");
  display(head1);

  head2=create(head2);
  printf("\n����2Ϊ\n");
  display(head2);

  connect(head1,head2);
  printf("\n����ϲ�Ϊ\n");
  display(head1);
  while(1)
  {
    system("cls");//��������
    display(head1);
    printf("�����˵���\n");
    printf("  1.���������\n");
    printf("  2.��ȡ�����n��Ԫ��ֵ\n");
    printf("  3.����������ĳ��Ԫ�ص�λ��\n");
    printf("  4.����ĳԪ�ص�����\n");
    printf("  5.ɾ�������е�n��Ԫ��\n");
    printf("  6.�������\n");
    int Choice,x,y;
    scanf("%d",&Choice);
    switch(Choice)
    {
      case 1:
        printf("������Ϊ %d\n",lenth(head1));
        break;
      case 2:
        printf("������Ҫ���ҵ�Ԫ��ֵλ��\n");
        scanf("%d",&x);
        printf("ֵΪ %d\n",get(head1,x));
        break;
      case 3:
        printf("������Ҫ���ҵ�Ԫ��ֵ\n");
        scanf("%d",&x);
        printf("λ���� %d\n",locate(head1,x));
        break;
      case 4:
        printf("������Ҫ�����ֵ��λ��\n");
        scanf("%d%d",&x,&y);
        head1=insert(head1,x,y);
        break;
      case 5:
        printf("������Ҫɾ��Ԫ�ص�λ��\n");
        scanf("%d",&x);
        head1=del(head1,x);
        break;
      case 6:
        head1=setnull(head1);
    }
    display(head1);
    system("pause");
  }
  return 0;
}


