//����ʳ����
#include <bits/stdc++.h>
using namespace std;

int father[50005],Rank[50005];

//����x�ļ��ϣ�����ʱѹ��·�������޸�x��father[x]�Ĺ�ϵ
int FindFather(int x)
{
  int t;
  if(x!=father[x])
  {
    t = father[x];
    father[x]= FindFather(father[x]);
    Rank[x] = (Rank[x]+Rank[t])%3;//����x��father[X]�Ĺ�ϵ
  }
  return father[x];
}

void Union(int x,int y,int d)//�ϲ�x,y���ڵļ���
{
  int xf = FindFather(x);
  int yf = FindFather(y);
  father[xf] = yf;//������xf�ϲ���yf������
  Rank[xf]=(Rank[y]-Rank[x]+3+d)%3;//���� xf ��father[xf]�Ĺ�ϵ
}

int main()
{
  int total=0,n,k,x,y,d,xf,yf;
  cin>>n>>k;
  memset(Rank,0,sizeof(Rank));
  for(int i=1; i<=n; ++i)
    father[i]=i;
  while(k--)
  {
    cin>>d>>x>>y;
    if(x>n||y>n||(d==2 && x == y))//���x��y��n�󣬻�x��x���Ǽٻ�
      total++;//�ٻ�����һ
    else
    {
      xf = FindFather(x);
      yf = FindFather(y);
      if(xf == yf)//���x��f�ĸ������ͬ,����жϸ��Ĺ�ϵ�Ƿ���ȷ��
      {
        if((Rank[x]-Rank[y]+3)%3 != d-1)
          total++;
      }
      else
        Union(x,y,d-1);//����ϲ�x��y
    }
  }
  cout<<total<<endl;
  return 0;
}


