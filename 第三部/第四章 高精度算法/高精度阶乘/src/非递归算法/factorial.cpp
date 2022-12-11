//��N�Ľ׳˵ĵݹ�ת�ǵݹ��㷨��ʹ������ģ��ϵͳ��ջ
#include <iostream>
using namespace std;
#define Num 50  //�β��ɳ���20 
#define MaxSize Num
unsigned long long int stack[Num+1],top;//top������ָ��

unsigned long long int push(int value)//��ջ���� 
{ 
  if(top<MaxSize)//��ջδ��ʱ 
  { 
    top++; //ѹ��һ��Ԫ�أ���ջ��ָʾ����һ 
    stack[top]=value;//���ջ��Ԫ�� 
  }
}

unsigned long long int pop()//��ջ���� 
{ 
  unsigned long long int temp;//ʹ����ʱ�����ݴ�ջ��Ԫ�� 
  if(top>=1)//���ջδ�� 
  {
    temp=stack[top];
    stack[top]=0;//����һ��Ԫ�أ�����ֵΪ�� 
    top--;//����һ��Ԫ�أ���ջ��ָʾ����һ
  }
  return temp;//���س�ջ��Ԫ��ֵ 
}

unsigned long long int Factorial(int n)
{
   unsigned long long int t;//��ʱ����
   while(n>=1)//����ѹ��ջ 
   {
     push(n);
     n--;
   }
   t=1;
   while(top>=1)//���ε���ջ����t 
     t=t*pop();
   return t;
} 

int main()
{
  FILE *in=fopen("factorial.in","r");
  FILE *out=fopen("factorial.out","w");
  int N;
  fscanf(in,"%d",&N);  
  top=0;//��ʼʱ��ջ��ָʾ��topΪ�� 
  fprintf(out,"%d!=%I64u",N,Factorial(N)); 
  fprintf(out,"\n");
  fclose(in);
  fclose(out);
  return 0;  
}
