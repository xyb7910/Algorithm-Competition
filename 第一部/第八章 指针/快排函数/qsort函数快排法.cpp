//qsort�������ŷ� 
#include <stdio.h> 
#include <stdlib.h> 

int comp(const void *p, const void *q)//�����޸ĵĲ��� 
{ 
  return (*(int *)p - *(int *)q); //ת������ָ��Ϊint���ٱȽ�
} 

int comp2(const void *p, const void *q)//�����޸ĵĲ��� 
{ 
  return (*(int *)q - *(int *)p); //ת������ָ��Ϊint���ٱȽ�
} 

int main() 
{ 
  int i; 
  int array[]={6,8,2,9,1,0}; 
  qsort(array,6,sizeof(int),comp); //��������Ԫ������Ԫ�ش�С���ȽϺ�����
  for (i=0;i<6;i++) //��С�������� 
    printf("%d\t", array[i]); 
  printf("\n");  
  
  qsort(array,6,sizeof(int),comp2); //��������Ԫ������Ԫ�ش�С���ȽϺ�����
  for (i=0;i<6;i++) //�ɴ���С���� 
    printf("%d\t", array[i]);     
  getchar();
}
