//����������-������ 
#include <iostream>
using namespace std;
int b[10000+1]; 
int i,j,k,m,n,t;

void init()
{
  freopen("martian.in","r",stdin);
  freopen("martian.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=n;i++)
    cin>>b[i];
}

void out()
{
  for(i=1;i<=n-1;i++)
    cout<<b[i]<<' ';
  cout<<b[n]<<endl;
}

void work()
{
  for(i=1;i<=m;i++)//��1 ��M�� 
  {
     for(j=n-1;j>=1;j--)//�ҵ��������ӵ�λ������λ 
       if(b[j]<b[j+1])//����12354��1����ֻ��3������λ�� 
         break;
     for(k=n;k>=1;k--)//�ҵ���С�����ӵ����� 
       if(b[k]>b[j])//����12354��1����С�����ӵ�������4 
         break;
     
     t=b[j];//��������ԭ�������� ��
     b[j]=b[k];//����12354��1����3��4�������������Ϊ12453 
     b[k]=t;  //��12453���������ս��������12435��Ҫ���� 
     
     j=j+1;//�����һλ 
     k=n;
     while((j<k))//�Ѻ���������൱�ڴ�С�������� 
     {
       t=b[j];  
       b[j]=b[k];
       b[k]=t;
       j++;
       k--;
     }
  }
}

int main()
{
  init();
  work();
  out();
  return 0;
}
