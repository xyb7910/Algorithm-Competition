//���±����� 
# include <iostream>
using namespace std;
int main ()
{
  int a[100],i,*p;
  for (i = 0; i < 100; i++)//����ֵ 
    a[i] = i;
    
  p = &a[50];//ָ��ָ�������м� 
  for (i = -50; i < 50; i++)
    cout<<p[i]<<' ';
  return 0;
}
