//�������� 
#include<iostream>
using namespace std;
#define N 50010
int tmp[N][100],map[27][27],rudu[27],ans[27];
bool word[27];
int n,js,m,d,p;
string s;
void juge(int a,int b)  //��һ�������Ż�
{
  if(tmp[a][b]==0||tmp[a+1][b]==0)return ;
  if(tmp[a][b]!=tmp[a+1][b])
  {
    map[tmp[a][b]][tmp[a+1][b]]=1;
    rudu[tmp[a+1][b]]++;
  }
  else juge(a,b+1);
}
bool topo()  //����
{
  for(int i=1; i<=27; ++i) //ͳ�Ƴ��ֵ���ĸ����
    if(word[i])m++;
  for(int i=1; i<n; ++i)
    juge(i,1);
  while(p!=m)
  {
    js=0;
    for(int i=1; i<=m; ++i)
    {
      if(rudu[i]==0)
      {
        d=i;
        rudu[i]=-1;
        js++;
      }
    }
    if(js!=1)return false;//�������������1.û�������0�ģ�2.�����0���ж���㣻
    ans[++p]=d;
    for(int i=1; i<=m; ++i)
    {
      if(map[d][i])
      {
        map[d][i]=0;
        rudu[i]--;
      }
    }
  }
  return true;
}
void out_()  //���
{
  for(int i=1; i<=tmp[n+1][0]; ++i)
  {
    for(int j=1; j<=m; ++j)
    {
      if(tmp[n+1][i]==ans[j])
      {
        cout<<char(j+96);
        break;
      }
    }
  }
}
int main()
{
  memset(tmp,0,sizeof(0));
  cin>>n;
  for(int i=1; i<=(n+1); ++i)
  {
    cin>>s;
    for(int j=0; j<s.size(); ++j)
    {
      tmp[i][++tmp[i][0]]=int(s[j]-96);
      word[s[j]-96]=1;
    }
  }
  if(topo()==0)cout<<0;
  else out_();
  return 0;
}
