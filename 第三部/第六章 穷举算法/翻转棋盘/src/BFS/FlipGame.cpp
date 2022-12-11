//��ת����-BFS 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 1000000
using namespace std;

int que[N];//��������������õ��Ķ��� 
int flag[65536];//flag[i]=1��i״̬�ѳ��ֹ� 
int step[65536];//step[i]����i״̬�Ĳ��� 
int front=0,rear=0;

int flip(int state,int pos)//��תpos������Χλ��
{
   state^=(1<<pos);
   if((pos-4)>=0)   state^=(1<<(pos-4));//��ת�Ϸ� 
   if((pos+4)<=15)  state^=(1<<(pos+4));//��ת�·� 
   if(pos%4!=0)     state^=(1<<(pos-1));//��ת�� 
   if(pos%4!=3)     state^=(1<<(pos+1));//��ת�ҷ� 
   return state;
}

int bfs()//����
{
  int OK=0,state,temp; 
  while(front<rear)//�����в�Ϊ�� 
  {                                     
    state=que[front++];//ȡ������״̬ 
    for(int i=0;i<16;i++) 
    {                                   
      temp=flip(state,i);//ö�ٵ�ǰ״̬�£���ת16�����Ӻ��״̬
      if(temp==0||temp==65535)//��ȫ0��ȫ1
      {            
        OK=1;
        flag[temp]=1;
        step[temp]=step[state]+1;
        break;
      } 
      else if(!flag[temp])//����״̬û�г��ֹ� 
      {
        que[rear++]=temp;
        flag[temp]=1;//�����״̬ 
        step[temp]=step[state]+1;  
      }
     } 
     if(OK)  
       break;               
   } 
   return OK;
} 

int main()
{
  freopen("FlipGame.in","r",stdin);
  freopen("FlipGame.out","w",stdout);
  int i,j;
  int state=0;
  char s[5];
  for(i=0;i<4;i++)
  {
    scanf("%s",s);
    for(j=0;j<4;j++)
    {
      if(s[j]=='b')//��'b'=1,'w'=0,����λΪ0ʱ������� 
        state|=(1<<(i*4+j));//��λΪ1ʱ��state+=1^λ��              
    }
  }
  if(state==0||state==65535)//��ȫ�׻�ȫ��  
    printf("0\n");
  else
  {
    que[rear++]=state;//��ʼ״̬����� 
    flag[state]=1;//��ʾ��״̬�ѳ��ֹ� 
    memset(step,0,sizeof(step));
    if(bfs())//�����������     
      printf("%d\n",flag[0]==1?step[0]:step[65535]);        
    else            
      printf("Impossible\n");
  }
  return 0;
}
