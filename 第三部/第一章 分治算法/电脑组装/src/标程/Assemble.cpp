//������װ 
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct compute
{
  int type,price,quality;
}d[1005];

int init[1005],n,w,Count;
map<string,int> MAP;//��stringӳ��Ϊ���� 

int cmp(compute a,compute b)
{
  return a.quality<b.quality;
}

int weight(int middle)
{
  int i,j,s;
  memset(init,-1,sizeof(init));
  for(i=middle;i<n;i++)
  {
    if(init[d[i].type]==-1)//��������ͻ�û��ͳ�� 
      init[d[i].type]=d[i].price;//����Ӹ����͵�һ������ļ�ֵ 
    else if(init[d[i].type]>d[i].price) 
      init[d[i].type]=d[i].price;//ѡȡ����ѡ����quality������˵Ĳ���
  }
  for(s=i=0;i<Count;i++)//���Ƿ��������Ͷ�ѡ�� 
	if(init[i]==-1)//����ûѡ�ģ���ʧ�� 
      return 0;
	else 
      s+=init[i];//�����ۼ� 
  if(s>w) //������Ԥ�㣬ʧ�� 
    return 0;
  else //����ɹ� 
    return 1;	
}

int binary()//���� 
{
  int left=0,right=n-1,middle;
  while(left<right)
  {
    middle=(left+right+1)/2;//Ҫ��1����������8,9�ͳ���ѭ��
    if(weight(middle))  
      left=middle;
    else 
      right=middle-1;
  }
  return d[left].quality;
}

int main()
{
  freopen("Assemble.in","r",stdin);
  freopen("Assemble.out","w",stdout);  
  int t,i,j;
  string s; char a[25];
  cin>>t;
  while(t--)
  {   
    Count=0;
    scanf("%d%d",&n,&w);//�������Ԥ�� 
    for(i=0;i<n;i++)
    {	
      scanf("%s",a);//���� 
      s=a;
      scanf("%s%d%d",a,&d[i].price,&d[i].quality); 
      if(MAP.find(s)==MAP.end())//��������ͻ�û�� 
        MAP[s]=Count++;//�����ӳ��Ϊĳ������ 
      d[i].type=MAP[s];//��ǹ��� 
    }
	MAP.clear();//ӳ��������� 
	sort(d,d+n,cmp);//���������� 
	printf("%d\n",binary());	
  } 
  return 0;
}
