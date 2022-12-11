//�������� 
#include<iostream>  
#include<vector> 
using namespace std; 

int n,m,k; 
vector<int>v[201]; 
int vis[201]; 
int match[201]; 

int dfs(int i) 
{ 
  for(int j=0;j<v[i].size();++j) 
  { 
    if(!vis[v[i][j]+n])//+n�ǵ������  
    { 
      vis[v[i][j]+n]=1; 
      if(match[v[i][j]+n]==-1||dfs(match[v[i][j]+n])) 
      { 
        match[v[i][j]+n]=i; 
        return 1; 
      } 
    } 
  } 
  return 0; 
} 

int main() 
{ 
  int i,a,b,c; 
  while(scanf("%d",&n),n) 
  { 
    scanf("%d%d",&m,&k); 
    for(i=0;i<=m+n;++i) 
      v[i].clear(); 
    for(i=1;i<=k;++i) 
    { 
      scanf("%d%d%d",&a,&b,&c); 
      if(b&&c) 
        v[b].push_back(c);//ֻ��Ҫ��X��ָ��Y���ͺ��� dfs()��ʱ���ֻ�Ǵ�X��Y  
    } 
    a=0;//ƥ�䲿��  
    memset(match,-1,sizeof(match)); 
    for(i=1;i<=n;i++) 
    { 
      memset(vis,0,sizeof(vis)); 
      if(dfs(i)) 
        a++; 
    }  
    cout<<a<<endl; 
  }
  return 0; 
}
