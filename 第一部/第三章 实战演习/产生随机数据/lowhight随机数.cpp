//����ָ����Χ�ڵ������ 
#include <iostream> 
using namespace std;

int main()
{
  int low,hight;
  srand((unsigned)time(NULL));
  cin>>low>>hight;//����low,hightֵ����С���õߵ�
  for(int i=1;i<=5000;i++)
    cout<<rand() %(hight-low+1)+low<<' ';
  system("pause");  
  return 0;
}
