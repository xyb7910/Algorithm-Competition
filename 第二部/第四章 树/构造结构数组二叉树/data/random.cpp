#include <iostream>
using namespace std;
#define random(num)     (rand() % (num))
#define randomize()     srand((unsigned)time(NULL))
#define n 100
int a[101],i;

int main()
{
  freopen("arraytree10.in","w",stdout);
  randomize();//��ȡ���������,rand()����0-32767֮����� 
  cout<<n<<endl;
  for(i=1;i<=n;i++)
    a[i]=random(100);
  for(i=1;i<=n;i++)
    printf("%d ",a[i]);
  getchar();
}

