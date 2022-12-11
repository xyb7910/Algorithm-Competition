//�����룭��* 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAXN = 370000;

struct node
{
  int math;//����ֵ
  int ca;//cantorֵ
  int zero;//0��λ��
}dui[MAXN];//��

struct node d;
int s[9],f[9]={1,2,3,8,0,4,7,6,5};//s��¼����״̬��f��¼ĩ״̬
int h[MAXN];//h�ǵ�ǰ��Ŀ��Ĺ���ֵ
int g[MAXN];//g����㵽��ǰ�Ĵ���
int duip[MAXN];//duip��ָ��dui��ָ��
int all = 1;//all��duip�ĳ���
int len = 1, final;//len��dui�ĳ��ȣ�final��ĩ״̬cantorֵ
bool visit[MAXN];//��¼�Ƿ��Ѿ�����

int cantor()//����ѹ��
{
  int i, j;
  int ans = 0;
  int no = 0;
  int use[9] = {};
  for (i = 0; i <= 7; i++)//���һλ����ѡ����أ�����ѭ����7
  {
    no = 0;
    use[s[i]] = true;
    for (j = 0; j < s[i]; j++)
    {
	  if (use[j])
	    no++;
    }
    ans = (ans + s[i] - no) * (8 - i);
  }
  return ans;
}

int turn()//ת��Ϊ����
{
  int i;
  int ans = 0;
  for (i = 0; i < 9; i++)
    ans = ans * 10 + s[i];
  return ans;
}

int _h()//����h�������ù��ۺ���<ʵ��ֵ�����ܵõ����Ž�
{
  int i;
  int ans = 0;
  for (i = 0; i < 9; i++)
	if (s[i] != f[i] && s[i] != 0)//����λ�ò����뿼�� 
	  ans++;
  return ans;
}

void init()//�����ʼ��
{
  int i;
  dui[1].math = 0;
  for (i = 0; i < 9; i++)
  {
    scanf("%d", &s[i]);
    if (s[i] == 0)
      dui[1].zero = i;
  }
  dui[1].math = turn();
  dui[1].ca = cantor();
  visit[dui[1].ca] = true;
  h[dui[1].ca] = _h();
  duip[1] = 1;
  s[0] = 1; s[1] = 2; s[2] = 3;
  s[3] = 8; s[4] = 0; s[5] = 4;
  s[6] = 7; s[7] = 6; s[8] = 5;
  final = cantor();
}

void s_get(int x)//��math���ֵõ�״̬
{
  int i;
  for (i = 8; i >= 0; i--)
  {
    s[i] = x % 10;
    x /= 10;
  }
}

void upwei(int root)//��������ά����
{
  int t = root;
  int change;
  if((root<<1)<=all 
  && (g[dui[duip[root<<1]].ca]+h[dui[duip[root<<1]].ca])
    <(g[dui[duip[root]].ca]+h[dui[duip[root]].ca]))
    t = root << 1;
  if(((root<< 1)+1)<=all 
  && (g[dui[duip[(root<<1)+1]].ca]+h[dui[duip[(root<<1)+1]].ca])
    <(g[dui[duip[t]].ca]+h[dui[duip[t]].ca]))
    t =(root << 1) + 1;
  if (t != root)
  {
    change = duip[t]; 
    duip[t] = duip[root]; 
    duip[root] = change;
    upwei(t);
  }
}

void downwei(int x)//��������ά����
{
  int t;
  while(x>1&&(g[dui[duip[x]].ca]+h[dui[duip[x]].ca])
    <(g[dui[duip[x>>1]].ca]+h[dui[duip[x>>1]].ca]))
  {
    t = duip[x]; 
    duip[x] = duip[x >> 1]; 
    duip[x >> 1] = t; 
    x >>= 1;
  }
}

void add(int mea)//������
{
  int t;
  t = s[d.zero + mea]; 
  s[d.zero + mea] = s[d.zero]; 
  s[d.zero] = t;
  t = cantor();
  if (!visit[t])
  {
    visit[t] = true;
    dui[++len].ca = t;
    dui[len].math = turn();
    dui[len].zero = d.zero + mea;
    duip[++all] = len;
    h[dui[len].ca] = _h();
    g[dui[len].ca] = g[d.ca] + 1;
    downwei(all);
  }
  t = s[d.zero + mea]; 
  s[d.zero + mea] = s[d.zero]; 
  s[d.zero] = t;
}

void _A()
{
  while (all >= 1)
  {
    if (h[dui[duip[1]].ca] == 0)
    {
      printf("%d\n", g[dui[duip[1]].ca]);
      return;
    }
    d = dui[duip[1]];
    s_get(dui[duip[1]].math);
    duip[1] = duip[all];
    all--;
    if (all > 1)
      upwei(1);
    if (d.zero > 2)//������
      add(-3);
    if (d.zero < 6)//����
      add(3);
    if ((d.zero % 3) > 0)//��
      add(-1);
    if ((d.zero % 3) < 2)//��
      add(1);
  }
  printf("-1\n");
}

int main()
{
  freopen("Puzzle8.in", "r", stdin);
  freopen("Puzzle8.out", "w", stdout);
  init();
  if (dui[1].ca == final)//���ĩ״̬����״̬
  {
    printf("0\n");
    return 0;
  }
  _A();
  return 0;
}
