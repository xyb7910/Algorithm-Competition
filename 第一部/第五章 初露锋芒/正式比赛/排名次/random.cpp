#include <iostream>
using namespace std;
#define random(num)     (rand() % (num))
#define randomize()     srand((unsigned)time(NULL))
#define n 100
int a[100001],i;

int main()
{
  freopen("billing10.in","w",stdout);
  randomize();//��ȡ���������,rand()����0-32767֮����� 
  int num=random(3000);
  cout<<num<<endl;
  for(i=1;i<=num;i++)
    a[i]=random(100);
  for(i=1;i<=num;i++)
    printf("%d ",a[i]);
  //getchar();
}

