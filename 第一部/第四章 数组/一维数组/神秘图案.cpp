//����ͼ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int j = 0;//��������
  int index = 0;//�ҵ�i+1����
  int n = 0;//�ҵĴ���
  int s = 1;//�����
  int mark[10]= {0}; //��¼�Ƿ��ҹ�
  for (; n<1000; n++)
  {
    mark[index] = 1;
    index+=1+s++;
    index%=10;
  }
  for (j=0; j<10; j++)
    if (mark[j] == 0)
      cout<<j+1<<' ';
  return 0;
}
