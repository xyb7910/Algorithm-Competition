//��ȡ�ļ���ĩβ 
#include <iostream>
using namespace std;

int a[500000],i,n;
int main()
{
  freopen("in.txt","r",stdin); //��in.txt�ж�ȡ����
  freopen("out.txt","w",stdout);//�����out.txt�ļ�
  for(i=0;scanf("%d",&a[i])!=EOF;i++);//scanfΪc���Զ�д��ʽ��ֱ�������ļ�ĩβ
    n=i;
  for(i=0;i<=n;i++)
     cout<<a[i]<<' '; 
  return 0;    
}
