//������Ϸ 
#include <stdio.h>
//�������� 
int graph[9][9]={0};
bool x_used[9][10]={false};
bool y_used[9][10]={false};

bool flag=false,error=false;//��Ǳ��� 

FILE *in,*out;

void init();        //�����������ж������Ƿ���ȷ 
void print();       //������� 
bool test(int x,int y,int num);     //�ж���num��3*3С�����Ƿ���� 
void search(int step);      //���������� 

void init()
{
  int i,j,num;
  in=fopen("sudoku.in","r");
  out=fopen("sudoku.out","w");
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
    {
      fscanf(in,"%1d",&num);
      if(num!=0)
      {
		if(!test(i,j,num)||x_used[i][num]||y_used[j][num])
		{
		  error=true;
		  fprintf(out,"%d�� %d�����ظ����֣�\n",i+1,j+1);
		}
        else
		{
		  x_used[i][num]=true;
		  y_used[j][num]=true;
        }
      }
      graph[i][j]=num;			
    }
}

void print()
{
  int i,j,k;	
  for(i=0;i<9;i++)
  {
    if(i!=0&&i%3==0) 
      fprintf(out,"\n");
    for(j=0;j<9;j++)
    {
	  if(j!=0&&j%3==0) 
        fprintf(out,"  ");
      fprintf(out,"%d ",graph[i][j]);
    }
    fprintf(out,"\n");
  }
}

bool test(int x,int y,int num)
{
  int i,j;
  x=x/3*3;		//Important part
  y=y/3*3;		//Important part
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      if(graph[x+i][y+j]==num) 
        return false;
  return true;
} 

void search(int step)
{
  if(step>80) 
  {
    flag=true;
    return;
  }
  int i=step/9,j=step%9,num;//Important part
  if(graph[i][j]!=0) 
    search(step+1);
  else
  {
    for(num=1;num<10;num++)
      if(!x_used[i][num]&&!y_used[j][num]&&test(i,j,num))
      {
		graph[i][j]=num;
		x_used[i][num]=true;
		y_used[j][num]=true;
		search(step+1);
		if(flag) 
          return;
		graph[i][j]=0;
		x_used[i][num]=false;
		y_used[j][num]=false;
      }
  }
}

int main()
{
  init();
  if(!error)
  {
    search(0);
    print();
  }
  return 0;
}
