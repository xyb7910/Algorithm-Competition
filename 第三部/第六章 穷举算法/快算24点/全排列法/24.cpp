//24�� ȫ����ö�� 
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool work(int d[4],int b[3],int c[3],bool output=0) //��������
{
  int i;
  int e[3]={0,0,0}; //�洢ÿ�β��������������� 
  int *a[4]={d,d+1,d+2,d+3};//ԭָ������d��4�����ֵ�ָ�룬���������ָ���µ�λ�� 
  for(i=0;i<3;i++)//i����ö��ÿ�β�����ÿ�β�����Ե�c[i]�����͵�c[i]+1���� ͬʱ����ָ�������洢��λ�� 
  {
    if(output) 
      cout<<*a[c[i]];
    switch(b[i])
    {
      case 1:
        if(output) 
          cout<<'+';
        e[i]=*a[c[i]]+*a[c[i]+1];
        break;
      case 2:
        if(output) 
          cout<<'-';
        e[i]=*a[c[i]]-*a[c[i]+1];
        break;
      case 3:
        if(output) 
          cout<<'*';
        e[i]=*a[c[i]]**a[c[i]+1];
        break;
      case 4:
        if(output) 
          cout<<'/';
        if(*a[c[i]+1]==0 || *a[c[i]]%*a[c[i]+1]!=0) 
          return 0;//�������� 
        e[i]=*a[c[i]] / *a[c[i]+1];
        break;
    }
    if(output) 
      cout<<*a[c[i]+1]<<'='<<e[i]<<endl;    
    if(i==1&&c[0]==1)//����bug 
    {
      if(c[i]==0)
        a[c[i]+2]=&e[i];
      else
        a[c[i]-1]=&e[i];
    }
    a[c[i]]=&e[i];
    a[c[i]+1]=a[c[i]];//����ָ��ָ��
  }
  if(output) 
    return 1;//����������Ǵ�ӡ�����ֱ�ӷ���1 
  if(e[2]!=24) 
    return 0;
  return work(d,b,c,1);//���н����ӡ 
}

int main()
{
  freopen("24.in","r",stdin);
  freopen("24.out","w",stdout);
  int i,j,a[4],b[3];//a[4]����4��ֵ,b[3]����ö��ÿ�β����Ĳ����� 
  for(i=0;i<4;i++) 
    cin>>a[i];
  int c[3]={0,1,2};//0��ʾ��a[0]��a[1]������1��ʾ��a[1]��a[2]������2��ʾ��a[2]��a[3]���� 
  do
  {
    //ö�ٲ����� 
    for(b[0]=1;b[0]<=4;b[0]++) 
      for(b[1]=1;b[1]<=4;b[1]++)
        for(b[2]=1;b[2]<=4;b[2]++)
          if(work(a,b,c))//���ĸ����֡�������������˳����Ϊ��������work�������� 
            return 0;//��ֹ����
  }while(next_permutation(c,c+3));//���ɲ���˳���ȫ���� 
  cout<<"NO"<<endl;
  return 0;
} 
