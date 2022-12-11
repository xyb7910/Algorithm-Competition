#include <iostream>
#include <cstdlib> 
#include <deque>

using namespace std;

deque<int> Q;

int Line[4][25];
const int vec[4] = {5, 3, 4, 24};
int pos[1440], solved[300];

int gcd(int i, int j)//���Լ�� 
{
  int k;
  for (;j != 0;)
  {
    k = i % j;
    i = j;
    j = k;
  }
  return i;
}

long long work(int n)
{
  int i, j, k;
  long long ans = 1;
  for (i = 0; i < n; ++i)
  {
    for (j = Q[i], k = 1; j != i; j = Q[j], ++k);
    /**������ǰ���򾭹����λ�ص�ԭ����λ�ã�������������˼ά 
       С�����n�κ�ص�ԭ����λ�ã�����ڵ�n��Ķ��У�һ��С����n��ǰ��λ�þ����Ǹ�λ�� 
       ����С���1 -> 2 -> 5 -> 6 -> 3 -> 1
        ��j��һ�α��3,6,5,2,1��Ϊj��ʾ������α仯��С���λ������1�ϵ�����3��
       Ҳ���Զ���һ��VISIT���飬д�ɣ� 
       for(VISIT[i]=true,j=Q[i],k=1;!VISIT[j]&&j!=i;VISIT[j]=true,j=Q[i],++k);
        ���Խ�Լ����ʱ�䣬����Ҫ�������� 
    */

		ans = ans * k / gcd(ans, k);//���С����֮ǰ����С������ڵ���С������ 
	}

	Q.clear();

	return ans;//��ն��� 
}

int solve(int n)
{
  int i;
  for (i = 0; i < n; ++i)//��ʼ���� 
    Q.push_back(i);

  for (;;)
  {
    Line[0][++Line[0][0]] = Q.front();//��Line[i][0]��¼�ڼ��У���ۣ����е��� 
    Q.pop_front();
    for (i = 0; i < 3; ++i)//����һ���ӣ�����ӣ�ʮ����ӵ���� 
    {
      if (Line[i][0] == vec[i])//�����дﵽ�����ɼ��� 
      {
		Line[i + 1][++Line[i + 1][0]] = Line[i][Line[i][0]--];//��һ���������һ�� 
        while (Line[i][0] != 0)
		  Q.push_back(Line[i][Line[i][0]--]);//ʣ������������������ 
      }
    }
    if (Line[3][0] == vec[3])//��24Сʱ���� 
    {
      i = Line[3][0]--;//�ȼ�¼����ı�� 
      while (Line[3][0] != 0)//��������������� 
        Q.push_back(Line[3][Line[3][0]--]);
      Q.push_back(Line[3][i]);//����������� 
      break;
    }
  }
  return work(n);
}

int main()
{
  int n;
  freopen("ballclock.in", "r", stdin);
  freopen("ballclock.out", "w", stdout);
  while (cin >> n, n != 0)
  {
    if (solved[n] != 0)///��¼һ�£���һ����ͬ��������Խ�Լʱ�� 
      cout << solved[n];
    else
      cout << (solved[n] = solve(n)) << '\n';
  }
  return 0;
}

