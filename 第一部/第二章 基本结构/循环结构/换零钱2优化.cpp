//����Ǯ2�Ż�
#include<iostream>
using namespace std;
int main()
{
    int count=0,x,i;
    cin>>x;
    x=(x-16)/5+1;//��5Ԫ��ֵ���������ֵ����10Ԫ����=0ʱ�ķ������� 
    count=(x+1)*(x+1)/4;//�Ȳ���� 
    cout<<count<<endl;
    system("pause");     
}
