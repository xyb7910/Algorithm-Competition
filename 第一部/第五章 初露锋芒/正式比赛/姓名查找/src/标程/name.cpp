//�������ɸ������������в���
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
int main()
{
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    int num,i,j;
    cin>>num;
    getchar();//��ȥ��һ�еĻس� 
    char name[num+1][50];
    for(i=0;i<=num;++i)
      gets(name[i]);//ע����ҵ���������name[num]�� 
    for(i=0;i<=num;++i)
      if(strcmp(name[i],name[num])==0)
        break;
    if(i==num)
      cout<<-1<<endl;
    else
      cout<<i+1<<endl;
    return 0;
}
