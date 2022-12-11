//����ƴд��� 
#include <iostream>
#include <string>
using namespace std;
const int maxn=1123357;//�˴�������������ѡ��������� 
int total;
string h[maxn+1];

int hash(string x)
{
  int t,l,m;  
  l=x.length();
  m=l/2;
  t=(x[0]-65)*10000+(x[m]-65)*100+(x[l-1]-65);
  return t%maxn;
}

void insert(string x)
{
  int t=hash(x);
  while(h[t]!="" && h[t]!=x)
  {
    t++;
    if(t==maxn)
      t=0;               
  }     
  h[t]=x;
}

void find(string x)
{
  int t=hash(x);
  while(h[t]!="" && h[t]!=x)
  {
    t++;
    if(t==maxn)
      t=0;               
  }     
  if(h[t]=="")
    total++;
}

int main()
{
  int i,n,m;
  string wrd; 

  cin>>n;//���ʿ�ĵ��ʸ���
  for(i=1;i<=n;i++)
  {
    cin>>wrd;
    insert(wrd);
  }
  cin>>m;//���鵥����
  for(i=1;i<=m;i++)
  {
    cin>>wrd;
    find(wrd);                 
  } 
  cout<<total;
  system("pause");
  return 0;  
}
