//��ŵ��
# include <iostream>
using namespace std;
/*��n����Ƭ��one������two�����Ƶ�three��*/
void hanoi(int n,char one,char two,char three)
{     
  if(n==1)                            //����Ƭֻʣ1��ʱ 
   printf("%c->%c ",one,three);     //�ƶ���Ƭ��one��three 
  else
  {
    hanoi(n-1,one,three,two);         //�ݹ����,��Ƭ��-1,�����뻻λ�� 
    printf("%c->%c ",one,three);    //�ƶ���Ƭ��one��three 
    hanoi(n-1,two,one,three);        //�ݹ����,��Ƭ��-1,�����뻻λ��
  }
}

int main()
{
  int m;                   //��Ƭ�� 
  printf("�������Ƭ��");
  scanf("%d",&m);
  hanoi(m,'A','B','C');
}
