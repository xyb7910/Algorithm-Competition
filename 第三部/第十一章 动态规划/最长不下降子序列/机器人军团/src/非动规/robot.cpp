//����½�����-�Ƕ��� 
#include <iostream>
#include <cstdlib>
#define SIZE 1001
using namespace std;
 
int main()
{
  freopen("robot.in","r",stdin);
  freopen("robot.out","w",stdout);
  int i, j, n, top, temp;
  int stack[SIZE];
  cin >> n;
  top = 0;
  stack[0] = -1;//��һ��Ԫ�ؿ���Ϊ0
  for (i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp > stack[top])//��ջ��Ԫ�ش�������ջ
      stack[++top] = temp;
    else
    {
      int low = 1, high = top;
      int mid;
      while(low <= high)//���ּ���ջ�б�temp��ĵ�һ����
      {
        mid = (low + high) / 2;
        if (temp > stack[mid])
          low = mid + 1;
        else
          high = mid - 1;
      }
      stack[low] = temp;//��temp�滻
    }
  }
  cout << top << endl;//�����������ջ�Ĵ�С
  return 0;
}
