#include <iostream>
using namespace std;
int n,num;
int a[20]={0};
bool lie[31],x1[31],x2[31];

void place(int x)//�ݹ麯��
{
 int y;
 if(x>n)
    num++;/*�ѵ�ĩβ����,���ô�ӡ����ĺ���*/
 else
 {
    for(y=1;y<=n;y++)/*����ÿһ�е����ӹ���8��*/
    {
       if(lie[y]==0 && x1[x+y]==0 && x2[x-y+n]==0)//������԰ڷ� 
       {
         a[x]=y;/*��a[x]��ֵ*/
         lie[y]=1;
         x1[x+y]=1;
         x2[x-y+n]=1;//ʹ����+n����ת�� 
         place(x+1);/*������һ�еĵݹ�*/
         lie[y]=0;//�ָ� 
         x1[x+y]=0;
         x2[x-y+n]=0;
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
   cout<<num<<endl;
  // system("pause");
}

