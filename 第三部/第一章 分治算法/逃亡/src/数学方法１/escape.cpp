//��������ѧ�㷨�� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    double s,v1,v2;
    double t1,t2,t3; 
    cin>>s>>v1>>v2;
    //��·�� ���� ���� 
    
    t1 = (s/v2-s/v1) / //���ȳ˳�ʱ�� 
        ((v1+(v2-v1)*v1/(v1+v2))/v2-1-(v2-v1)*(v2/v1+2)/(v1+v2));
     
    t2 = t1*(v2-v1)/(v1+v2); //����������������ʱ�� 
    t3 = (s-v1*t1-v1*t2)/v2; //�ײ��е��յ��ʱ�� 
                             //�� �ҳ˳����յ��ʱ�� 
    
    printf("%.2f\n",t1+t2+t3);
    return 0;
}
