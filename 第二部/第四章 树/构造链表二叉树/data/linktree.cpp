//�������������
#include <bits/stdc++.h>
using namespace std;

struct tree
{
  struct tree *left;
  int date;
  struct tree *right;
};
typedef struct tree treenode;
typedef struct tree *b_tree;

b_tree insert(b_tree root,int node)
{
  b_tree newnode;
  b_tree currentnode;
  b_tree parentnode;
  newnode=new treenode;
  newnode->date=node;
  newnode->left=NULL;
  newnode->right=NULL;

  if(root==NULL)    //��һ����㽨��
    return newnode;
  else
  {
    currentnode=root;//�洢��ǰ���
    while(currentnode!=NULL)
    {
      parentnode=currentnode;//�洢�����
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
  b_tree root=NULL;
  for(int i=1; i<=len; i++)
    root=insert(root,data[i]);
  return root;
}

void print(b_tree root)//�ݹ��ӡ������
{
  if(root!=NULL)
  {
    printf("%d ",root->date);
    print(root->left);
    print(root->right);
  }
}

int main()
{
  freopen("linktree.in","r",stdin);
  freopen("linktree.out","w",stdout);
  int n;
  b_tree root=NULL;
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  root=create(node,n);
  print(root);
  cout<<endl;
  return 0;//��������Ӧ�ͷ�����ռ�
}

