//���������Σ������㷨 
#include <iostream>
using namespace std;
int n,Max,num[20][20],key[20];//key������ң���Ϊ1����Ϊ2��0Ϊδ�߹� 

void fun()
{
  int i=1,j=1,s=num[1][1];//׼������������� 
  do
  {
    if(i<n)//��û���ߵ��ײ�ʱ 
      if(key[i]==0)//����õ�û���߹� 
      {
        key[i]=1;//���Ϊ����߹� 
        i++;//ָ�������ƶ� 
        s=s+num[i][j];//�����µ���� 
      }
      else
        if(key[i]==1)//���������߹� 
        {
          key[i]=2;//���Ϊ�ұ��߹� 
          i++;//������ 
          j++;//������ 
          s=s+num[i][j];//�����µ���� 
        }
        else//������º����¶��߹� 
        {
          key[i]=0;//�ָ�Ϊδ�߹� 
          s=s-num[i][j];//�����ߣ���ȥ���ӵ��� 
          if(key[i-1]==2)//�����һ�����Ҿ��߹� 
            j--;//����ʱ�ص����ϵ� 
          i--;//ָ������ 
        }
    else
    {
      if(Max<s)
        Max=s;
      s=s-num[i][j];//����ʱҪ��ȥ���ӵ�ֵ 
      if(key[i-1]==2)//�����һ���������ߵ�
        j--;//������
      i--;//������
    }
  }while(!(i==0));//��û�л��ݵ����ʱ 
}

void init()
{
  int i,j;
  cin>>n;
  for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
      cin>>num[i][j];
}

int main()
{ freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout); 
  init();
  fun();
  cout<<Max<<endl;
  return 0;
}
