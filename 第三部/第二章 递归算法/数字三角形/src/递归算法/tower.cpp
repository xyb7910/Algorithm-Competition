//���������εݹ��㷨 
#include <iostream>
#include <cstdlib>
using namespace std;
int a[1001][1001],n;

int fun(int x,int y)//xΪ�У�yΪ�� 
{ 
  int r,l; 
  if(x==n)//�������������������ײ㣬���ر���ֵ 
    return a[x][y];
  l=fun(x+1,y);//���������ߣ�Ҫ֪����x,y������ֵ����������һ�����ҵ���ֵ 
  r=fun(x+1,y+1);//���������� 
  if(l>r)
   return l+a[x][y];
  else
   return r+a[x][y];         
}

int main()
{
  freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout);
  int i,j;
  cin>>n;
  for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
      cin>>a[i][j]; 
  cout<<fun(1,1)<<'\n';//����㣨1��1����ֵ 
  return 0;
}
