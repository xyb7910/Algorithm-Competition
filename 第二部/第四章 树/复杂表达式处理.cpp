//���ӱ��ʽ���� 
#include<iostream>
#include<string>
#include<iomanip>//������ʾ���ɵ�����ͷ�ļ� 
#include<windows.h>//������ʾ���ɵ�����ͷ�ļ� 
#define max 1001
using namespace std;

string tree[max];
int qkh(string str[],int i,int *n)//ȥ���� 
{
  string a[max];    
  int j,k=0;
  int sum=0;
  if(i==*n&&str[1]=="(")//�ж��������ʽ�Ƿ񱻣�����ס 
  { 
    for(j=1;j<=i;j++)
      if(str[j]=="("||str[j]==")")//ͳ�����ŵ�λ���뷽�� 
      {
        k++;
        a[k]=str[j];
      }
    if((a[2]=="("&&a[k-1]==")")||k==2)
    //�磨1+2��*��3+4���Ǳ��ʽǰ��Ϊ�������������ʽȴ������һ�������ڣ������������ 
    {
      for(j=1;j<=*n-2;j++)
        str[j]=str[j+1];
      str[*n]="\0";str[*n-1]="\0";
      *n=*n-2;
      return *n+1;
    }
  } 
  for(j=i;j>=0;j--)//�������û�и������� �ַ��������������ڵ����� 
  {
    if(str[j]==")")
      sum++;
    if(str[j]=="(")
      sum--;
    if(sum==0)
      break;
  }
  return j;
}

void zhh(int n,string str2[],int level,int m)
{
  if(m==1)//�����һ����ŵ�λ�á��˾�Ϊ������ 
    level=2*level;
  if(m==-1)//ͬ�ϡ������� 
    level=2*level+1;
     
  int l=0,r=0,i,j;
  int a=1,k;
  /*for(i=1;i<=n;i++)
    cout<<str2[i];cout<<endl;*/
  //�����е��Ӵ�����ȡ��ע�� 
  if(n!=1)
    for(i=n;i>=1;i--)
    {
      if((str2[i]=="*"||str2[i]=="/")&&a==1)
      //a��֤���������һ�Σ���������ġ����ұߵ�*��/�� 
        {k=i;a--;}
      if(str2[i]==")")//�����Ž��д��� 
        {i=qkh(str2,i,&n);continue;}
      else if(str2[i]=="+"||str2[i]=="-")
      //��ȡ���ұ��������+��-�Ž������������ķֽ� 
        {l=i-1;r=n-i;break;}
    }
  if(i==0&&a==0&&l==0&&r==0)
  //����������+��-�ţ���ȥ*��/�������� 
    {l=k-1;r=n-k;}
  if(l>0)//������ 
  {
    string part1[l+1];//����������ֵ 
    for(i=0;i<l+1;i++)
      part1[i]=str2[i];
    zhh(l,part1,level,1);       
  }
  if(r>0)//������ 
  {
    string part2[r+1];//����������ֵ 
    for(i=0,j=l+1;i<=r+1,j<=n;i++,j++)
      part2[i]=str2[j];
    zhh(r,part2,level,-1);
  }
  tree[level]=str2[l+1];
}

void qx(int level)//ǰ����� 
{
  cout<<tree[level];
  if(tree[2*level]!="\0")
    qx(2*level);
  if(tree[2*level+1]!="\0")
    qx(2*level+1);
}

void hx(int level)//������� 
{
  if(tree[2*level]!="\0")
    hx(2*level);
  if(tree[2*level+1]!="\0")
    hx(2*level+1);
  cout<<tree[level];
}

void draw1(int loo,int level)//���������� 
{
  if(tree[level]!="\0")
  {
    draw1(loo+8,2*level+1);
      cout<<setw(loo)<<tree[level]<<endl;
    draw1(loo+8,2*level);
  }
}
void draw2(int level,int x,int y,int k,int space)
{
   if(tree[level]!="\0")
   {
     HANDLE hOutput;
     COORD location;
     location.X=x;
     location.Y=y;
     hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hOutput,location);
     if(k==1)
       cout<<tree[level]<<"/";
     else if(k==2)
       cout<<"\\"<<tree[level];
     else
      cout<<tree[level];
     draw2(2*level,x-space,y+1,1,space/2);
     draw2(2*level+1,x+space,y+1,2,space/2);
   }
}

int main()
{
  char a;
  string str[max];
  int num=1;
   
  while(1)
  {
    if((a=getchar())=='\n')
      break;
    else
    {
      str[num]=a;
      num++;
    }       
  }
  num--; 
  zhh(num,str,1,0);
  cout<<"������ʽ��";
  for(int i=1;i<=num;i++)
    cout<<str[i];
  cout<<endl;
  cout<<"ǰ����ʽ:";
  qx(1);
  cout<<endl;
  cout<<"������ʽ��";
  hx(1);
  cout<<endl;
  //draw1(0,1);//������ʾ�� 
  cout<<endl;
  draw2(1,40,3,0,20);//������ʾ��  
  getchar();
  getchar();
  return 0;  
}
