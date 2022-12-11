//��ϣ��
#include <iostream>
using namespace std;
#define M  11
#define N  7

struct hterm
{
  int key;   /*�ؼ���ֵ*/
  int si;    /*ɢ�д���*/
};

struct hterm hashlist[M+1];
int i,address,sum,d,x[N+1];
float average;

int main()
{
  for (i=1;i<=M;i++)  //�ó�ֵ
  {
    hashlist[i].key=0;
    hashlist[i].si=0;
  }
  x[1]=22;  x[2]=41;   x[3]=53;
  x[4]=46;  x[5]=30;   x[6]=13;
  x[7]=1;  
  for (i=1;i<=N;i++)
  {
    sum=0;
    address=(3*x[i]) % M;
    d=address;
    if (hashlist[address].key==0)//��û�г�ͻ�򱣴�  
    {
      hashlist[address].key=x[i];
      hashlist[address].si=1;
    }
    else  //�����ͻ
    {
      do  
      {
		d=(d+(x[i]*7) % 10 +1) % 11;
        sum=sum+1;
      }while (hashlist[d].key!=0);
      hashlist[d].key=x[i];
      hashlist[d].si=sum+1;
    }
  }
  printf("��ϣ���ַ:   ");
  for (i=0;i<M;i++)
    printf("%-4d",i);
  printf("\n");
  printf("��ϣ��ؼ���: ");
  for (i=0;i<M;i++) 
    printf("%-4d",hashlist[i].key);
  printf("\n");
  printf("��������:     ");
  for (i=0;i<M;i++) 
    printf("%-4d",hashlist[i].si);
  printf("\n");
  average=0;
  for (i=0;i<M;i++) 
    average=average+hashlist[i].si;
  average=average/N;
  printf("ƽ����������:ASL(%d)=%g",N,average);
  system("pause");
  return 0;
}
