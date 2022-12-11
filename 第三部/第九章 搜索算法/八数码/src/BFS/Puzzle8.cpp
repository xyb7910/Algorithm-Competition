//�����룭������� 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAXN=370000;

int n, final, Ans, p;
int last[MAXN], queue[MAXN], rank[MAXN];
//last��һ���ĺ��룬�������·�������������·���������ο���
//queue�洢����
//rank ��¼��ǰ������ȣ������˶��ٴ�
bool visit[MAXN];//����Ƿ��Ѿ�����
int s[9];//��ǰ�������״̬
int front = 1,rear = 1;//������β

int turn()//ת��������
{
  int i;
  int ans = 0;
  for(i = 0; i < 9; i++)
    ans = ans * 10 + s[i];
  return ans;
}

int cantor()//����ѹ��
{
  bool use[9] = {0};
  int i, j, no;
  int ans = 0;
  for(i = 8; i >= 1; i--)
  {
    no = 0;
    use[s[8 - i]] = true;
    for(j = 0; j < s[8 - i]; j++)	
    {
      if(use[j] == true)
		no++;
    }
    ans = (ans + s[8 - i] - no) * i;//0 ��ʼ
  }
  return ans;
}

void init()
{
  int i;
  for(i = 0; i < 9; i++)//��״̬
  {
    scanf("%d", &s[i]);
    n = n * 10 + s[i];
  }
  queue[1] = n;
  visit[cantor()] = true;
  n = 0;
  s[0] = 1;s[1] = 2;s[2] = 3;
  s[3] = 8;s[4] = 0;s[5] = 4;
  s[6] = 7;s[7] = 6;s[8] = 5;
  final = cantor();//ĩ״̬
}

void Ucan(int num)//������չ��������������չ�������ǿ���ֵչ��
{
  int i;
  for(i = 8; i >= 0; i--)
  {
    s[i] = num % 10;
    num /= 10;
  }
}

int findzero()//��0��λ��
{
  int i;
  for(i = 0; i < 9; i++)
    if(s[i] == 0)
  return i;	
}

void bfs(int c)
{
  int t, num;
  t = s[p]; s[p] = s[p + c]; s[p + c] = t;
  num = cantor();
  if(visit[num] != true)
  {
    queue[++rear] = turn();//��������
    visit[num] = true;
    last[rear] = front;
    rank[rear] = rank[front] + 1;
    if(num == final)//����
      Ans = rank[front] + 1;
  }
  t = s[p]; s[p] = s[p + c]; s[p + c] = t;
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  init();
  if(visit[final] == true)//��״̬��ĩ״̬
  {
    printf("0\n");
    return 0;
  }
  while(front <= rear && Ans == 0)
  {
    Ucan(queue[front]);
    p = findzero();
    if(p >= 3)//��������
      bfs(-3);
    if(Ans == 0 && p < 6)
      bfs(3);//��������
    if(Ans == 0 && (p % 3) > 0)
      bfs(-1);//��������
    if(Ans == 0 && (p % 3) < 2)
      bfs(1);//��������
    front++;
  }
  if(Ans == 0)//ʼ��û�д�
    printf("-1\n");
  else
    printf("%d\n", Ans);
  return 0;
}
