//���������⣭�ɣģ�* 
#include <iostream>
#include <cstdlib>
using namespace std;

inline int Abs(int a) 
{
  return a>0 ? a : -a;
}

int limit=-1;//�������
char ans[100];

//���ֱ�ʾ����0Ϊ�ϣ�1Ϊ�ң�2Ϊ�£�3Ϊ��
char cdir[4]={'u','r','d','l'};//�����Ӧ��ĸ
char opcdir[4]={'d','l','u','r'};//�������Ӧ��ĸ

/* ĳ�����������е�λ��loc��һ��0~8��������ʾ���ֱ��Ӧ����λ��
   0 1 2
   3 4 5
   6 7 8
   ��ô��λ��������Ϊloc/3 , ������Ϊloc%3  (����0��ʼ����
   ��λ��1�ڵ�0�е�1��  */
/*Ŀ��״̬
  1 2 3
  8 0 4
  7 6 5  */
const int aim_state[9]={1,2,3,8,0,4,7,6,5};//Ŀ��״̬
const int aim_loc[9]={4,0,1,2,5,8,7,6,3};//ÿ�����ֵ�Ŀ��λ��

inline int ManhattanDis(int loc1,int loc2)
{
  return Abs(loc1/3-loc2/3) + Abs(loc1%3-loc2%3);
}

inline int h(int state[9])//�� 1-8 �ĵ��λ�þ������ǵ�Ŀ��λ�ú�Ϊ����ֵ
{  
  int ans=0;
  for(int i=0;i<9;i++)
    if(state[i])
      ans+=ManhattanDis(i,aim_loc[state[i]]);
  return ans;
}

inline bool check(int state[9])//�Ƚ��Ƿ�ɹ� 
{
  for(int i=0;i<9;i++)
    if(state[i]!=aim_state[i])
      return 0;
  return 1;
}

//�жϿո���locλ��ʱ�ܷ���dir�����ƶ���ͬʱ�����ƶ����λ��nxt
inline bool canMove(int loc, int dir, int &nxt)
{
  switch(dir)
  {
    case 0://��
        nxt=loc-3;
        return loc>2;
    case 1://��
        nxt=loc+1;
        return loc%3!=2;
    case 2://��
        nxt=loc+3;
        return loc<6;
    case 3://��
        nxt=loc-1;
        return loc%3;
  }
}

//stateΪ��ǰ����״̬��nowΪ�ո�ǰλ�ã�depΪ�������
bool dfs(int state[], int now, int dep=0)
{
  if(dep==limit)
    return check(state);
    
  if(dep+h(state)>limit) //�������
    return 0;
  int nxt;//�ո��ƶ����λ��
  for(int dir=0;dir<4;dir++)//�ո�����ĸ������ƶ�
    if(  (dep==0 || ans[dep-1]!=opcdir[dir]) //��������
          && canMove(now,dir,nxt) )
    {
      state[now]=state[nxt];
      state[nxt]=0;
            
      ans[dep]=cdir[dir];
      if(dfs(state, nxt, dep+1))
        return 1;
      //��ԭ
      state[nxt]=state[now];
      state[now]=0;
    }    
  return 0;
}
int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  int initial_state[9], x;

  for(int i=0; i<9; i++)
  {
    cin>>initial_state[i];
    if(initial_state[i]==0)
      x=i;
  }
    
  //�ж��Ƿ��н⣬ע�Ȿ���ǳ�ʼ�����������λ�������н�
  int sum=0;
  for(int i=0;i<8;i++)  
    for(int j=i+1;j<9;j++)
      if(  initial_state[i] && initial_state[j]
              && initial_state[i]>initial_state[j])
        sum++;
  if(sum&1)
  {
    limit=h(initial_state);
    while(limit<100 && !dfs(initial_state, x))
      limit++;
  }
  cout<<limit<<endl;
  return 0;
}
