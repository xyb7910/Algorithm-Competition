//��������
#include <iostream>
using namespace std;

int main()
{
    int a=3,b=4;
    int *_point1,*_point2;//����������ָ����� *_point1,*_point2
    _point1=&b;           //�ѱ���b�ĵ�ֵַ����_point1
    _point2=&a;           //�ѱ���a�ĵ�ֵַ����_point2
    cout<<a<<' '<<b;
    cout<<*_point1<<' '<<*_point2);
}
