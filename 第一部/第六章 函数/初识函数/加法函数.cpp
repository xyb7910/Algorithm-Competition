//�ӷ�����
#include <iostream>
using namespace std;

float add(float x,float y) //��������Ϊfloat,�������β�float x,float y
{
  float z; //ע�⣬������z
  z=x+y;
  return z; //����ֵz Ϊfloat�ͣ��뷵��ֵ����ƥ��
}

int main()
{
  float x,y,z;  //ע�⣺������x,y,z
  cin>>x>>y;
  z=add(x,y);//����add�����󷵻�һ��float���͵�ֵ,������ֵ����z
  cout<<z<<endl;
  system("pause");
}
