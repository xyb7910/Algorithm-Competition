//�ӷֶ�����
#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int d[31];
int f[31][31];
int root[31][31];//��¼�ڵ㣬�����������

int df(int left, int right)
{
  int score = -1;
  int node = -1;//�������
  if(f[left][right] != -1)//��������ֵ
  {
    score = f[left][right];
    node = root[left][right];
  }
  else if(left > right)//��Ϊ��
    score = 1;
  else if(left == right)//����Ҷ���
  {
    score = d[left];
    node = left;
  }
  else//����������ӽ��
  {
    for(int i=left; i<=right; i++)//����
    {
      int tmp=df(left,i-1)*df(i+1,right)+d[i];
      if(score<tmp)
      {
        score = tmp;
        node = i;//���¸��ڵ�Ϊi
      }
    }
  }
  f[left][right] = score;
  root[left][right] = node;
  return score;
}

void print(int left, int right)//�������
{
  if(left <= right)
  {
    cout<<root[left][right]<<" ";
    print(left,root[left][right]-1);
    print(root[left][right]+1,right);
  }
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>d[i];
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
    {
      f[i][j] = -1;  //����ʼ��Ϊ-1
      root[i][j] = -1;
    }
  cout<<df(1,n)<<endl;
  print(1,n);
  cout<<endl;
  return 0;
}
