//����r=1��r=10ʱ��Բ�����ֱ�����area����100Ϊֹ
# include <iostream>
using namespace std;
int main()
{	
  float area;int r;
  for(r=1;r<=10;r++)
  {
    area=3.14*r*r;
    if(area>100)
      break; //������ǰѭ���壬ִ��ѭ������������
    cout<<r<<":area="<<area<<endl;
  }
  system("pause");
  return 0;
}
