//��ͨ��������-ö���㷨 
#include <iostream>
#include <cstdlib>
using namespace std;
int N,S;
int W[40];// ��ʼ��ÿ����Ʒ������
int flag[40]={0};// �������

void Print()// ��ӡ���
{
  for(int i=0;i!=N;i++)
  if (1 == flag[i])
    cout<<W[i]<<" ";
  cout<<endl;
  exit(0);
}

int main()
{
  freopen("Backpack.in","r",stdin);
  freopen("Backpack.out","w",stdout);  
  int sum,all_count=1;  
  cin>>S>>N;
  for(int i=0;i<N;i++)
    cin>>W[i];
  for (int i=0;i!=N;i++)// �������п����Դ���,��2��n�η�
    all_count*=2;
    
  for(int num=0;num<=all_count;++num)
  {
    for (int i=0;i!=N;i++)//�о�����flag�������
      if ( flag[i]==0 )
      {
        flag[i]=1;
        continue;
      }
      else 
      {
        flag[i]=0;
        break;
      }
      sum=0;//����������ʼ��Ϊ0
      for (int i=0;i!=N;i++)//����Ǽ�������ѡ����Ʒ������
        if (flag[i]==1)
          sum+=W[i];
      if (sum == S)//��ӡ���� 
        Print();        
  } 
  cout<<"Failed!\n";  
  return 0;
}
