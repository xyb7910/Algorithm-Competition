//������ĸ߾����㷨1
#include <iostream>
#include <fstream>
using namespace std;
long long save[10000][10000];

long long  combin(int m,int n)
{ 
  long long temp; 
  if(n==0||m==n ||m==0)
    return 1; 
  if (save[m][n]>0)//�Ż����������c(n,m),��ֹͣ��ȵݹ飬ֱ�����ü��� 
    return save[m][n];  
  temp=combin(m-1,n)+combin(m-1,n-1);
  save[m][n]=temp;
  return temp;
}

main()
{
  ifstream fin("combin.in");
  ofstream fout("combin.out");    
  int m,n,t;
  fin>>m>>n;
  m+=n-2;
  n-=1;
  if(m-n<n)//�����������C(m,n)=C(m,m-n),�˴��������Ż�Ч�� 
    fout<<combin(m,m-n)<<endl;  
  else  
    fout<<combin(m,n)<<endl;
  fin.close();
  fout.close();  
  return 0;  
}
