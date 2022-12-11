//è������
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int x, y;//����
	char pos;//����
};
char array[10][11];

void MoveNext(struct Node* who)//����ĸı��������ĸı�
{
  switch (who->pos)//��ȡ��ǰ��λ��������һ������ 
  {
	case 'N': 
      if (who->x == 0 || array[who->x - 1][who->y] == '*')
	    who->pos = 'E';
	  else
	    who->x--;
	  break;
	case 'S': 
      if (who->x == 9 || array[who->x + 1][who->y] == '*')
		who->pos = 'W';
      else
        who->x++;
	  break;
	case 'E': 
      if (who->y == 9 || array[who->x][who->y + 1] == '*')
		who->pos = 'S';
      else
        who->y++;
	  break;
	case 'W': 
      if (who->y == 0 || array[who->x][who->y - 1] == '*')
		who->pos = 'N';
      else 
        who->y--;
      break;
	}
}

int main()
{
  freopen("catmouse.in", "r", stdin);
  freopen("catmouse.ans", "w", stdout);
  int N, i, j, k, count;
  struct Node Mouse, Cat;
  scanf("%d", &N);
  gets(array[0]);//��ȡ����Ļس��� 
  for (k = 0; k < N; k++)
  {
    for (j = 0; j < 10; j++)
      gets(array[j]);
    for (i = 0; i < 10; i++)////��ͼ����ȡ�������ڵ�λ�ò���� 
      for (j = 0; j < 10; j++)
      {
		if (array[i][j] == 'C') 
		{
		  Cat.x = i;
		  Cat.y = j;
		  Cat.pos = 'N';
		}
		else if (array[i][j] == 'M')
		{
		  Mouse.x = i;
		  Mouse.y = j;
		  Mouse.pos = 'N';
		}
      }
    count = 0;
    //һ�ٲ�֮�ڻ���δ�ҵ��������
    while (count < 100 && (Mouse.x != Cat.x || Mouse.y != Cat.y))
    {
      MoveNext(&Mouse);
      MoveNext(&Cat);
      count++;
    }
    if(Mouse.x == Cat.x && Mouse.y == Cat.y)//���������
      printf("%d\n", count);
    else//δ�ҵ�
      printf("-1\n");
  }
  return 0;
}
