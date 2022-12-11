//���������� 
#include <fstream>
#include <string>
using namespace std;
int n;

struct TFriend
{
  string name[2];
  int pop;//���г̶� 
  int idx;//ԭʼ������±�       
}fr[50000+10];

int cmp_name(const void *a,const void *b)//������Ϊ�ؼ������� 
{
   TFriend *fr1=(TFriend *)a;//ǿ��ת������ 
   TFriend *fr2=(TFriend *)b;
   if(fr1->name[0]<fr2->name[0])
     return -1;
   if(fr1->name[0]>fr2->name[0])
     return 1;
   return 0;     
}

int cmp_pop(const void *a,const void *b)//popΪ��һ�ؼ��֣�idxΪ�ڶ��ؼ��� 
{
   TFriend *fr1=(TFriend *)a;
   TFriend *fr2=(TFriend *)b;
   if(fr1->pop>fr2->pop)//�Ƚϵ�һ���ؼ��� 
     return -1;
   if(fr1->pop<fr2->pop)
     return 1;
   if(fr1->idx<fr2->idx)//���һ�ؼ�����ͬ���Ƚϵڶ����ؼ��� 
     return -1;
   if(fr1->idx>fr2->idx)
     return 1;
   return 0;              
}   

int main()
{
   ifstream fin("friends.in");
   ofstream fout("friends.out");
   int n=0;
   while(fin>>fr[n].name[0]>>fr[n].name[1])//�ɹ���ȡ����ʱ��ѭ�� 
   {
     fr[n].idx=n;
     n++;                                        
   }
   qsort(fr,n,sizeof(fr[0]),cmp_name);
   int st=0;//st��¼��ǰ����������㣬0��Ȼ�ǵ�һ������������� 
   for(int i=1;i<=n;i++)
   { //ɨ�������������ǰһ��Ԫ�ز�ͬ�������������� 
     if(i==n ||fr[i].name[0]!=fr[i-1].name[0])
     {
       for(int j=st;j<i;j++)
         fr[j].pop=i-st;
       st=i;//��һ����������i��ʼ          
     }        
   }
   qsort(fr,n,sizeof(fr[0]),cmp_pop);
   for(int i=0;i<n;i++)
     fout<<fr[i].name[0]<<" "<<fr[i].name[1]<<endl;
   return 0;     
}
