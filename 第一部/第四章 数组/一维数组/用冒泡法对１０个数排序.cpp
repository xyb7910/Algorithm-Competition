//��ð�ݷ��ԣ�������������С����
#include <iostream>
using namespace std;

int main()
{
  int a[11],i,j,temp;
  for(i=1;i<11;i++)
    cin>>a[i];
  cout<<endl;
  for(j=1;j<=10-1;j++)//��ѭ��������
    for(i=1;i<=10-j;i++)//ÿ����ѭ���Ĳ�����εݼ�
      if(a[i]>a[i+1])//�Ƚ���������ڣ������ڵڣ���Ԫ��,��С���ϸ�,�����³�
         { temp=a[i];a[i]=a[i+1];a[i+1]=temp;}
  for(i=1;i<11;i++)
    cout<<a[i]<<"  ";//����ӡ���ź��������
  system("pause");
  return 0;
}
