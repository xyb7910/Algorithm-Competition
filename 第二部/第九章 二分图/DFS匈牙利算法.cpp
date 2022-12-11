//ƹ�����
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int  Link[101]; //����Link[1]=3����Ů1����3��ƥ�� ����
bool visit [101]; //��¼Ů�˶�Ա����Ƿ񱻷��ʹ� ����
bool Map[101][101];//Map[a][b]=1����a,b�����б����� ����

bool dfs(int boy)
{
  for (int girl=1; girl<=m; girl++) //����Ů�˶�Ա
    if (Map[boy][girl]==1 && !visit[girl]) //��girl��boy�б���δ������
    {
      visit[girl] = true; //���iΪ�ѷ���
      if(Link[girl]==0||dfs(Link[girl]))//��girlδƥ���girlƥ���boy������· ��
      {
        Link[girl]=boy; //���ת
        return true; //���� ����
      }
    }
  return false;//������·�򷵻�false
}

int main()
{
  int a,b,ans=0;
  cin>>n>>m>>k;//n,mΪ�С�Ů�˶�Ա������kΪ����
  for(int i=1; i<=k; i++)
  {
    cin>>a>>b;
    Map[a][b]=true;
  }
  for (int i=1; i<=n; i++)//������˶�Ա����
  {
    memset(visit, 0, sizeof(visit));//����ϴν����ʱ��
    if (dfs(i))
      ans++; //�ӽ��i������չ
  }
  cout<<ans<<endl;
  return 0;
}

