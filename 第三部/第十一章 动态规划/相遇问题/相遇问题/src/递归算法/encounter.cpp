//������������ݹ��㷨 
#include<iostream>
#include<iomanip>
using namespace std;

int n,k,Dir[101][101];
double ans;
bool encounter=1;

void init()
{
  cin>>n;
  k=(n+1)/2;
  if(k%2==1)//��Զ��������������� 
  {
    encounter=0;
    return;
  }
  for(int i=0;i<=n+1;++i) //ͳ��(x,y)��·���� 
    for(int j=0;j<=n+1;++j)
    {
      if((i==1&&j==1)||(i==1&&j==n)||(i==n&&j==1)||(i==n&&j==n))    
        Dir[i][j]=2;
      else if(i==1||i==n||j==1||j==n)
        Dir[i][j]=3;
      else 
        Dir[i][j]=4;
    }       
}

void fun(int t,int x,int y,double lv)//��t�칫��������x,y�ĸ���Ϊlv 
{
  if(x<1||x>n||y<1||y>n||t>n)//��(x,y)Խ�����ʱ�䳬�����򷵻� 
    return;
  if(x-(abs(y-k))<t) //������(x,y)������ζ�����������(t,k)���֦ 
    return; 
  if(t==x && y==k)  //�������빫������ 
  {
    ans+=lv;//�����ۼ�    
    return;
  }
  fun(t+1,x+1,y,lv/Dir[x][y]);   //���ҳ��� 
  fun(t+1,x-1,y,lv/Dir[x][y]);   //������ 
  fun(t+1,x,y+1,lv/Dir[x][y]);   //���ϳ��� 
  fun(t+1,x,y-1,lv/Dir[x][y]);   //���³��� 
  return;
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);  
  init();
  if(encounter) //����������Ŀ��ܣ���ݹ���� 
    fun(0,k,k,1);//ʱ��Ϊ0ʱ������(k,k)���괦����Ϊ1 
  cout<<setprecision(4)<<ans<<endl;
  return 0;    
}
