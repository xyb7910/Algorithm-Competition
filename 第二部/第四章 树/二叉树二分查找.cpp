//���������ֲ��ҷ�
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

b_tree create(int *node,int position)//�ݹ齨��������
{
  b_tree newnode;
  if(node[position]==0 || position>15)
    return NULL;
  else
  {
    newnode=new treenode;
    newnode->date=node[position];
    newnode->left=create(node,2*position);
    newnode->right=create(node,2*position+1);
    return newnode;
  }
}

void print(b_tree root)//�������
{
  if(root!=NULL)
  {
    print(root->left);
    printf("%d ",root->date);
    print(root->right);
  }
}

b_tree search(b_tree point,int locate)//���ֲ���
{
  while(point!=NULL)
  {
    if(point->date==locate)//���ҵ�,�򷵻ص�ַ
      return point;
    else if(point->date>locate)
      point=point->left;//����������
    else
      point=point->right;//����������
  }
  return NULL;//δ�ҵ����,�򷵻�NULL
}

int main()
{
  int locate;
  b_tree root=NULL;
  b_tree point=NULL;
  int node[16]= {0,5,2,9,1,4,7,0,0,0,3,0,6,8,0,0};
  root=create(node,1);
  print(root);
  printf("\n�����������ҵĽ��ֵ:  ");
  scanf("%d",&locate);

  point=search(root,locate);//���ö��ֲ��Һ���
  if(point!=NULL)
    printf("The value is [%d]\n",point->date);
  else
    printf("Not find!\n");
  return 0;
}

