//�������� 
#include <iostream>
using namespace std;

int main()
{
    int *p1,*p2,*p,a=3,b=4;
    p1=&a;  p2=&b;   //p1,p2��ֵ������ָ��a,b��
    if(a<b)
    {p=p1;p1=p2;p2=p;}  //��ֵַ���ཻ��
    cout<<a<<" "<<b;
    cout<<*p1<<" "<<*p2;
}
