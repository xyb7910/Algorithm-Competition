/*
�������ƣ�����ƻ����ݹ�棩
����˵�������ǵ��͵�ŷ����·���⣬�ҵ������С�Ŀ�ʼ��
���Ϊż�㣬��1��ʼ����õ��������ĵ㣬�ͽ��õ����·���󷵻أ�
��õ��������ĵ㣬���������������һ�����ɾ����Ӧ�ıߡ�
�ݹ��������ϵͳ��ջ������Ӧ�Խ���ջ���� 
*/ 
#include <iostream>
using namespace std;
int n,i,j,s,t,m;
int net[500+1][500+1];//�洢����ͼ 
int d[500+1];//����� 
int path[1025+1];//����·�� 

void search(int s)//������� 
{
  int i;
  for(i=1;i<=m;i++)
    if (net[s][i]>0)//������������бߣ���������� 
    {
      net[s][i]--;
      net[i][s]--;
      search(i);              
    }     
  j++;//���û�б��ˣ��򽫸õ�Ž�·���� 
  path[j]=s;  
}

void init()
{
  freopen("fence.in","r",stdin);
  freopen("fence.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>s>>t;
    net[s][t]++;
    net[t][s]++;
    d[s]++;
    d[t]++;
    if(s>m)
      m=s;
    if(t>m)
      m=t;    
  }
  s=1;//�ҵ���ʼ�㣬�ȼ����1��ʼ 
  for(i=1;i<=m;i++)//�������㣬�����㿪ʼ 
  {
    if(d[i]%2!=0)
      s=i;
    break;
  }
}

int main()
{
  init();
  j=0;//·���±��ʼΪ0 
  search(s);
  
  for(i=n+1;i>=1;i--)//��ӡ 
    cout<<path[i]<<endl;
  return 0;  
}
