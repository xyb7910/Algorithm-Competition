//�����ħ���� 
#include <fstream>
#include <iostream>

//Ϊ���������Ԥ�����ĸ�����
#define additionSymbol '+'
#define additionNumber 0
#define multiplySymbol 'x'
#define multiplyNumber 1

int max(int x, int y)
{
  return x > y? x : y;
}

int min(int x, int y)
{
  return x < y? x : y;
}

using std::fstream;

fstream fin, fout;
typedef bool symbol;

int part;
int num[50];
symbol opt[50];
//Act[i][j] ָ�ӵ�j����ʼ����i���������Ĵ�,maxActΪ���ֵ,minActΪ��Сֵ 
int maxAct[50][50], minAct[50][50];
/* 
* Action (x1, y1, x2, y2)
(x1, y1)ָ��ߵĲ���,��y1~x1+y1/ *����y1����x1��������* /���в���,ͬ��(x2,y2) 
*/
int maxAddAction(int x1, int y1, int x2, int y2);
int minAddAction(int x1, int y1, int x2, int y2);
int maxMulAction(int x1, int y1, int x2, int y2);
int minMulAction(int x1, int y1, int x2, int y2);

int (*maxAction[2])(int x1, int y1, int x2, int y2);
int (*minAction[2])(int x1, int y1, int x2, int y2);

int main(int argc, char* argv[])
{
  bool fopen(void);
  bool read(void);
  bool solve(void);
  bool write(void);
  fopen() && read() && solve() && write();
  return 0;
}

bool fopen(void)
{
  fin.open("MagicArray.in", std::ios::in);
  fout.open("MagicArray.out", std::ios::out);
  return bool(fin) && bool(fout);
}

bool read(void)
{
  bool Ok = true;
  int i;
  fin >> part;
  bool readNum(int& ptr);
  bool readOpt(symbol &Opt);
  for (i = 0; i < part; ++i)
    Ok &= readNum(num[i]) && readOpt(opt[i]);
  return Ok;
}

bool readNum(int& ptr)
{
  return fin >> ptr;
}

bool readOpt(symbol& Opt)
{
  char Sym;
  fin >> Sym;
  // �Ѷ���ķ���ת��Ϊ���ִ��档 
  switch (Sym)
  {
    case additionSymbol: Opt = additionNumber; break;
    case multiplySymbol: Opt = multiplyNumber; break;
    default: return false;
  }
  return true;
}

bool solve(void)
{
  int i, j, k;
  // ���������㵱Ȼ��ԭֵ 
  for (i = 0; i < part; ++i)
  {
    maxAct[0][i] = num[i];
    minAct[0][i] = num[i];
  }
  const int index(const int _index);
  maxAction[additionNumber] = maxAddAction;
  maxAction[multiplyNumber] = maxMulAction;
  minAction[additionNumber] = minAddAction;
  minAction[multiplyNumber] = minMulAction;
  // action(left, right) ָ��left��right�������������һ������ left < right
  for (i = 1; i < part; ++i)/// ��һ�����й�����i������� 
	for (j = 0; j < part; ++j)/// _left = index(j), _right = index(i + j)
	{
	  maxAct[i][j] = 0x80000000;
	  minAct[i][j] = 0x3FFFFFFF;
	  //leftPart = action(_left, j + k), rightPart = 
      //action(index(j + k + 1), _right)�� ��kָ��߲��ְ���k���������
      for (k = 0; k < i; ++k) 
	  {
	    maxAct[i][j]=max(maxAct[i][j], maxAction[opt[index(j + k)]](k, j, i - k - 1, index(j + k + 1)));
	    minAct[i][j]=min(minAct[i][j], minAction[opt[index(j + k)]](k, j, i - k - 1, index(j + k + 1)));
	  }
	}
  return true;
}

const int index(const int _index)/// @remark index < 2 * part
{
  return _index < part? _index : _index - part;
}

bool write(void)
{
  int maxsolve = 0x80000000;
  for (int i = 0; i < part; ++i)
    maxsolve = maxsolve > maxAct[part - 1][i]? maxsolve : maxAct[part - 1][i];
  fout << maxsolve << std::endl;
  return true;
}

int maxAddAction(int x1, int y1, int x2, int y2)//�ӷ� 
{
  return maxAct[x1][y1] + maxAct[x2][y2];
}

int minAddAction(int x1, int y1, int x2, int y2)
{
  return minAct[x1][y1] + minAct[x2][y2];
}

// �˷���ֱ�Ӱ����ֽ��ȡ�����С�� 
int maxMulAction(int x1, int y1, int x2, int y2)
{
  return max(max(maxAct[x1][y1] * maxAct[x2][y2],maxAct[x1][y1] * minAct[x2][y2]),
	max(minAct[x1][y1] * maxAct[x2][y2], minAct[x1][y1] * minAct[x2][y2]));
}

int minMulAction(int x1, int y1, int x2, int y2)
{
  return min(min(maxAct[x1][y1] * maxAct[x2][y2],maxAct[x1][y1] * minAct[x2][y2]),
	min(minAct[x1][y1] * maxAct[x2][y2], minAct[x1][y1] * minAct[x2][y2]));
}
