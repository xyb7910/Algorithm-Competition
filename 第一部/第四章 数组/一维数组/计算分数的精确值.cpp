//��������ľ�ȷֵ
#include<iostream>
using namespace std;
int remainder[101],quotient[101];
//remainder:��ų���������;quotient:���δ���̵�ÿһλ

int main()
{
  int m,n,i,j;
  cin>>m>>n;      //���뱻�����ͳ���
  cout<<m<<"/"<<n<<"=0.";
  for(i=1;i<=100;i++)  //i: �̵�λ��
  {
    remainder[m]=i; //m:�������� remainder[m]:��������Ӧ���̵�λ��
    m*=10;          //��������10λ
    quotient[i]=m/n; //��
    m=m%n;           //������
    if(m==0) //����Ϊ0,��������
    {
      for(j=1;j<=i;j++) //���ʾ������С��
        cout<<quotient[j];  //�����
      break;             //�˳�ѭ��
    }
    if(remainder[m]!=0) //����������Ӧ��λ��ǰ���Ѿ����ֹ�
    {
      for(j=1;j<=i;j++) 
        cout<<quotient[j];  //�����ѭ��С��
      cout<<"\n������ѭ��С��,����С�����"<<remainder[m]<<"λ";
      cout<<"��"<<i<<"λ\n";//���ѭ���ڵ�λ��
      break;                //�˳�
    }
  }
  system("pause");
  return 0;
}
