//�����Ӵ�
#include <iostream>
#define N 100
using namespace std;

int main()
{
  freopen("findchar.in","r",stdin);
  freopen("findchar.out","w",stdout);
  int i,j,k;
  char s1[N],s2[N];
  gets(s1);
  gets(s2);
  for(i=0;s1[i];i++)
  {
    for(j=i,k=0;s1[j] && s2[k] && s1[j]==s2[k];j++,k++);
    if(!s2[k])  //��s2�Ƚ���ϣ���ʾ����s1���Ӵ�
    {
       cout<<i<<endl;
       return 0;
    }
  }
  cout<<"-1\n"; 
  return 0;
} 
