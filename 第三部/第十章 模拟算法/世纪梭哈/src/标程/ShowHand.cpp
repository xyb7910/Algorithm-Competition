//������� 
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

struct card
{
  int n,f;
}a[6],b[6];
int ma, mb;

void swap(card a[], int x, int y)
{
  card temp = a[x]; a[x] = a[y]; a[y] = temp;
}

bool operator <(card a, card b)//��������� 
{
  //��aΪ��һ����bΪ�ڶ���������
  return(a.n>b.n)||((a.n==b.n)&&(a.f>b.f));
}

int count(card t[])//�ж�����
{
  int i;
  //��Ϊ������������������ʱ 
  if((t[1].n==14)&&(t[2].n==5)&&(t[3].n==4)&&(t[4].n==3)&&(t[5].n==2))
	for(i=1;i<=5;i++)
	  t[i].n = 6 - i;
  bool flag = true;
  for (i = 1; i<5; i++) 
	if ((t[i].f != t[i + 1].f) || (t[i].n != t[i + 1].n + 1))
	{
	  flag = false; break;//����ɫ����ͬ�������ֲ�����
	}
  if (flag)
	return 10;
  flag = true;
  for (i = 1; i<4; i++)
    if (t[i].n != t[i + 1].n)//�жϣ������Ƿ���� 
    {
	  flag = false;break;
    }
  if (flag)
	return 20;
  flag = true;
  for (i = 2; i<5; i++)//�жϣ������Ƿ���� 
	if (t[i].n != t[i + 1].n)
	{
	  flag = false; break;
	}
  if (flag)
	return 21;
  if((t[1].n==t[2].n)&&(t[3].n==t[4].n)&&(t[4].n==t[5].n))
	return 31;
  if ((t[1].n==t[2].n)&&(t[2].n==t[3].n)&&(t[4].n==t[5].n))
	return 30;
  flag = true;
  for (i = 1; i<5; i++)
	if (t[i].f != t[i + 1].f)
	{
	  flag = false; break;
	}
  if (flag)
	return 40;
  flag = true;
  for (i = 1; i<5; i++)
	if (t[i].n != t[i + 1].n + 1)
	{
	  flag = false; break;
	}
  if (flag)
	return 50;
  if ((t[1].n == t[2].n) && (t[2].n == t[3].n))
	return 60;
  if ((t[2].n == t[3].n) && (t[3].n == t[4].n))
	return 61;
  if ((t[3].n == t[4].n) && (t[4].n == t[5].n))
	return 62;
  if ((t[1].n == t[2].n) && (t[3].n == t[4].n))
	return 70;
  if ((t[1].n == t[2].n) && (t[4].n ==t[5].n))
	return 71;
  if ((t[2].n == t[3].n) && (t[4].n == t[5].n))
	return 72;
  for (i = 1; i<5; i++)
	if (t[i].n == t[i + 1].n)
	  return 80 + i - 1;
  return 90;
}

int judge(card a[])//�ж�����֮��������
{
  int t = count(a);
  if (t== 21)
  {
    swap(a, 1, 5);
    sort(a + 1, a + 5);
  }
  if (t== 31)
  {
    swap(a, 1, 5);
    swap(a, 2, 4);
    sort(a + 1, a + 4);
    sort(a + 4, a + 6);
  }
  if (t == 61)
  {
    swap(a, 1, 2);
    swap(a, 2, 3);
    swap(a, 3, 4);
  }
  if (t == 62)
  {
    swap(a, 1, 3);
    swap(a, 2, 4);
    swap(a, 3, 5);
    swap(a, 4, 5);
  }
  if (t == 71)
  {
    swap(a, 3, 4);
    swap(a, 4, 5);
  }
  if (t == 72)
  {
    swap(a, 1, 2);
    swap(a, 2, 3);
    swap(a, 3, 4);
    swap(a, 4, 5);
  }
  if (t == 81)
  {
    swap(a, 1, 2);
    swap(a, 2, 3);
  }
  if (t == 82)
  {
    swap(a, 1, 3);
    swap(a, 2, 4);
  }
  if (t == 83)
  {
    swap(a, 2, 4);
    swap(a, 3, 5);
    swap(a, 1, 2);
    swap(a, 2, 3);
  }
  return t/ 10;
}

int main()
{
  freopen("ShowHand.in","r",stdin);
  freopen("ShowHand.out","w",stdout);
  while (scanf("%d%d",&a[1].n,&a[1].f)==2)
  {
    int i;
    for (i = 2; i <= 5; i++)//���� 
      scanf("%d%d", &a[i].n, &a[i].f);
    for (i = 1; i <= 5; i++)
      scanf("%d%d", &b[i].n, &b[i].f);
    for (i = 1; i <= 5; i++)
    {
      if (a[i].n == 1)//��A�ƵĴ���
		a[i].n = 14;
      if (b[i].n == 1)
		b[i].n = 14;
      a[i].f = 5 - a[i].f; 
      b[i].f = 5 - b[i].f;
    }
    sort(a + 1, a + 6);//���ɴ�С����,ע������������� 
    sort(b + 1, b + 6);
    ma = judge(a);//�ж�
    mb = judge(b);
    if (ma<mb)
      cout<<"Player A win!\n";
    if (ma>mb)
      cout<<"Player B win!\n";
    if (ma == mb)//������һ�����ȵ���
    {
      bool equal = true;
      for (i = 1; i <= 5; i++)
		if (a[i].n != b[i].n)
		{
		  equal = false;
		  if (a[i].n>b[i].n)
            cout<<"Player A win!\n";
		  if (a[i].n<b[i].n)
		    cout<<"Player B win!\n";
		  break;
		}
      if (!equal)
		continue;
      if (a[1].f>b[1].f)
		cout<<"Player A win!\n";
      else 
        cout<<"Player B win!\n";
    }
  }
  return 0;
}
