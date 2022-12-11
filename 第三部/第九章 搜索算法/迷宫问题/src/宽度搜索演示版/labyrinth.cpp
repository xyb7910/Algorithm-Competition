//����-���Թ�����
#include <iostream>
#define m 5  /*����*/
#define n 5  /*����*/
#define MaxSize 100
using namespace std;

int zx[9]={0,-1,-1,0,1,1,1,0,-1};
int zy[9]={0,0,1,1,1,0,-1,-1,-1};  
int mg[m+2][n+2]={1,1,1,1,1,1,1,
                  1,0,0,0,1,0,1,
                  1,0,1,0,0,0,1,
                  1,0,0,1,0,1,1,
                  1,1,1,0,1,0,1,
                  1,0,1,1,1,0,1,
                  1,1,1,1,1,1,1};
struct stype
{
  int x,y,pre;
}queue[MaxSize];

void printlj(int rear)//��ӡ·�� 
{
  int i,j;
  i=rear;
  do
  {
    j=i;
    i=queue[i].pre;
    queue[j].pre=-1;
  } while (i!=0);
  printf("\n�Թ�·��:\n\t���->");
  i=0;
  while (i<MaxSize)
  {
	if (queue[i].pre==-1)
	   printf("(%d,%d)->",queue[i].x,queue[i].y);
	i++;
  }
  printf("����\n");
}

void mglj()
{
  int i,j,x,y,v,front,rear,find=0,no=1;
  queue[1].x=1;queue[1].y=1;queue[1].pre=0;

  front=1;rear=1; 
  mg[1][1]=-1;    
  printf(" ����  x   y  pre\n");
  printf("%4d%4d%4d%4d\n",no++,queue[rear].x,queue[rear].y,queue[rear].pre);
  while (front<=rear && !find)  
  {
	x=queue[front].x; y=queue[front].y;
	for (v=1;v<=8;v++)   
	{
	  i=x+zx[v];j=y+zy[v]; 
	  if (mg[i][j]==0)    
	  {
	     rear++;   
	     queue[rear].x=i;
	     queue[rear].y=j;
	     queue[rear].pre=front;  
	     mg[i][j]=-1; 
	     printf("%4d%4d%4d%4d\n",no++,queue[rear].x,queue[rear].y,queue[rear].pre);
  	  }
	  if (i==m && j==n) /*�ҵ��˳���*/
	  {
	    printlj(rear);  /*��ӡ�ҵ���·��*/
	    find=1;         /*����Ϊ1ʱ�����˳�ѭ��*/
	  }
    }
    front++;  
  }
  if (!find) printf("������·��!\n");
}

int main()
{
  mglj();  /*�����Թ�·��*/
  getchar();
}
