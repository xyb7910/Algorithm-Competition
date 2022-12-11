//��ʿ���������� 
#include <stdio.h> 
#define INF 100

int board[8][8],n;
int start;
int mover[]={-2,-1,1,2, 2, 1,-1,-2};
int movec[]={ 1, 2,2,1,-1,-2,-2,-1};

int numable(int r, int c, int nexta[])//�����´ο����ҵ�������
{
  int i, k, a, b;
  int num = 0;
  for(i = 0;i <= 7;i++)
  {
    k = (i + start) % 8;//1-8��ѭ������ 
    a = r + mover[k];
    b = c + movec[k];
    if(a<=7 && a>=0 && b>=0 && b<=7 && board[a][b]==0)
    {
      nexta[num] = k;
      num++;
    }
  }
  return num;
}

int number(int r, int c)/*�����´ο����ҵ��������ĸ���*/
{
  int i, k, a, b;
  int num = 0;
  for(i = 0;i <= 7;i++)
  {
    k = (i + start) % 8;
    a = r + mover[k];
    b = c + movec[k];
    if(a<=7 && a>=0 && b>=0 && b<=7 && board[a][b]==0)
      num++;
 }
 return num;
}

int next(int r, int c)//�ҵ����ٵ�������������-1����· 
{
  int nexta[8], num, num1 = 0, minNum, i, k;
  minNum = INF;
  num = numable(r, c, nexta);//���㣨r,c)�ж��ٳ�· 
  if(num == 0) 
    return -1;  //û�г��� 
  
  for(i = 0;i <= num - 1;i++)//�ҵ����ٳ��� 
  {
    num1 =number(r+mover[nexta[i]],c+movec[nexta[i]]);
    if(num1 <= minNum)
    {
      minNum = num1;
      k = nexta[i];
    }
  }
  return k;
}

int main()
{
  int x, y;
  int step, caseCounter;
  int r, c;
  int i, j, k;
  scanf("%d%d", &x, &y);//�������
  start = 0;
  caseCounter = 1;
  while(start <= 7)
  {
    for(i = 0;i <= 7;i++)//��ʼ��
      for(j = 0;j <= 7;j++)
        board[i][j] = 0;
    r = x;
    c = y;
    board[r][c] = 1;//���
    step = 2;//��һ��λ��

    while(1)
    {
      if(step > 64)//����64�������ӡ��� 
      {
        printf("Case %d:\n", caseCounter++);
        for(i = 0;i <= 7;i++)
        {
          for(j = 0;j <= 7;j++)
            printf("%2d ", board[i][j]);
          printf("\n");
        }
        start++;
        break;
      }
       
      k = next(r, c);
      if(k == -1)
      {
        start++;
        break;
      }
      r = r + mover[k];
      c = c + movec[k];

      board[r][c] = step;
      step++;
    }
  }
  return 0;
}
