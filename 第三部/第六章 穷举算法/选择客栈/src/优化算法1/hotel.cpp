//ѡ���ջ ���Ż��㷨��
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int N = 200000 + 10, K = 60;
int n, k, price, c, v, s;
int a[K], f[K][N];
int main() 
{
  freopen("hotel.in", "r", stdin);
  freopen("hotel.out", "w", stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++) 
  {
    scanf("%d %d", &c, &v);
    for(int j=0; j<k; j++)//���������ɫ 
      f[j][i] = f[j][i-1] + (j == c);//��ɫ������һ 
    if(v <= price) 
      s += f[c][a[i] = i] - 1;//�翧�ȵ������������
    else
      s += f[c][a[i] = a[i-1]];
  }
  printf("%d\n", s);
  return 0;
}
