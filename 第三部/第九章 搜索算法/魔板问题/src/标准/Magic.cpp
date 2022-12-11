//ħ�����⡡������ 
#include<iostream>
#include<fstream>
using namespace std;
bool have[45000]={0};   //�洢ĳ״̬�Ƿ���� 
char did[45000]={0};    //�洢ĳһ���Ĳ���
int bfs[45000]={0},last[45000]={0},cost[45000]={0};
//�ֱ�洢��ǰ״̬����һ��״̬����ţ��ܹ������˶��ٴβ��� 
int s[8]={1,2,3,4,8,7,6,5},ans=0,enter=0,now=0,len=0,f=0,temp=0;
/* s�����ʾħ���״̬��ans��ʾĿ��״̬��enter��Ϊ�˱�֤���ÿ60��һ�У�now��Ŀǰ����������ţ�
len��Ŀǰ�ܹ�״̬��f��ʾ�𰸵���� */ 

int cantor()//�ÿ���չ��ʽѹ��״̬
{
  int a=0,i=0,j=0,b=0;
  for(i=7;i>=1;--i)
  {
    b=s[i]-1;
    for(j=7;j>i;--j)
      if(s[j]<s[i])
        --b;
    a+=b;
    a*=i;
  }
  return a;
}

int change()//��״̬ѹ����8λ������ 
{
  int a=0,i=0;
  for(i=0;i<=7;++i)
    a=a*10+s[i];
  return a;
}

void turn(int num)//�����ֽ�ѹ 
{
  int i=0;
  for(i=7;i>=0;--i)
  {
    s[i]=num%10;
    num/=10;
  }
  return;
}

void go(char tmp)
{
  ++len;
  bfs[len]=change();
  temp=cantor();
  if(have[temp])
    --len;
  else
  {
    have[temp]=1;
    cost[len]=cost[now]+1;
    last[len]=now;
    did[len]=tmp;
    if(bfs[len]==ans)
    f=len;
  }
} 

void go1()//����A 
{
  int i=0;
  for(i=0;i<4;++i)//���в��� 
  {
    temp=s[i],s[i]=s[i+4],s[i+4]=temp;
  }
  go('A'); //������� 
  for(i=0;i<4;++i)         //��ԭ 
  {
    temp=s[i],s[i]=s[i+4],s[i+4]=temp;
  }
}

void go2()   //����B 
{
  temp=s[3],s[3]=s[2],s[2]=s[1],s[1]=s[0],s[0]=temp;//���в��� 
  temp=s[7],s[7]=s[6],s[6]=s[5],s[5]=s[4],s[4]=temp;//������� 
  go('B');
  temp=s[0],s[0]=s[1],s[1]=s[2],s[2]=s[3],s[3]=temp;//��ԭ 
  temp=s[4],s[4]=s[5],s[5]=s[6],s[6]=s[7],s[7]=temp;
}

void go3()  //����c 
{
  temp=s[1],s[1]=s[5],s[5]=s[6],s[6]=s[2],s[2]=temp;//���в���
  go('C');                                          //������� 
  temp=s[2],s[2]=s[6],s[6]=s[5],s[5]=s[1],s[1]=temp;//��ԭ 
}

void out(int num)   //��� 
{
  if(num!=1)
  {
    out(last[num]);
    cout<<did[num];
    ++enter;
    if(enter%60==0)
      cout<<"\n";    //��֤ÿ�����60���ַ� 
  }
}

int main()
{
  freopen("Magic.in","r",stdin);
  freopen("Magic.out","w",stdout);  
  int i=0,j=0;
  have[cantor()]=1;  //ȷ����ʼ״̬ 
  bfs[1]=12348765;
  now=1;len=1;
  cin>>s[0]>>s[1]>>s[2]>>s[3]>>s[7]>>s[6]>>s[5]>>s[4];//��������˳�����ȷ 
  ans=change();
  if(ans==bfs[1])
    f=1;
  while(f==0 && now<=len)//����������� 
  {
    turn(bfs[now]);
    go1();
    if(f==0)
      go2();
    if(f==0)go3();
      ++now;
  }
  if(f==0)
    cout<<-1<<"\n";
  else
  {
    cout<<cost[f]<<"\n";
    out(f);
    if(enter%60!=0)
      cout<<"\n";  //��֤���һ���лس� 
  }
  return 0;
}
