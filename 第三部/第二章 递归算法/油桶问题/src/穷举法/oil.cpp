//��Ͱ���⣭��ٷ� 
#include <iostream>
#include <cstdlib>
using  namespace std;

int main()
{
  freopen("oil.in","r",stdin);
  freopen("oil.out","w",stdout);
  int N,M,j,i,oil[100],total,t,t2;
  cin>>N>>M;
  for (i=0;i<N;i++)
  {
    cin>>oil[i];
    total+=oil[i];
  }
  if (total<M)
  {
    cout<<"no\n";
    goto end;
  }
  total=1<<N;
  for (i=0;i<total;i++) //������п��� 
  {  
    t=0; t2=i;  //tΪ��ǰ��������� 
    for (j=0;j<N;j++)
    {
      if (t2&1)    //��������Ͱ�б�ѡ�� 
	    t+=oil[j];  //���������Ͱ���� 
      t2>>=1;  //�����һ����Ͱ 
    }
    if (t==M)   //������
    {
	  cout<<"yes\n";
      goto end;
    }
  }
  cout<<"no\n";
  end:
  return 0;
}
