//���������� 
#include <iostream>
using namespace std;

#define MAXN 1000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1

typedef struct //����ṹ��
{
  int bit[100];//������������� 
  int start;//����Ŀ�ʼλ�� 
}HCode; 
       
typedef struct//���ṹ��
{
  int weight;
  int parent;
  int lchild;
  int rchild;
}HNode;        

HNode HuffNode[MAXNODE];//����һ�����ṹ������
HCode HuffCode[MAXLEAF];//����һ������ṹ������

void CreatHuffmanTree(HNode HNode[MAXNODE],int n)//����һ�Ź�������
{ 
  int i, j;
  int m1, m2;//������������������СȨֵ����Ȩֵ
  int x1, x2;//������������������СȨֵ����������е����
  
  for (i=0; i<n-1; i++)//ѭ������ Huffmantree
  {
    m1=m2=10000;//m1��m2�д�������޸�����ҽ��Ȩֵ��С���������
    x1=x2=0;
        
    for (j=0; j<n+i; j++)//�ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ�����
    {
      if (HNode[j].weight < m1 && HNode[j].parent==-1)
      {
        m2=m1; 
        x2=x1; 
        m1=HNode[j].weight;
        x1=j;
      }
      else if (HNode[j].weight < m2 && HNode[j].parent==-1)
      {
        m2=HNode[j].weight;
        x2=j;
      }
    }
    //�����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ
    HNode[x1].parent  = n+i;
    HNode[x2].parent  = n+i;
    HNode[n+i].weight = HNode[x1].weight + HNode[x2].weight;
    HNode[n+i].lchild = x1;
    HNode[n+i].rchild = x2;
  }
}

void CreatHuffmanCode(HNode HuffNode[MAXNODE],int n)
{
  HCode cd;//����һ����ʱ���������������ʱ����Ϣ   
  for (int i=0; i < n; i++)
  {
    cd.start = n-1;
    int c = i;
    int p = HuffNode[c].parent;
    while (p != -1)   /* �������� */
    {
      if (HuffNode[p].lchild == c)
        cd.bit[cd.start] = 0;
      else
        cd.bit[cd.start] = 1;
      cd.start--;        /* �����ĵ�һλ */
      c=p;                    
      p=HuffNode[c].parent;    /* ������һѭ������ */
    } 
    for (int j=cd.start+1; j<n; j++)//���������ÿ��Ҷ���Ĺ���������ͱ������ʼλ
    { 
      HuffCode[i].bit[j] = cd.bit[j];
    }
    HuffCode[i].start = cd.start;
 }                  
} 

void init(HNode HNode[],int n)//��ʼ��
{
  for (int i=0; i<2*n-1; i++) 
  {
    HNode[i].weight = 0;
    HNode[i].parent =-1;
    HNode[i].lchild =-1;
    HNode[i].lchild =-1;
  }
  for (int i=0; i<n; i++)
  {
    cout<<"�������"<<i<<"������Ȩ��";  
    cin>>HNode[i].weight;
  }    
}

int main()
{
  int i, j,n;
  cout<<"�������ַ�����n:\n";
  cin>>n;
  init(HuffNode,n);//��ʼ�� 
  CreatHuffmanTree(HuffNode, n);//������������ 
  CreatHuffmanCode(HuffNode, n);//���ɹ���������  
  
  for (i=0; i<n; i++)//�������������
  {
    cout<<i<<"�Ĺ���������Ϊ:";
    for (j=HuffCode[i].start+1; j < n; j++)
      cout<<HuffCode[i].bit[j];
    cout<<"\n";
  }
  getchar();
  getchar();
  return 0;
}
