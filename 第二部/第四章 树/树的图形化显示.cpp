//����ͼ�λ���ʾ
#include <iostream>
#include <windows.h>
using namespace std;

struct tree
{
  struct tree *left;
  int date;
  struct tree *right;       
};
typedef struct tree treenode;
typedef struct tree *b_tree;

b_tree insert(b_tree root,int node)//����ڵ�
{
  b_tree newnode;
  b_tree currentnode;
  b_tree parentnode;
  
  newnode=(b_tree)malloc(sizeof(treenode));
  newnode->date=node;
  newnode->left=NULL;
  newnode->right=NULL;
  
  if(root==NULL)    //��һ���ڵ㽨�� 
    return newnode;
  else
  {
    currentnode=root;//�洢��ǰ�ڵ� 
    while(currentnode!=NULL)
    {
      parentnode=currentnode;//�洢���ڵ� 
      if(currentnode->date>node)                      
        currentnode=currentnode->left;//������ 
      else
        currentnode=currentnode->right; //������   
    } 
    if(parentnode->date>node)
      parentnode->left=newnode;
    else
      parentnode->right=newnode;  
  }              
  return root;
}

b_tree create(int *data,int len)//���������� 
{
  int i;
  b_tree root=NULL;
  for(i=1;i<=len;i++)
    root=insert(root,data[i]);
  return root;  
}

void GraphiShow(b_tree root,int x,int y,int k,int space)
{
  if(root!=NULL)
  {
    //�˶δ������ڶ�λ��꣬����д�ɺ������õ���ʽ 
    HANDLE hOutput;
    COORD location;
    location.X=x;
    location.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);//�����Ļ��� 
    SetConsoleCursorPosition(hOutput,location);//��λ��굽���꣨x,y���� 
 
    if(k==1)
      cout<<root->date<<"/";//�����ʾ������   
    else if(k==2)      
      cout<<"\\"<<root->date;//�����ʾ������                
    else 
      cout<<root->date;//�������� 
    GraphiShow (root->left,x-space,y+1,1,space/2);
    GraphiShow (root->right,x+space,y+1,2,space/2);              
  }
}


int main()
{
  int n,i;
  b_tree root=NULL;  
  cin>>n;
  int node[n+1];
  for(i=1;i<=n;i++)
    cin>>node[i];
  root=create(node,n);
  GraphiShow (root,40,3,0,20);
  cout<<endl;
  system("pause");
  return 0;
}
