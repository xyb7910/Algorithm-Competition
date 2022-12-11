//�˷���Ϸ-ȫ���з� 
#include <iostream>
using namespace std;
int card[20],permutation[20],n,ans=2147483647;
bool used[20];

void calculate()
{
  int i, sum=0, remove[20];
  for(i=1; i<=n+2; i++)  
    remove[i]=1;//remove[i]���ڱ��card[i]�Ƿ�ȡ��,0��ʾ��ȡ��
  for(i=1; i<=n; i++)
  {
    remove[permutation[i]+1]=0;
    int mul=card[permutation[i]+1];//ȡ�����Ƶ�ֵ����mul 
    int j=permutation[i]+1;//ȡ�����Ƶ�λ�ø�ֵ��j 
    while(remove[j]==0) 
      j++;  //�ҵ��ұߵ���
    mul*=card[j];     
    while(remove[j-1]==0) 
      j--;  //�ҵ���ߵ���
    mul*=card[j-1];
    sum+=mul;  //���˻������ܷ�
  }
  if(sum<ans)//ѡ����Сֵ 
    ans=sum;
}

void dfs(int dep)
{
  if(dep > n)
    calculate();
  else
    for(int i=1; i<=n; i++)
      if(used[i]==0)
      {
        permutation[dep]=i;
        used[i]=1;
        dfs(dep+1);
        used[i]=0;
      }
}

int main()
{
  freopen("Puzzle.in","r",stdin);
  freopen("Puzzle.out","w",stdout);
  int i;
  cin>>n;
  for(i=1; i<=n; i++)
    cin>>card[i];
  n-=2;  //Ҫȡ����ֻ��n-2��
  dfs(1);
  cout<<ans <<endl;
  return 0;
}
