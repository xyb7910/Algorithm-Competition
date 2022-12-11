//����Ѳ��2  ̰�� 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1510

int main()
{
  int n,in[MAXN];//in[]ͳ�Ƶ�Ķ��� 
  bool vis[MAXN];
  while(scanf("%d",&n)!=EOF)
  {
    memset(in,0,sizeof(in));
    vector<int>road[MAXN];
    for(int i=0; i<n; i++)
    {
      int a,b,c;
      scanf("%d:(%d)",&a,&b);
      for(int j=0; j<b; j++)
      {
        cin>>c;
        road[a].push_back(c);
        road[c].push_back(a);
        in[a]++;
        in[c]++;
      }
    }
    if(n==1)
    {
      cout<<1<<endl;
      continue;
    }
    queue<int>st;
    for(int i=0; i<n; i++)
      if(in[i]==1)//������Ϊ1�ĵ����vector 
        st.push(i);
    int sum=0;
    memset(vis,false,sizeof(vis));
    while(!st.empty())//�����в�Ϊ�գ���������ѭ�� 
    {
      int u=st.front();
      st.pop();
      if(vis[u])  continue;
      for(int i=0; i<(int)road[u].size(); i++)
      {
        int t=road[u][i];
        if(!vis[t])
        {
          vis[t]=1;
          sum++;
          for(int j=0; j<(int)road[t].size(); j++)
          {
            int q=road[t][j];
            in[q]--;
            if(in[q]==1&&!vis[q])
              st.push(q);
          }
        }
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
