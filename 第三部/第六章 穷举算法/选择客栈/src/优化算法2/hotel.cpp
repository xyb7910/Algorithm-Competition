//ѡ���ջ ���Ż��㷨��
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int K = 60;
int n, k, price, c, v, s, f;
int a[K], b[K], u[K];

int main() 
{
  freopen("hotel.in", "r", stdin);
  freopen("hotel.out", "w", stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++) 
  {
    scanf("%d %d", &c, &v);
    if(v <= price)//���з���������ѵĿ��ȵ� 
      f = i;
    if(f >= u[c]) 
      b[c] = a[c];
    s += b[c];
    a[c]++;//��ɫΪ c �Ŀ�ջ����һ 
    u[c] = i;//���´洢��һ����ɫΪ c �Ŀ�ջ��� 
  }
  printf("%d\n", s);
  return 0;
}
