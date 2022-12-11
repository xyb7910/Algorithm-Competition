//������ģ��ջ 
#include<iostream>
#define MAXN 1000//ջ�����ɵ����Ԫ�ظ���
using namespace std;

int stack[MAXN];
int top = -1;//��ʼ��ջ��ָ��Ϊ-1 

int pop()//ջ��Ԫ�س�ջ����ȡ��ջ��Ԫ��ֵ 
{
  int temp;
  if(top<0)
  {
    cout<<"\nThe stack is empty!\n";
    return -1;
  }
  temp=stack[top--];
  return temp;
}

void push(int value)
{ 
  if(top>=MAXN)
    cout<<"\nThe stack is full!\n";
  else
    stack[++top]=value;
}

void display()//��ʾջ��Ԫ��
{
  for(int tmp = top ; tmp >= 0 ; -- tmp)
    cout<<stack[tmp]<<" ";
  cout<<"\n";
}

int main()
{
  int ins;
  while(1)
  {
    cout<<"Please enter a value,(0=exit,-1=pop)\n";
    cin>>ins;
    if(ins==0)
      exit(0);
    else if(ins!=-1)
      push(ins);
    else if(ins==-1)
      pop();
    system("cls");
    display();
  }  
  return 0;
}
