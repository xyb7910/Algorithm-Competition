//�ڰ�Ϳɫ������DFS
#include <bits/stdc++.h>
using namespace std;

int Map[110][110];
int color[110],tmp[110];//tmp[]��ʱ�洢����Ž��
int len,maxlen;
int index,n,k;

void DFS(int num)
{
  int i;
  if(num==n)  //num==n,��Ѱ���
  {
    if(len>maxlen)//�������Ž�
    {
      maxlen=len;
      for(i=1,index=0; i<=n; i++)
        if(color[i])
          tmp[index++]=i;
    }
    return;
  }
  for(i=1; i<=n; i++)
    if(i!=num && Map[i][num] && color[i])//��Ѱ��Χ�ĵ��Ƿ��б���ɫ
      break;
  if(i>n) //i>n��ʾû�б���ɫ
  {
    color[num]=1;  //��Χ��û�б���ɫ���������Ϳ�����ɫ��
    len++;         //���ȼ�1
    DFS(num+1);    //��Ѱ��һ����
    color[num]=0;  //�ָ�����ǰ״̬
    len--;         //�ָ�����ǰ״̬
  }
  DFS(num+1);  //��Ѱ��һ����
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    memset(Map,0,sizeof(Map));
    memset(color,0,sizeof(color));
    len=maxlen=0;
    scanf("%d%d",&n,&k);
    while(k--)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      Map[x][y]=Map[y][x]=1;
    }
    DFS(1);
    printf("%d\n%d",maxlen,tmp[0]);
    for(int i=1; i<maxlen; i++)
      printf(" %d",tmp[i]);
    printf("\n");
  }
  return 0;
}
