//��������STL�� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector> //��Ӵ˾� 
#include <queue>��//��Ӵ˾䡡 
using namespace std;
vector <int>vec;//�洢����
vector<int>::iterator point;//����һ��ָ��vector��ָ�� 
queue <int>que[10];//����Ͱ 
int n,temp,IntMax=0;

int maxbit(int IntMax)//�����λ��
{
  int digit=1;
  while(IntMax>0)
  {
    digit++;
    IntMax/=10;
  }
  return digit-1;
}

void VecToDeque(vector<int>vec,queue<int>deq[],int n)//��ĳλ����������Ͱ
{
  for(point=vec.begin();point!=vec.end();++point)
  {
    int itor=(*point)/n%10; 
    deq[itor].push(*point);//��ֵ��Ͱ 
  }
}

void Colect(vector<int>&vect,queue<int>deq[])//��Ͱ���źõ��������������
{
  int count=0;
  for(int i=0;i<10;i++)
  {
    while(!deq[i].empty())//�����Ϊ�� 
    {
	  vect[count]=deq[i].front();//ȡ����е�һ��ֵ 
      count++;
      deq[i].pop();//���� 
    }
  }
}

void RadixSort(vector<int>&vec)//�������� 
{
  int count=maxbit(IntMax);
  int power=1;
  for(int i=1;i<=count;i++)
  {
    VecToDeque(vec,que,power);//���ΰ�λ���䵽Ͱ 
    Colect(vec,que);//�������� 
    power*=10;
  }
}

void output()//��� 
{
  for(point=vec.begin();point!=vec.end();++point)
    cout<<*point<<" ";
  cout<<'\n';     
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);  
  cin>>n;  
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    vec.push_back(temp);//vector��˲����� 
    if(temp>IntMax)//�ҳ����ֵ 
      IntMax=temp;
  }
  RadixSort(vec);
  output();
  return 0;
}
