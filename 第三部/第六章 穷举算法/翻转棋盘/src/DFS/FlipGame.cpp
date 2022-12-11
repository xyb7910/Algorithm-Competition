//��ת���̣�DFS 
#include <iostream>
#include <cstdlib>
using namespace std;
 
bool map[6][6], Find = false;//��������Ҫд��find,���г�ͻ 
int step;
int dr[5] = {-1, 0, 0, 0, 1};//�������������ӵ�λ��ֵ 
int dc[5] = {0, -1, 0, 1, 0};
 
bool OK()//�ж��Ƿ�ɹ� 
{                           
  for(int i = 1; i <= 4; i ++)
    for(int j = 1; j <= 4; j ++)
      if(map[i][j] != map[1][1])
        return false;
  return true;
}
 
void flip(int row, int col)//������(row,col),�ı�map[][]״̬
{             
  for(int i = 0; i < 5; i ++)
  {
    int x = row + dr[i];
    int y = col + dc[i];
    map[x][y] = !map[x][y];
  }
}
 
void dfs(int row, int col, int dep)//��ת��(row,col),depΪ���
{     
  if(dep == step)
  {
    Find = OK();
    return;
  }
  if(Find || row == 5) 
    return;

  flip(row, col);//��ת��(row,col)
  if(col < 4) 
    dfs(row, col + 1, dep + 1);
  else 
    dfs(row + 1, 1, dep + 1);

  flip(row, col);//��ԭ��(row,col)
  if(col < 4) 
    dfs(row, col + 1, dep);
  else 
    dfs(row + 1, 1, dep);
}
 
int main()
{
  freopen("FlipGame.in","r",stdin);
  freopen("FlipGame.out","w",stdout);  
  char c;
  for(int i = 1; i <= 4; i ++)
    for(int j = 1; j <= 4; j ++)
    {
      cin >> c;
      if(c == 'b') 
        map[i][j] = true;
    }
  for(step = 0; step <= 16; step ++)//16�����ӣ���ö��0~16��
  {
    dfs(1, 1, 0);
    if(Find) 
      break;
  }
  if(Find) 
    cout<<step<<endl;
  else 
    cout <<"Impossible\n";
  return 0; 
}
