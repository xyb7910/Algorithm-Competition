//ѭ��������ʾ���� 
#include <iostream>
#define MAXN 5 /*���е����Ԫ�ظ���*/
using namespace std;

int queue[MAXN];
int Front=0;//ͷָ��
int Rear=0;//βָ�� 

void addqueue(int value) //����valueֵ�����
{
  if(Front==0 && (Rear+1)%MAXN==MAXN)
    cout<<"����"<<endl;//Ԫ�ش�δ��������µĶ��� 
  else if((Rear+1)%MAXN==Front)
    cout<<"����"<<endl;//����Ԫ�س��Ӻ������µĶ��� 
  else
  { 
    queue[Rear]=value;
    Rear=(Rear+1)%MAXN;
  }  
}

int delqueue()  //�����������
{
  int temp;
  if(Front==Rear)
    cout<<"����Ϊ��"<<endl;
  else
  {
     temp=queue[Front];
     queue[Front]=-1;//ȡ�����λ������Ϊ-1
     Front=(Front+1)%MAXN;//ָ����һλ��
     return temp; //���Ԫ��ֵ
  }
}

void display()//��ʾ���������е�Ԫ��
{
  for(int i = 0 ;i < MAXN; ++ i)
    cout<<queue[i]<<" ";
  cout<<endl;
}

void init()//��ʼ�����У��趨��ֵΪ-1*/
{
  for(int i = 0 ;i < MAXN; ++ i)
    queue[i] = -1;
}

int main()
{
  int select,temp;
  init();
  while(1)
  {
    cout<<"1.Input a data\n";
    cout<<"2.Output a data\n";
    cout<<"3.Display the queue\n";
    cout<<"4.Exit\n";
    cin>>select;
    switch(select)
	{
      case 1:cout<<"Please input a value";
             cin>>temp;
             addqueue(temp);
             break;
      case 2:delqueue();
             break;
      case 3:display();
             break;
      case 4:return 0;
    } 
    system("cls");
    display();        
  }
  return 0;
}            
