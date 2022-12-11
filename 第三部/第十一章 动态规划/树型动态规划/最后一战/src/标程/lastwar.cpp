//���һս 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
 
const int MAX = 1500+10;
int f[MAX][3],data[MAX],son[MAX][MAX],len[MAX],in[MAX];
int n,x,root;

void dp(int x)
{
  if (len[x] == 0)
  {
    f[x][0] = f[x][2] = data[x];
    f[x][1] = 0;
    return;
  }
  for (int i = 1;i <= len[x];i++)
    dp(son[x][i]);
  f[x][0] = 1299999999;
  for (int i = 1;i <= len[x];i++)
  {
    int tmp = 0;
    for (int j = 1;j <= len[x];j++)
      if (i!=j)
        tmp += min(f[son[x][j]][0],f[son[x][j]][2]);
    f[x][0] = min(f[x][0],tmp+f[son[x][i]][2]);
  }
  f[x][1] = 0;
  for (int i = 1;i <= len[x];i++)
    f[x][1] += min(f[son[x][i]][0],f[son[x][i]][2]);
  f[x][2] = data[x];
  for (int i = 1;i <= len[x];i++)
    f[x][2]+=min(f[son[x][i]][0],min(f[son[x][i]][1],f[son[x][i]][2]));
}
 
int main()
{
  freopen("lastwar.in","r",stdin);
  freopen("lastwar.out","w",stdout);  
  scanf("%d",&n);
  memset(data,0,sizeof(data)); //��ÿ�������ʿ���� 
  memset(f,0,sizeof(f)); //dp���飬F[i,j]��������������
  memset(in,0,sizeof(in));//�洢ÿ�������ȣ������ҳ����ڵ�
  memset(son,0,sizeof(son));//�洢ÿ����Ķ��ӽڵ�
  memset(len,0,sizeof(len));//�洢ÿ������ӽڵ����
  for (int i = 1;i <= n;i++)
  {
    scanf("%d",&x);
    scanf("%d%d",&data[x],&len[x]);
    for (int j = 1;j <= len[x];j++)
    {
      scanf("%d",&son[x][j]);
      in[son[x][j]]++;
    }
  }
  for (int i = 1;i <= n;i++)//�ҵ������ 
    if (in[i] == 0)
    {
      root =i;
      break;
    }
  dp(root);
  cout<<min(f[root][0],f[root][2])<<endl;
  return 0;
}
