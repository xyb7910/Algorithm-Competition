//һ���򵥵Ķ��������������,������ģ��������Ľṹ,ʹ��ջ�Ż�
#include<iostream>
#define MAX_TREE_NODE 1000000 /*�������ڵ���*/
using namespace std;

/*dataΪ����lc,rcΪ�ڵ�����Һ���*/
int data[MAX_TREE_NODE],p[MAX_TREE_NODE],lc[MAX_TREE_NODE],rc[MAX_TREE_NODE];
int root = -1;

/*�����ṩ�����λ��ջ*/
int stack[MAX_TREE_NODE];
int top = 0;

/*��������ֵΪk�Ľڵ㣬���������������е�λ�ã�����������򷵻�-1*/
int tree_search(int x,int k)
{
  /*����ʹ�ýϿ�ĵ�����ʽ*/
  while(x != -1 and data[x] != k)
    {
      if(k < data[x])
	x = lc[x];
      else
	x = rc[x];
    }
  return x;
}

/*�����в���һ���ڵ�z������ڵ���pre_insert()�������Ѿ���ֵ*/
void tree_insert(int z)
{
  /*insert node*/
  int x = root, y = -1;
  while(x != -1)
    {
      y = x;
      if(data[z] < data[x])
	x = lc[x];
      else
	x = rc[x];
    }  

  p[z] = y;

  if(y == -1)
    root = z;
  else if (data[z] < data[y])
    lc[y] = z;
  else
    rc[y] = z;

  return ;
}

/*���������ҵ�һ����λ���Ҹ�����ڵ㸳ֵ��������뵽����*/
void pre_insert(int ins_data)
{
  int z;
  z = stack[top++];
  data[z] = ins_data;
  tree_insert(z);
  return ;
}

/*�����ϵ���Сֵ*/
int tree_minimum(int x)
{
  while(lc[x] != -1 )
    x = lc[x];
  return x;
}

/*��ĳ�ڵ�ĺ��*/
int tree_successor(int x)
{
  /*���ýڵ��������������Ѱ��������������ڵ�*/
  if(rc[x] != -1)
    return tree_minimum(rc[x]);
  /*�����������������ȣ�����ֱ������ĳ���ڵ����丸�ڵ�����ӽڵ�Ϊֹ*/
  int y = p[x];
  while(y != -1 and x == rc[y])
    {
      x = y;
      y = p[y];
    }
  return y;
}

/*ɾ������zλ���ϵĽڵ㣬����ڵ���pre_delete()�������Ѿ�ȷ����*/
void tree_delete(int z)
{
  int x,y;
  /*�������ڵ�������һ�����ӣ���ɾ���ýڵ�*/
  if(lc[z] == -1 or rc[z] == -1)
    y = z;
  else/*������Ѱ������*/
    y = tree_successor(z);
  /*��xָ��y�����ӻ��Һ���(����еĻ�)*/
  if(lc[y] != -1)
    x = lc[y];
  else
    x = rc[y];

  /*���y�к��ӣ���ô�������沽����ָ�����ĺ��ӵĸ��ڵ�ָ��y�ĸ��ڵ�*/
  if(x != -1)
    p[x] = p[y];
  
  if(p[y] == -1)/*ɾ���Ľڵ�Ϊ���ڵ�*/
    root = x;
  else if(y == lc[p[y]])/*ɾ���Ľڵ�yΪy������*/
    lc[p[y]] = x;
  else/*ɾ���Ľڵ�yΪy���Һ���*/
    rc[p[y]] = x;

  if(y != z)/*��y��ֵ����z*/
    data[z] = data[y];
  
  /*delete node y*/
  data[y] = -1;
  lc[y] = -1;
  rc[y] = -1;
  p[y] = -1;
  stack[--top] = y;
  return ;
}

/*ɾ��֮ǰ�Ĳ������������ҵ�ɾ���ڵ����ڵ�λ��*/
void pre_delete(int data)
{
  int k;
  k = tree_search(root,data);
  if(k != -1)
    tree_delete(k);
  return ;
}

/*��ʼ�����нڵ㣬Ĭ�Ͽ�ֵΪ-1*/
void init()
{
  int i;
  for(i = 0 ;i < MAX_TREE_NODE; ++ i)
    {
      data[i] = rc[i] = lc[i] = p[i] = -1;
      stack[i] = i;
    }
  return ;
}

/*�������������ʽ��ʾ�����������еĽڵ㼰ÿ���ڵ����Ϣ*/
void display(int x)
{
  if(x == -1) return ;
  if(lc[x] != -1)
    display(lc[x]);
  cout<<x<<" value : "<<data[x]<<" left: "<<lc[x]<<" right: "<<rc[x]<<" parent : "<<p[x]<<"\n";
  if(rc[x] != -1)
    display(rc[x]);
  return ;
}

/*��ʾ����*/
int main()
{
  int ins,tmp;

  cout<<"please insert a instruction:\n";
  cout<<"1.insert a value\n";
  cout<<"2.delete a value\n";
  cout<<"3.display the tree in middle order\n";

  init();

  while(cin>>ins)
    {
      //cout<<"top : "<<top<<" val : "<<stack[top]<<"\n";
      switch(ins)
	{
	case 1:/*����1������һ��ֵ*/
	  cin>>tmp;
	  cout<<"please input insert data \n";
	  pre_insert(tmp);
	  display(root);
	  break;

	case 2:/*����2��ɾ��һ��ֵ�������ɾ��ֵ*/
	  cin>>tmp;
	  cout<<"please input the data need to delete\n";
	  pre_delete(tmp);
	  display(root);
	  break;

	case 3:/*��ʾ�������е����нڵ�*/
	  display(root);
	  break;

	default :
	  return 0;
	}
    }
  return 0;
}
