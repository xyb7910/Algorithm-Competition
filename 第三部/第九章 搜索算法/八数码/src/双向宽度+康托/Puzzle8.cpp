//���������⣭˫�����+���� 
#include<iostream>
#include<cstdlib>
using namespace std;

int have[2][370000]={0};//�洢ĳ��״̬�Ƿ���� 
int line[2][370000]={0};//�洢˫����ѵ�״̬ 
int last[2][370000]={0};//�洢��һ��״̬�ı�� 
int len[2]={0},mid[2]={0};//�洢˫����ѵ�����״̬�����ҵ��Ĵ� 
int now[2]={0},s[9]={0},p=0;//�洢��ǰ�������ģ�������״̬��0���ڵ�λ�� 
int NUM;
void out()        //�����ǰ�İ�����״̬ 
{
  NUM++;   
  cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n";
  cout<<s[3]<<" "<<s[4]<<" "<<s[5]<<"\n";
  cout<<s[6]<<" "<<s[7]<<" "<<s[8]<<"\n";
}

int cantor()//�ÿ���չ��ʽѹ�� 
{
  int a=0,i=0,j=0,b=0;
  for(i=8;i>=1;--i)
  {
    b=s[i];
    for(j=8;j>i;--j)
      if(s[j]<s[i])
        --b;
    a+=b;
    a*=i;
  }
  return a;
}

void get(int num) //��ѹ������ת���ɰ����� 
{
  int i=0;
  for(i=8;i>=0;--i)
  {
    s[i]=num%10;
    if(s[i]==0)p=i;
      num/=10;
  }
}

int turn()//�Ѱ�����ת������ 
{
  int i=0,num=0;
  for(i=0;i<=8;++i)
  {
    num*=10;
    num+=s[i];
  }
  return num;
}

void go(int c,bool w) //��0λ�����ƶ� 
{
  int temp=0,num=0;
  temp=s[p],s[p]=s[p+c],s[p+c]=temp;
  ++len[w];
  line[w][len[w]]=turn();
  num=cantor();
  if(have[w][num]!=0)
    --len[w];
  else
  {
    last[w][len[w]]=now[w];
    if(have[!w][num]!=0)
    {
      mid[w]=len[w];
      mid[!w]=have[!w][num];
    }
    else
      have[w][num]=len[w];
  }
  temp=s[p],s[p]=s[p+c],s[p+c]=temp;
}

void out1(int num)//������ѵĸ������� 
{
  if(num!=1)
  {
    out1(last[0][num]);
    cout<<"\n";
  }
  get(line[0][num]);
  out();
}

void out2(int num)//���������ѵĸ������� 
{
  get(line[1][num]);
  if(num!=mid[1])
    out();
  if(num!=1)
  {
    cout<<"\n";
    out2(last[1][num]);
  }
}

int main()
{
  int a=0,b=0,temp=0;
  int i=0,j=0;
  for(i=1;i<=9;++i)//�����ʼ״̬ 
    cin>>s[i-1];
  a=turn();
  line[0][1]=a;
  len[0]=1;now[0]=1;have[0][cantor()]=1;
  //for(i=1;i<=9;++i)//����Ŀ��״̬ 
  //  cin>>s[i-1];
  s[0]=1;s[1]=2;s[2]=3;s[3]=8;//�̶���Ŀ��״̬ 
  s[4]=0;s[5]=4;s[6]=7;s[7]=6;s[8]=5;  
  b=turn();
  line[1][1]=b;
  len[1]=1;now[1]=1;
  if(have[0][cantor()]==0)//�鿴״̬�Ƿ��غ� 
    have[1][cantor()]=1;
  else
    mid[0]=1,mid[1]=1;
  while(mid[0]==0 && (now[0]<=len[0] || now[1]<=len[1]))//���� 
  {
    while(mid[0]==0 && len[1]>=len[0] && now[0]<=len[0])//���� 
    {
      get(line[0][now[0]]);
      if(p>=3)
        go(-3,0); //���� 
      if(mid[0]==0 && p<=5)
        go(3,0); //���� 
      if(mid[0]==0 && p>=1 && (p-1)%3!=2)
        go(-1,0);      //���� 
      if(mid[0]==0 && p<=8 && (p+1)%3!=0)
        go(1,0);       //���� 
      ++now[0];
    }
    while(mid[0]==0 && len[0]>=len[1] && now[1]<=len[1])//������� 
    {
      get(line[1][now[1]]);
      if(p<=5)
        go(3,1);  //���� 
      if(mid[0]==0 && p>=3)
        go(-3,1); //���� 
      if(mid[0]==0 && p<=8 && (p+1)%3!=0)
        go(1,1);       //���� 
      if(mid[0]==0 && p>=1 && (p-1)%3!=2)
        go(-1,1);      //���� 
      ++now[1];
    }
  }
  if(mid[0]==0)
    cout<<"-1\n";//�������ԴﵽĿ��״̬�����-1
  else
  {
    out1(mid[0]);
    out2(mid[1]);  
    cout<<NUM-1<<endl;
  }
  return 0;
}
