//����ָ�����ȵ�����ַ��� 
#include <iostream>
using namespace std;
#define random(num)     (rand() % (num))
#define randomize()     srand((unsigned)time(NULL))

int main()
{
  int i,n,m;//���n��m���ַ�������ַ���
  freopen("LCIS5.in","w",stdout);

  cin>>n>>m; 
  randomize();
  cout<<n<<endl; 

    for(int j=1;j<=n;j++)
    {
      cout<<random(200)<<' ';
    }

  cout<<m<<endl;

    for(int j=1;j<=m;j++)
    {
      cout<<random(200)<<' ';
    }
 

}
