//�涴 
#include <iostream>
using namespace std;
int w[1000+1][1000+1],d[1000+1];
int n,m;
char change;

void init()
{
  cin>>n>>m;//������ϵ���������ĸ���
  int x,y,v,i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      w[i][j]=INT_MAX; 
  for(i=1;i<=m;i++) 
  {
    cin>>x>>y>>v;
    w[x][y]=v; //ע���Ϊ����ͨ��
  }    
}

void bellman_ford(int x)
{
  int i,j,k; 
  for(i=1;i<=n;i++)
    d[i]=w[x][i];
  d[x]=0;
  for(k=1;k<=n-1;k++)//�ɳ�n-1�� 
    for(j=1;j<=n;j++)//ö��ÿ���㣬ÿ���㶼�п��ܻ�������·��
      for(i=1;i<=n;i++)//����ĳ��i����j 
        if((w[i][j]!=INT_MAX)&&(d[i]!=INT_MAX)&&(d[j]>d[i]+w[i][j])) 
          d[j]=d[i]+w[i][j];
  change=1;//�ж����޻�·,Ĭ�ϲ����ڣ�change=1
  for(i=1;i<=n;i++)//�ɳ۲����ж��Ƿ���ڸ�Ȩ��·
    for(j=1;j<=n;j++)
      if((w[i][j]!=INT_MAX)&&(d[i]!=INT_MAX)&&(d[j]>d[i]+w[i][j])) //���d[j]�������̣�����ڸ�Ȩ��· 
        change=0; //����change=0
  if(change)
    cout<<"Not possible"<<endl;
  else
    cout<<"Possible"<<endl;
}

int main()
{
  init();
  bellman_ford(1);//�Ӷ��㣱����
  return 0;
}
