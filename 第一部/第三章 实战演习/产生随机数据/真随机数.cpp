//������� 
#include <iostream>
using namespace std;    
#define n 100
int a[101],i;

int main()
{
  srand((unsigned)time(NULL));//��ȡ���������,rand()����0-32767֮����� 
  for(i=1;i<=n;i++)
    a[i]=rand() % 100;
  for(i=1;i<=n;i++)
    cout<<a[i]<<' ';
  getchar();
  return 0;
}
