//���� 
#include <stdio.h>
 
int n;//���ĸ���
int h;//����ʱ��
int fi[30];//���������
int di[30];//��λʱ����ļ�����
int cfi[30];//�� fi ����ı���
int ti[30];//ti[i] ��ʾ�ӵ� i �������� i+1 ����ʱ��
 
struct LAKENODE
{
  int num[30];
  int max;
}lake[30];//�ýṹ�����鱣����ܽ�
 
int GetMax(int p[], int i, int j)//�������� p ��������ı��
{
  int cmax = p[i], loc = i;// loc :�������λ��
  for (int m = i + 1; m <= j; m++)
    if (cmax < p[m])
    {
      cmax = p[m];
      loc = m;
    }
  return loc;
}
 
void GetFish()
{
  int i, j;
  int T = h * 60, t, CT;
  for(i = 1; i <= n; i++)//�ṹ�������ʼ����ȫ������
  {
     lake[i].max = 0;
     for(int j = 1; j <= n; j++)
       lake[i].num[j] = 0;
  }
  for (i = 1;i <= n; i++)//ö�ٽ�������λ��,�ӵ�һ��������n����
  {
    CT = T;
    t = 0;
    for (j = 1; j <= i; j++)
    {
      cfi[j] = fi[j];//��fi�����ֵ������cfi������
      CT = (j < i) ? CT - ti[j] * 5 : CT;//�����ȥ��·ʱ����ʣ��ʱ��
    }
    while (t < CT)
    {
      int k = GetMax(cfi, 1, i);//�ҵ����������ĺ��ı��
      lake[i].max += cfi[k];//��������������k��һ����λʱ���������
      lake[i].num[k] += 5;//ͣ��k����ʱ������һ����λʱ��
      cfi[k] >= di[k] ? cfi[k] -= di[k] : cfi[k] = 0;//�޸ĵ�k��������һ��ʱ�䵥λ�����ܵ�������
      t += 5;//ʱ������һ����λʱ��
    }
  }
  for (i = 1; i <= n; i++)//�����ֵ������cfi�����У����ڲ�ѯ�������ֵ
    cfi[i] = lake[i].max;
  int la = GetMax(cfi, 1, n);//la�����Ž��±�
  for (i = 1; i <= n; i++)
  {
    (i!=n)?printf("%d, ",lake[la].num[i]):printf("%d", lake[la].num[i]);
  }
  printf("\nNumber of fish expected: %d\n\n", lake[la].max);
}
 
int main()
{
  freopen("fish.in","r",stdin);
  freopen("fish.out","w",stdout);  
  int i;
  while (scanf("%d", &n) && n)
  {
    scanf("%d", &h);
    for (i = 1; i <= n; i++)
      scanf("%d", &fi[i]);
    for (i = 1; i <= n; i++)
      scanf("%d", &di[i]);
    for (i = 1; i < n; i++)
      scanf("%d", &ti[i]);
    GetFish();
  }
  return 0;
}
