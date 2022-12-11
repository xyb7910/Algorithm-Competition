//���������㷨2 
#include<iostream>
using namespace std;
const int MAX = 100;
int List[MAX],color[MAX],k;
struct
{
  int n;
  int adjvex[MAX];
}Edge[MAX];

void DFS(int cur)
{
  int i,next;
  color[cur] = -1;
  for(i=0;i<Edge[cur].n;i++)//�������е����ӱ� 
  {
     next = Edge[cur].adjvex[i];//�ҵ���һ�����ӱ� 
     if(color[next]==0) 
       DFS(next);
     else if(color[next]==-1)//�лر߳�����ζ���л�·
     {
       cout<<"Circuit exists!"<<endl;
       system("pause");
       exit(0);
     }
  }  
  color[cur] = 1;
  List[--k] = cur;//���ڵ���ɵ�˳�����У����򱣴� 
}

int main()
{
    int n,e,a,b;
    int i,j; 
    cin>>n>>e;//���붥����n�ͱ���e 
    for(i=1;i<=n;i++)
        Edge[i].n = 0;
    for(i=0;i<e;i++)//����� 
    {
      cin>>a>>b;
      Edge[a].adjvex[ Edge[a].n++ ] = b;
    }
    k=n;
    DFS(1);
    for(i=0;i<n;i++)
        cout<<List[i]<<" ";
    system("pause");
    return 0;
}
