//�ڽ������ʾ��
#include <bits/stdc++.h>
using namespace std;
#define Max 6
int graph[Max][Max];

void PrintGraph()
{
  for(int i=0; i<Max; i++)
  {
    for(int j=0; j<Max; j++)
      printf("%d  ",graph[i][j]);
    printf("\n");
  }
}

int main()
{
  int node1,node2;
  while(1)
  {
    scanf("%d %d",&node1,&node2);
    if(node1==-1 || node2==-1)                      //�˳�����
      break;
    if(node1==node2)
      printf("����,����ѭ��!\n");
    else if(node1>=Max || node2>=Max ||node1<0 || node2<0)
      printf("����,������Χ!");
    else
    {
      graph[node1][node2]=1;
      graph[node2][node1]=1;
    }
  }
  PrintGraph();                                     //����ڽ�����
  return 0;
}

