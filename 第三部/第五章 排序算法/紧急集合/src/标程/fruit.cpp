//�������� 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int number[20000+1];//����±��Ӧֵ�����ĸ��� 
int BigNumber[15000+1];//˳���Ŵ���2���Ⱥ���� 
int n;//Ϊ���� 
int power;//��������ֵ 

void solve()
{
  int i,p,q;
  long total=0;
  p=1;//���number����û�ϲ�ǰ����Сָ���� 
  q=1;//���BigNumber����û�ϲ�ǰ����Сָ���� 
  i=0;//���ÿ�κϲ�ʱ�Ѻϲ���Ⱥ�� 
  while(n>1)//�绹û�ϲ��꣬������ϲ� 
  {
    if(p<=20000)//���и���С��2���Ⱥû�кϲ� 
    {
      if(number[p]>0)//���number�±��ӦȺ���ڣ���ϲ� 
      {
        i++;
        total+=p;
        number[p]--;
      }
      else
        p++;//û�и���Ϊp��ֵ�������� 
    }
    else//����Ⱥ�ĸ���������2����˳���number������ȡ��Ⱥ�ϲ� 
    {
      i++;
      total+=BigNumber[q];
      q++;
    }
    
    if((total<=20000)&&(i==2))//һ�κϲ���i=2)���Һϲ���ĸ���������2�� 
    {
      number[total]++;//���ϲ���ֵ��������С������ 
      n--;
      i=0;
      power+=total;
      total=0;
    }
    else
      if(i==2)//һ�κϲ��꣬�Һϲ���ĸ�������2�� 
      {
        BigNumber[0]++;//�ڱ�����ʾ��һ��ȡֵ�Ӵ�����ĺ�λ��ȡ 
        BigNumber[BigNumber[0]]=total;//��������� 
        n--;
        power+=total;
        i=0;
        total=0;
      }
  }
  printf("%d\n",power);
}

void init()
{
  int i,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&k);
    number[k]++;
  }
}

int main()
{
  freopen("fruit.in","r",stdin);
  freopen("fruit.out","w",stdout);
  power=0;
  init();//������������ 
  solve();
  return 0;
}
