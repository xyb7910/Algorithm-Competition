//ָ�������Ӧ��
#include <iostream>
using namespace std;

#include <stdio.h>
void swap(int *p1,int *p2)//ע�⵱ָ�����������ʱ�βε���ʽ
{
     int temp;
     temp=*p1; *p1=*p2; *p2=temp;
}

main()
{
    int *_point1,*_point2,a=3,b=4;
    _point1=&a;  _point2=&b;  //��a,b�ĵ�ַ����_point1,_point2
    if(a<b)
        swap(_point1,_point2);//��ָ���������������
    cout<<a<<" "<<b;
}
