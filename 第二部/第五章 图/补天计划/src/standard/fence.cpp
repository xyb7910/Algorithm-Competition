/*
DFS+��֦ 
һ��ȷ����� 
��2������
1��ͼ�����ҽ���2�������㣨��֮������·������Ϊ�����Ľڵ㣩 
���ҳ����������㣬�Ա�Ž�С�ĵ���Ϊ��㣬��һ��Ϊ�յ㡣
2��ͼ��û��������
�Ա����С�ĵ���Ϊ�����յ㡣 
����̰��DFS+��֦
0�����ߵı������������ȫ������������������У�Ȼ��exit(0)�� 
1��floodfillһ�Σ��жϴӵ�ǰ���ܷ����ʣ������бߣ������ܣ��򷵻أ����ܣ�������� 
2����С�������ö�ٵ�ǰ���ܵ���ĵ㣬������õ�ıߢ�ɾ�������Ըõ�ִ��DFS��
3����DFS���̷��أ���ָ��ߢ٣�����ö����һ���㡣
*/
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
 
using namespace std;
 
ifstream fin ("fence.in");
ofstream fout ("fence.out");
 
const long MAXN=510,MAXF=1550;
 
long mapS[MAXN][MAXN];
long nodeCounter[MAXN];
long n;
long path[MAXF],upPath;
 
void init()
{
     fin >>n;
     memset(mapS,0,sizeof(mapS));
     memset(nodeCounter,0,sizeof(nodeCounter));
     long a,b;
     for (long i=0;i<n;++i)
     {
         fin >>a >>b;
         ++mapS[a][b];
         ++mapS[b][a];
         ++nodeCounter[a];
         ++nodeCounter[b];
     }
     upPath=-1;
     return;
}
 
long getStart()     //��ȡ��� 
{
     long oddCounter=0,minOdd=MAXN;
     for (long i=1;i<MAXN;++i)
         if (nodeCounter[i]&1)
         {
            ++oddCounter;
            if (minOdd==MAXN) minOdd=i;
         }
     if (oddCounter==2)
        return minOdd;
     else if (oddCounter==0)
          return 1;
     else
     {
         fout <<"getStart Error:oddCounter=" <<oddCounter <<endl;
         return -1;
     }
}
 
bool floodfill(long node)
{
     long stack[MAXN],top=-1;
     bool vis[MAXN];
     memset(vis,0,sizeof(vis));
     stack[++top]=node;
     vis[node]=true;
     while (top>-1)
     {
           node=stack[top--];
           for (long i=1;i<MAXN;++i)
           {
               if (mapS[node][i] && !vis[i])
               {
                  stack[++top]=i;
                  vis[i]=true;
               }
           }
     }
     for (long i=1;i<MAXN;++i)
         if (!vis[i] && nodeCounter[i])
         {
            return false;
         }
     return true;
} 
 
 
void DFS(long node)
{
     if (upPath==n)                    //���·�����ȵ���F+1�����·�� ��exit(0) 
     {
        for (long i=0;i<=upPath;++i)
            fout <<path[i] <<endl;
        exit(0);
     }
 
     if (!floodfill(node))     //���޷�����ʣ��ȫͼ�򷵻� 
     {
        return;
     }
 
     for (long i=1;i<MAXN;++i)    //ö�ٵ�
     {
         if (mapS[node][i]) 
         {
            //ɾ��
            --mapS[node][i];
            --mapS[i][node];
            --nodeCounter[i];
            --nodeCounter[node];
 
            path[++upPath]=i;         
            DFS(i);
            --upPath;
            //�ָ��� 
            ++mapS[node][i];
            ++mapS[i][node];
            ++nodeCounter[i];
            ++nodeCounter[node];
         }
     }
     return;
}
 
int main()
{
    init();
    path[++upPath]=getStart();
    DFS(path[upPath]);
    return 0;
}
