//���ر����������㷨 
#include <iostream>
#include <cstdlib> 
using namespace std;   

int maxV[201]; 
int weight[50]; //��¼��ֺ��������� 
int value[50];  //��¼��ֺ������ֵ 
int V, N;   

int main() 
{ 
  freopen("Mbag.in","r",stdin);
  freopen("Mbag.out","w",stdout);      
  int i, j;     
  cin>>V>>N;     
  int weig, val, num;     
  int count = 0;       
  for(i=0; i<N;++i)     
  { 
    cin>>weig>>val>>num;   //�������Ʒ����������ֵ������           
    for(j=1;j<=num; j<<=1) //j����һλ�����ж����Ʋ��         
    {           
      weight[count] = j*weig;// ������Ӧ�Ķ�����ϵ��          
      value[count++] = j * val;             
      num -= j;         
    }         
    if(num > 0)//ʣ��δ��ֵ�         
    {             
      weight[count] = num * weig;             
      value[count++] = num * val;         
    }     
  }     
    
  for(i = 0; i < count; ++i)  // ʹ��01����     
    for(j = V; j >= weight[i]; --j)         
    {             
      int tmp = maxV[j-weight[i]] + value[i];             
      maxV[j] = maxV[j] > tmp ? maxV[j] : tmp;         
    }     
  printf("%d",maxV[V]); 
  return 0;
}
