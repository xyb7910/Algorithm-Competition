#include <iostream>
using namespace std;
int n,number;
int a[20]={0};

int Try(int x,int y)/*����x��y�пɷ�ڷ�����*/
{
 int j=1;
 while(j<x) /*���������ѷźõ����Ƚ�*/
 {
  if((a[j]==y)||(abs(x-j)==abs(a[j]-y)))
    return 0;
  j++;
 }
 return 1;
}

void place(int x)//�ݹ� 
{
 int y;
 if(x>n)
    number++;//print();/*�ѵ�ĩβ����,��ӡ���*/
 else
 {
    for(y=1;y<=n;y++)/*����ÿһ�е����ӹ���8��*/
    {
       if(Try(x,y))//������԰ڷ� 
       {
         a[x]=y;/*��a[x]��ֵ*/
         place(x+1);/*������һ�еĵݹ�*/
       }
    }
 }
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  cin>>n;
  place(1);
  cout<<number<<endl;
}

