//����һԪ����ʽ֮�� 
#include <stdlib.h>
#include <stdio.h>
typedef struct List *Link;
typedef struct List Lnode;

struct List
{
  int coef;//ϵ�� 
  int expn;//�� 
  struct List *next;
};

Link create()
{
  int a,n,i=1;
  Link Head,s,p;
  Head=(Link)malloc(sizeof(Lnode));
  Head->next=NULL;
  p=Head;
  do  
  {
    printf("\n�� %d ��->ϵ��,��:",i++);
    scanf("%d %d",&a,&n);
    if(a!=0 ||n!=0)
    {
      s=(Link)malloc(sizeof(Lnode));       
      s->coef=a;s->expn=n;s->next=NULL;
      p->next=s;p=s;
     
    }
  }while(a!=0 ||n!=0);
  printf("\n");
  return(Head->next);   
}

Link add(Link pa,Link pb)
{
  int n;
  Link pc,s,p;
  pc=(Link)malloc(sizeof(Lnode));
  pc->next=NULL;
  p=pc;
  while(pa!=NULL && pb!=NULL)//����������û�е�ĩβʱ 
  {
    if(pa->expn>pb->expn)     //��a���ݴ���b���� 
    {
      s=(Link)malloc(sizeof(Lnode));
      s->coef=pa->coef;s->expn=pa->expn;
      s->next=NULL;p->next=s;p=s;
      pa=pa->next;
    }
    else if(pa->expn<pb->expn)//��a����С��b����
    {
      s=(Link)malloc(sizeof(Lnode));
      s->coef=pb->coef;s->expn=pb->expn;
      s->next=NULL;p->next=s;p=s;
      pb=pb->next;    
    }
    else                     //��a���ݵ���b����
    {
      n=pa->coef+pb->coef;
      if(n!=0)
      {
         s=(Link)malloc(sizeof(Lnode));
         s->coef=n;s->expn=pb->expn;s->next=NULL;
         p->next=s;p=s;
      }
      pa=pa->next;pb=pb->next;      
    }
  }                 
  while(pa!=NULL)    //��a��������ʱ 
  {
    s=(Link)malloc(sizeof(Lnode));
    s->coef=pa->coef;s->expn=pa->expn;
    s->next=NULL;p->next=s;
    p=s;pa=pa->next;
  }             
  while(pb!=NULL)�� //��b��������ʱ 
  {
    s=(Link)malloc(sizeof(Lnode));
    s->coef=pb->coef;s->expn=pb->expn;
    s->next=NULL;p->next=s;
    p=s;pb=pb->next;               
  } 
  return(pc->next);
}

void display(Link Head)
{
  int first=1;   
  Link p=Head;
  while(p!=NULL)
  { 
    if(first)  //��ʾ��һ�����ʱ,����ʾ+�� 
    { 
      if(p->expn==1)
        printf("%dx",p->coef);
      else if(p->expn==0)
        printf("%d",p->coef);
      else                       
        printf("%d^%d",p->coef,p->expn);
      first=0;  
    }  
    else  //��ʾ�������ʱ,��ʾ+�� 
    {
      if(p->expn==1)
        printf("+%dx",p->coef);
      else if(p->expn==0)
        printf("+%d",p->coef);
      else
        printf("+%dx^%d",p->coef,p->expn);       
    }
    p=p->next;
  }  
  printf("\n"); 
}

int main()
{
  Link Link1,Link2,Link3;
  printf("\n������һ��һԪ����ʽ(��0 0��־����):\n");
  printf("Ҫ��:1.���ݴӴ�С������������.\n");
  printf("     2.û��������������ͬ����.\n"); 
  Link1=create();

  printf("\n�����ڶ���һԪ����ʽ(��0 0��־����):\n");
  printf("Ҫ��:1.���ݴӴ�С������������.\n");
  printf("     2.û��������������ͬ����.\n");     
  Link2=create();
  
  Link3=add(Link1,Link2);
  printf("��һ��һԪ����ʽΪ:");
  display(Link1);
  printf("�ڶ���һԪ����ʽΪ:");
  display(Link2);
  printf("\n��Ӻ��һԪ����ʽΪ:");
  display(Link3);
  system("pause");  
}
