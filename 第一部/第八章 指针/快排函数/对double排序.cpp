//��double����
#include <iostream>
using namespace std;

int cmp(const void *a,const void *b)//�������ǲ�������ȵ� 
{
  return ((*(double *)a-*(double *)b>0)?1:-1);
}

int main()
{
  double a[10];//string����
  for(int i=0;i<10;i++)
    cin>>a[i];
  qsort(a,10,sizeof(a[0]),cmp);
  cout<<endl;
  for(int i=0;i<10;i++)
    cout<<a[i]<<endl;
  system("pause");  
}
