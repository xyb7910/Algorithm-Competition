//��ά�������� 
#include <iostream>
using namespace std;

int cmp(const void *a,const void *b)
{
   if(((int *)a)[0]-((int *)b)[0]==0)//�����һԪ����� 
     return ((int *)a)[1]-((int *)b)[1];//�Ƚϵڶ�Ԫ�� 
   else  
     return ((int *)a)[0]-((int *)b)[0];//����Ƚϵ�һԪ�� 
}

int main()
{
  int s[10][2];
  for(int i=0;i<10;i++)
    cin>>s[i][0]>>s[i][1];
  qsort(s,10,sizeof(s[0]),cmp);
  cout<<endl;
  for(int i=0;i<10;i++)
    cout<<s[i][0]<<" "<<s[i][1]<<endl;
  system("pause");  
}
