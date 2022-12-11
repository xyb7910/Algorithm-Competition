//�Թ����⣭��������㷨 
#include <iostream>
using namespace std; 
#define MAX_ROW 5
#define MAX_COL 5

//������Ϊ�ṹ�� 
struct point 
{ 
  int row, col; 
}stack[512];

//�����ͼ 
int maze[MAX_ROW][MAX_COL]={0, 0, 1, 0, 0,
	                        0, 1, 0, 1, 1,
	                        0, 1, 0, 0, 0,
	                        0, 1, 0, 1, 0,
	                        0, 0, 0, 1, 0,};

//����ڵ��ǰ������ʼ��Ϊ-1 
struct point predecessor[MAX_ROW][MAX_COL] = 
{
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

int top = 0;//��ջ��ָ���ʼΪ0 

void push(struct point p)//��ջ 
{
  stack[top++] = p;
}

struct point pop(void)//��ջ 
{
  return stack[--top];
}

int is_empty()//�ж϶�ջ�Ƿ�Ϊ�� 
{
  return top == 0;
}

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;//���Ϊ2�������߹� 
	predecessor[row][col] = pre;//��Ǹýڵ��ǰ�� 
	push(visit_point);//���ýڵ�ѹ���ջ 
}

void PrintWay(int x,int y)//�������·�ߣ������ǵ���·�ߣ��������õݹ�˳����� 
{
   if(predecessor[x][y].row == -1)
   {
     printf("1 1\n");
     return;
   }
   else
   {
     PrintWay(predecessor[x][y].row,predecessor[x][y].col);
     printf("%d,%d\n", x+1, y+1);  
   }    
}

int main()
{
  struct point p = { 0, 0 }; 
  maze[p.row][p.col] = 2;//���Ϊ2��ʾ�õ��ѱ��߹� 
  push(p);	
  
  while (!is_empty())//����ջ��Ϊ��ʱ 
  {
    p = pop();//��ջ 
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) //����ҵ����ھ�����  
      break;
    if (p.row+1 < MAX_ROW && maze[p.row+1][p.col] == 0) //������̽
      visit(p.row+1, p.col, p);
    if (p.col+1 < MAX_COL  && maze[p.row][p.col+1] == 0)//������̽
      visit(p.row, p.col+1, p);
    if (p.row-1 >= 0 && maze[p.row-1][p.col] == 0)      //������̽ 
      visit(p.row-1, p.col, p); 
    if (p.col-1 >= 0  && maze[p.row][p.col-1] == 0)     //������̽ 
	  visit(p.row, p.col-1, p); 
  }
  if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) 
    PrintWay(p.row,p.col);        
  else
    printf("No path!\n");
  return 0;
}
