//�����������ʾ����(ջ�Ż�)
#include<iostream>
#define MAXN 100001
using namespace std;

int linklst_data[MAXN] ;
int linklst_point[MAXN] ;
int stack[MAXN];//���ڼ�¼û�м�������������±��ջ
int head = -1;//�����ͷָ��
int stack_head = 0;//ջ��ָ�� 

void del_by_data(int del_data)//ɾ��һ������del_data��Ԫ��
{
  int p=head,pre=-1;  //��ͷ��ʼ��������
  while(p != -1)
  {
    if(linklst_data[p] == del_data)//�ҵ�Ҫɾ����ֵ������ɾ������
	{
	  
	  if(p == head)//���ɾ������ͷָ�룬�����ͷָ��
	    head = linklst_point[head];
	  else//���else ��ͬ�� if (pre != 1)��Ϊ��p!=headʱpǰ���Ѿ���Ԫ����
	    linklst_point[pre] = linklst_point[p];
	  
	  linklst_data[p] = -1;//ɾ��pָ���Ԫ�ص�ֵ
	  linklst_point[p] = -1;
	  stack[--stack_head] = p;//��ɾ��Ԫ�ص������±���ջ
	  return ;
	}
      pre = p;
      p = linklst_point[p];
  }
  return ;
}

void add_front(int add_data)//������ǰ�μ���Ԫ��*/
{
  int p = 1;
  p = stack[stack_head++];//ֱ��ȡ��ջ�еĿ�λ*/
  linklst_data[p] = add_data;//��Ҫ����Ľڵ�ѡ�õĿ�λ��ֵ*/
  linklst_point[p] = head; //����ǰ����Ԫ�ص�ָ��ָ��head*/
  head = p;  //ʹ��ǰ��Ԫ�س�Ϊ����ͷָ��*/
}

void add_rear(int add_data)//������ĩβ����Ԫ��*/
{
  int p = 1,pre;
  p = stack[stack_head++];//ֱ��ȡ��ջ�еĿ�λ*/
  linklst_data[p] = add_data;  //��Ҫ����Ľڵ�Ŀ�λ���и�ֵ*/
  if( head != -1 ) //����Ϊ��
  {
    pre = head;//�ҵ������е����һ��Ԫ��*/
    while(linklst_point[pre] != -1)
  	  pre = linklst_point[pre];
    linklst_point[pre] = p;//����ǰ���������һ��Ԫ�ص�ָ��ָ��Ҫ�����Ԫ��
  }
  else//����ֱ�Ӷ�head��ָ��Ԫ�ظ�ֵ
    head = p;
}

void output()
{
  int p=head;
  while(p != -1)
  {
    cout<<linklst_data[p]<<" ";
    p = linklst_point[p];
  }
  cout<<"\n";
  return ;
}


void init()//��ʼ������ָ��ֵ
{
  for(int i = 0;i < MAXN;i++)
  {
    linklst_point[i] = -1;
    linklst_data[i] = -1;
    stack[i] = i + 1;//��1��MAXN��ջ���������±�
  }
  return ;
}

int main()//��ʾ����Ĳ���
{
  int ins,data;
  init();
  while(1)
  { 
    cout<<"1.insert a value in front \n";
    cout<<"2.insert a value in rear \n";
    cout<<"3.delete a value \n";
    cout<<"4.quit \n";
    cin>>ins;
    switch(ins)
	{
  	  case 1:
	    cout<<"please insert a value :";
	    cin>>data;
	    add_front(data);
	    break;
  	  case 2:
	    cout<<"please insert a value :";
	    cin>>data;
	    add_rear(data);
	    break;
	  case 3:
	    cout<<"please insert a value :";
	    cin>>data;
	    del_by_data(data);
	    break;
	  default:
	    return 0;
	}
    system("cls");//������ֻ����windowƽ̨��ʹ�� 
	output();
 }
 return 0;
}
