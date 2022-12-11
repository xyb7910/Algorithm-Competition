//������߾����㷨2 
#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 90000000;
long long C[MAX][2];

ifstream fin("combin.in");
ofstream fout("combin.out"); 

void combin(int M,int N)
{
  int m,n,M1=0, M2=1;
  C[0][M1] = 1; //��ʾC(1,0)=1
  C[1][M1] = 1; //��ʾC(1,1)=1

  for(int i = 2; i <= M; ++i)//����M<=1000000����˼�ʹ�߾�������Ҳ����Ϊ��ʱ
  {      
    C[0][M2] = C[i][M2] = 1;//��ʾC(i,0)=1,��ʾC(i,i)=1
    for(int j = 1; j < i; ++j)
    {
      C[j][M2] = C[j-1][M1] + C[j][M1];
      if (j>=N)//�Ż���֦ 
        break;
    }
    swap(M1,M2);//�������齻��ֵ 
  }
  fout << C[N][M1] <<'\n';
}

int main()
{
 
  int m, n;
  fin >> m >> n;
  m=m+n-2;
  n-=1; 
  combin(m,n);
  fin.close();
  fout.close();
  return 0;
}
