//���������⣭˫����������ʾ�� 
#include <iostream>
using namespace std;
int p1,p2,t1,t2,number,x[5];//pΪ�ף�tΪβ��numberΪ�������ܴ��� 
struct node
{
  string str;
  int pre;//ǰ�� 
}c1[5004],c2[50004];

int change(int p0)//�ҳ��ɽ����Ŀ��ܴ��������ܽ���������λ�� 
{
  if(p0==0)
  { x[1]=1,x[2]=3;return 2;  }
  else if(p0==1)
  { x[1]=0,x[2]=2,x[3]=4;return 3; }
  else if(p0==2)
  { x[1]=1,x[2]=5;return 2;  }
  else if(p0==3)
  { x[1]=0,x[2]=4,x[3]=6;return 3;}
  else if(p0==4)
  { x[1]=1,x[2]=3,x[3]=5,x[4]=7;return 4; }
  else if(p0==5)
  { x[1]=2,x[2]=4,x[3]=8;return 3; }
  else if(p0==6)
  { x[1]=3,x[2]=7;return 2;  }
  else if(p0==7)
  { x[1]=4,x[2]=6,x[3]=8;return 3; }
  else if(p0==8)
  { x[1]=5,x[2]=7;return 2;  }
}

void outC1(int v)//�ݹ�������� 
{
  if(v==1)
  {
    number++;
    cout<<c1[v].str<<endl;//���ÿһ�� 
  }
  else
  { 
    outC1(c1[v].pre);
    number++;
    cout<<c1[v].str<<endl;//���ÿһ��  
  }  
}

void outC2(int v)
{
  while(v>=1)
  {          
    number++;         
    cout<<c2[v].str<<endl;//���ÿһ��   
    v=c2[v].pre;
  }

}

void out()
{
  outC1(t1);
  outC2(c2[t2].pre);
  cout<<number-1<<endl;  
  exit(0);
}

int find(int x,string tmp)//���ұ����������ظ����ַ��� 
{
   int i,k;
   if(x==1)
   {
     for(i=1;i<=t1;i++)
       if(tmp==c1[i].str)
         return 1;
   }
   if(x==2)
   {
     for(i=1;i<=t2;i++)
       if(tmp==c2[i].str)
         return 1;     
   }  
   return 0;    
}

int checkC1(string tmp)//�����һ�����Ƿ�����ͷ 
{
  int i;
  for(i=1;i<=t1;i++)
    if(tmp==c1[i].str)
    {
      t1=i;                
      return 1;
    }
  return 0;      
}

int checkC2(string tmp)//�����һ�����Ƿ�����ͷ 
{
  int i;
  for(i=1;i<=t2;i++)
    if(tmp==c2[i].str)
    {
      t2=i;                
      return 1;
    }  
  return 0;
}

void addC1()//��Ӷ���1 
{
  int k,i,pos,v;
  string tmp,t;
  k=p1;
  pos=c1[k].str.find('0',0);//�ҳ�0�ںδ� 
  v=change(pos);//��ÿ��Խ����Ĵ��� 
  for(i=1;i<=v;i++)//���ĸ����򶼱��� 
  { 
    tmp=c1[k].str;  //�����滻 
    t=tmp[x[i]];
    tmp.replace(pos,1,t);
    tmp.replace(x[i],1,"0");
    if(find(1,tmp)==0)//����������޸����ַ���������� 
    {
      t1++;
      c1[t1].str=tmp;
      c1[t1].pre=p1;
      if(checkC2(tmp)==1)//�������һ������ͷ 
        out(); 
    }   
  }
  if(p1<t1)  
    p1++;    
} 

void addC2()//��Ӷ���2 
{
  int k,i,pos,v;
  string tmp,t;
  k=p2;
  pos=c2[k].str.find('0',0);
  v=change(pos);
  for(i=1;i<=v;i++)//���ĸ����򶼱��� 
  { 
    tmp=c2[k].str;  //�����滻 
    t=tmp[x[i]];
    tmp.replace(pos,1,t);
    tmp.replace(x[i],1,"0");
    if(find(2,tmp)==0)//����������޸��ַ�����������´� 
    {
      t2++;
      c2[t2].str=tmp;
      c2[t2].pre=p2;
      if(checkC1(tmp)==1)//�������һ�����غϣ����ӡ��� 
        out();
    }
  }
  if(p2<t2)  
    p2++;    
} 

int main()
{ 
  //freopen("Puzzle8.in","r",stdin);  
  freopen("Puzzle8.ans","w",stdout);
  int i;  
  string start="317428650";
  string goal= "123804765";
  p1=1,p2=1;//��ָ�� 
  t1=1,t2=1;//βָ�� 
  c1[1].str=start;//���±�1��ʼ 
  c1[1].pre=0;
  c2[1].str=goal;
  c2[1].pre=0;

  while(t1<5000 ||t2<5000) 
  {
    if(t1<=t2 )//������չ���У����ж̵����ȿ���
      addC1();
    else
      addC2();  
  }
  cout<<"-1\n";    
}
