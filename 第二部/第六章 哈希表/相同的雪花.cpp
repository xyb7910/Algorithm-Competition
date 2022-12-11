//��ͬ��ѩ�� 
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

const int M = 90001; //hash������ȡ�����

int snow[100005][6]; //�洢ѩ����Ϣ
vector<int> hash[M]; //hash�����д洢����snow������±�

bool isSame(int a, int b)//�ж�a��b�Ƿ�ͬ�� 
{
  for(int i=0;i<6;i++)
  {
    //˳ʱ��
    if((snow[a][0] == snow[b][i] &&
		snow[a][1] == snow[b][(i+1)%6] &&
		snow[a][2] == snow[b][(i+2)%6] &&
		snow[a][3] == snow[b][(i+3)%6] &&
		snow[a][4] == snow[b][(i+4)%6] &&
		snow[a][5] == snow[b][(i+5)%6])
		||   //��ʱ��
		(snow[a][0] == snow[b][i] &&
         snow[a][1] == snow[b][(i+5)%6] &&
         snow[a][2] == snow[b][(i+4)%6] &&
         snow[a][3] == snow[b][(i+3)%6] &&
         snow[a][4] == snow[b][(i+2)%6] &&
         snow[a][5] == snow[b][(i+1)%6]))
			
      return true;
  }
  return false;
}

int main()
{
  int n;
  int i,j;
  cin>>n;
  for( i = 0; i < n; i++) 
    for( j = 0; j < 6; j++)
      cin>>snow[i][j];
	
  int sum, key;
  for(i = 0; i < n; i++) 
  {
    sum = 0;//���ѩ����������ĺ�
    for( j = 0; j < 6; j++) 
      sum += snow[i][j];
	key = sum % M; //���key
		
    //�ж��Ƿ���hash����hash[key]�洢��ѩ����ͬ
    for(vector<int>::size_type j = 0; j < hash[key].size(); j++) 
	{
       if(isSame(hash[key][j], i))//����ͬ 
	   {
          cout<<"Twin snowflakes found."<<endl;
          exit(0);
       }
    }
    hash[key].push_back(i);//��û�ҵ���ͬ�� 
  }
  cout<<"No two snowflakes are alike."<<endl;
  return 0;
}
