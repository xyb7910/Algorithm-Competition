//͹��������ǻ���
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
#define NMAX 50

//������������ 
typedef int BN;

int n;
int q[NMAX];//����Ȩֵ 
BN f[NMAX][NMAX]; //f(i, j)�Ӷ���i��j����СȨֵ��  
short f_last[NMAX][NMAX];//ʹf(i, j)Ȩֵ��С��k 
short f_ans[NMAX-2][3];//�ָ�������ζ��� 
int idx;//��ǰ�����ж����� 

ifstream fin("Triangle.in");
ofstream fout("Triangle.out");

BN calc(int i, int j);
void prt(int i, int j);
int comp(const void* a, const void* b);

int main()
{
  int i;
  fin >> n;//����
  for(i = 1; i <= n; ++i)
    fin >> q[i];
  fout << calc(1, n) << "\n";//�Ż��ݹ���f(1, n) 
  prt(1, n);//�ݹ鱣��ָ�����f_ans[][3]  
  qsort(f_ans, idx, 3*sizeof(short), comp);//�ָ������ֵ������� 
  for(i = 0, --idx; i < idx; ++i)//���
    fout << f_ans[i][0] << " "
         << f_ans[i][1] << " "
         << f_ans[i][2] << ",";
  fout << f_ans[i][0] << " "
       << f_ans[i][1] << " "
       << f_ans[i][2];
  return 0;
}

BN calc(int i, int j)//��f(i, j)
{
  if(f[i][j] != 0)//�Ż�����ֹ�ظ���ֵ 
    return f[i][j];
  if(j - i == 1)//f(i, i+1) = 0
    return 0;
    
  //f(i,j)=Min{f(i,k)+f(k,j)+q[i]*q[k]*q[j]}(0 < i < k < j)
  int k = i + 1;
  BN *p = &f[i][j];
  BN t;
  *p = calc(i, k) + calc(k, j) + (BN)q[i] * q[k] * q[j];
  f_last[i][j] = k;
    
  for(++k; k < j; ++k)
    if((t=calc(i,k)+calc(k,j)+(BN)q[i]*q[k]*q[j])< *p)
    {
      *p = t;
      f_last[i][j] = k;
    }
  return *p;
}

void prt(int i, int j)//��ӡi ~ j�ķָ���
{
  if(j - i == 2)
  {
    //i, j�м�ֻ��һ�����㣬���������� �����浽���� 
    f_ans[idx][0] = i;
    f_ans[idx][1] = i + 1;
    f_ans[idx][2] = j;
    ++idx;
  }
  else
  {
    if(f_last[i][j] - i > 1)//i ~ k ��������
      prt(i, f_last[i][j]);
    //�ָ����������  
    f_ans[idx][0] = i;
    f_ans[idx][1] = f_last[i][j];
    f_ans[idx][2] = j;
    ++idx;
        
    //k ~ j �������� 
    if(j - f_last[i][j] > 1)
      prt(f_last[i][j], j);
  }
}

//���зָ����ص�������������a, b, c��С�������� 
int comp(const void* a, const void* b)
{
  int ctmp;
  if((ctmp = ((const short*)a)[0] - ((const short*)b)[0]) != 0)
    return ctmp;
  else
  {
    if((ctmp = ((const short*)a)[1] - ((const short*)b)[1]) != 0)
      return ctmp;
    else
      return ((const short*)a)[2] - ((const short*)b)[2];
  }
}
