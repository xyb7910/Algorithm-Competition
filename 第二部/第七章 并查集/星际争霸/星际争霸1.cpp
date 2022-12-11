//�Ǽ�����1
#include <bits/stdc++.h>
using namespace std;

int FindFather(int father[], int pos)//Ѱ�ҵ�i��ս�����ڵ�����ս�����е�ͷ
{
  return father[pos] < 0? pos:FindFather(father, father[pos]);
}

void Unite(int father[], int posI, int posJ)//�ϲ�ָ��
{
  int fI = FindFather(father, posI); //����ȥѰ�����ڵ�����ս������ͷ
  int fJ = FindFather(father, posJ);
  //��i��ս�����У���Ϊһ�����������j��ս�����е�β��
  int rear = -father[fJ]; //posJ���ڶ��еĶ�β
  father[fJ] = father[fI];
  father[fI] = rear;
}

int Search(int father[], int posI, int posJ)//��ѯָ��
{
  int fI = FindFather(father, posI); //posI���ڶ��еĶ�ͷ
  int rear = -father[fI];           //posI���ڶ��еĶ�β
  while (rear != posI && rear != posJ) //Ѱ��posI��posJ�ڶ����е�λ��
    rear = father[rear];
  if (rear == posJ)//������ҵ�posJ������posJ = posI������Ѱ��posJ
    posJ = posI;
  int len = -1;
  while (rear != father[fI] && rear != posJ)//Ѱ��posJ�ڶ����е�λ��
  {
    len++;
    rear = father[rear];
  }
  //�����i��ս�����j��ս����ǰ����ͬһ���ϣ������-1
  if (rear != posJ)
    len = -1;
  return len;
}

int main()
{
  const int MAX = 30000;
  int *father = new int[MAX+1];
  for (int i=0; i<=MAX; i++) //���е�����Ԫ��ֵ����ʼ��Ϊ������ŵ��෴��
    father[i] = -i;//father[i]  Ϊ�Լ��ĸ��� ��������fatherΪβ���
  int T;
  cin >> T;
  char ch;
  int  posI, posJ;
  for (int i=0; i<T; i++)
  {
    cin >> ch;
    cin >> posI >> posJ;
    if (ch == 'M')
      Unite(father, posI, posJ);
    else
      cout << Search(father, posI, posJ) << endl;
  }
  delete []father;//�ͷ�father�ڴ�ռ� 
  return 0;
}

