//ȫ��������-���ֵ��� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define Swap(i,j){int t;t=a[i];a[i]=a[j];a[j]=t;}//Ԥ�������������ĺ��� 
using namespace std;
int total=0,n;
int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void print()
{
  for(int i=0;i<n;i++)
    cout<<a[i];
  cout<<endl; 
}

void permutation(int from,int to)//��һ���Ż���ʡ�Եڶ������� 
{
  int i,j;
  if(from==to)  //�ݹ���� 
  {
    print();//��ӡ���  
    total++;
  }
  else
    for(i=from;i<=to;++i)//��from~to����Ԫ���������1��Ԫ�ؼ���from��Ԫ�ػ��� 
    {
      Swap(i,from);//�������� 
      permutation(from+1,to);//�ݹ���from+1~to����ȫ���� 
      Swap(i,from);//�ָ�                  
    }                          
}

int main()
{ 
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout);  
  cin>>n;
  permutation(0,n-1);
  cout<<total<<endl;
  return 0;
}
