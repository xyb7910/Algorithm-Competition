//ָ�����ָ������Ԫ�ص�Ӧ��
#include <iostream>
using namespace std;
int main()
{
   int *p,i,a[10]={1,2,3,4,5,6,7,8,9,10};
   for(p=a;p<(a+10);p++)  //ע��aΪ�׵�ַ����p��p++��ָ����һԪ�ض��Ǽ�1
     cout<<*p<<" ";
}
