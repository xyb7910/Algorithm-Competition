//�򵥱������⣲�����棳 
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("pack2.in");
ofstream fout("pack2.out");

bool f[20001];

int main()
{
  int v,n,a[31],i,j,d;
  fin>>v>>n;
 
  for(i=1;i<=n;i++)
   fin>>a[i];
  
  for(i=1;i<=n;i++)//��n����Ʒ
  {
    for(j=v;j>0;j--)//jΪʣ��ռ�
      if(f[j]==1 && j+a[i]<=v) 
        f[j+a[i]]=1;
    f[a[i]]=1;
  }
  d=v;
  while(d>0 && f[d]!=1)//�ҳ����װ�ؿռ� 
    d--;
 
  fout<<v-d<<endl;
  fin.close();
  fout.close();
  return 0;
}
