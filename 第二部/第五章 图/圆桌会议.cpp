//Բ������ 
#include <bits/stdc++.h>
using namespace std;
#define M 410

int  ans[M],g[M][M];
bool vis[M];
int n,m,t,ansi;//ansiΪ���ĸ��� 

void Reverse(int ans[M],int s,int t)//��ans������s��t�Ĳ��ֵ���
{
  while(s<t)
    swap(ans[s++],ans[t--]);
}

void Expand()//��t�㿪ʼѰ�ұ�������չ
{
  while(1)
  {
    bool flag=0;
    for(int i=1; i<=n; ++i)
      if(g[t][i] && !vis[i])
      {
        ans[ansi++]=i;
        vis[i]=true;
        t=i;
        flag=1;
        break;
      }
    if(!flag) break;
  }
}

void Hamilton()
{
  int i,j,s=1;//��ʼ��sȡ1�ŵ�
  for(i=1; i<=n; i++)//��������s�ĵ�
    if(g[s][i]) break;
  t=i;//ȡ��������s�ĵ�Ϊt
  vis[s]=vis[i]=true;//����ѷ���
  ans[0]=s;//������뻷
  ans[1]=t;
  ansi=2;//ͳ�ƻ��ĸ���
  while(1)
  {
    Expand();//��t�㿪ʼ������չ
    Reverse(ans,0,ansi-1);//����ǰ�õ������е���
    swap(s,t);//s��t����
    Expand();//��t������չ��ʵ���Ǵ�ԭ���е�s������չ
    if(!g[s][t])//���s��t�����ڣ����е���
    {
      for(i=1; i<ansi-2; i++)//��g�������ҵ�i
        if(g[ans[i]][t] && g[s][ans[i+1]])//ʹans[i]��t��,ans[i+1]��s��
          break;
      t=ans[++i];
      Reverse(ans,i,ansi-1);//����ans[i+1]��t���ֵ�ans[]����
    }
    if(ansi==n)//�����ǰs��t����
      return;//�����ǰ�����а���n��Ԫ�أ��㷨����
    for(j=1; j<=n; j++)//�����<n,�ҵ�ans[i],ʹans[i]��ans[]��һ������ 
    {
      if(vis[j]) continue;//���ѷ��ʹ�������
      for(i=1; i<ansi-2; i++)//��ans[i]�㴦�ѻ�·�Ͽ�,�ͱ����һ��·��
        if(g[ans[i]][j])     //�Ӷϵ㴦������չ�Ϳ�����
          break;
      if(g[ans[i]][j]) break;
    }
    s=ans[i-1];
    t=j;
    Reverse(ans,0,i-1);//��ans[]��s��ans[i-1]���ֵ�ans[]����
    Reverse(ans,i,ansi-1);//��ans[]��ans[i]��t�Ĳ��ֵ���
    ans[ansi++]=j;//����j���뵽ans[]��β��
    vis[j]=true;
  }
}

int main()
{
  while(scanf("%d%d",&n,&m),n|m)//��n,m��Ϊ0ʱ 
  {
    n*=2;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    for(int i=0; i<=n; i++)
      for(int j=0; j<=n; j++)
        i==j?g[i][j]=0:g[i][j]=1;//��ͼ��ʼ��
    int a,b;
    for(int i=1; i<=m; i++)
    {
      scanf("%d%d",&a,&b);
      g[a][b]=g[b][a]=0;//������ͼ
    }
    Hamilton();
    for(int i=0; i<n; i++)
      i!=n-1?printf("%d ",ans[i]):printf("%d\n",ans[i]);
  }
  return 0;
}
