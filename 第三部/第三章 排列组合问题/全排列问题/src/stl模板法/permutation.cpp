//ȫ�������⣭�ӣԣ�ģ�� 
#include<iostream> 
#include<algorithm>//������ϴ˾� 
using namespace std; 
int n,total=0;
int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 

void print()
{
  for(int i=0;i<n;i++) 
    cout<<a[i]; 
  cout<<"\n"; 
  total++;     
}

int main() 
{ 
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout);      
  cin>>n;
  print();
  while(next_permutation(a,a+n))//������һ������ 
    print();
  cout<<total<<'\n';  
  return 0; 
}
