//ħ��ʯ���ջ���ѧ���� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ZeroTrail(int n)//����n����0�ĸ��� 
{
  int count = 0;
  while(n) 
  {
    count+=n/5;
    n/=5;
  }
  return count;
}

int main() 
{
  freopen("rob.in","r",stdin);
  freopen("rob.out","w",stdout);  
  int q;
  scanf ("%d", &q);
  if (!q) 
  {
    printf ("1\n");
    return 0;
  }
  int i = 4*q/5*5;
  while (ZeroTrail(i) < q) 
    i += 5;
  if (q == ZeroTrail(i)) 
    printf ("%d\n", i);
  else 
    printf ("No solution\n");
  return 0;
}
