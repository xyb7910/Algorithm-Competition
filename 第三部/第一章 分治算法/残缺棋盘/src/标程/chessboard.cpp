//��ȱ���� 
#include <iostream>
#include <cstdlib>
using namespace std;
int k=1,c[1024][1024];//���Ͻ�������Ϊ��1��1�� 

void lt(int x1,int y1,int x2,int y2 )//���� 
{
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=4;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=4;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=4; //���ͼ��4     
}

void lb(int x1,int y1,int x2,int y2 )//���� 
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=2;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=2;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=2;//���ͼ��2   
}

void rt(int x1,int y1,int x2,int y2 )//����
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=3;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=3;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=3;//���ͼ��3      
}
 
void rb(int x1,int y1,int x2,int y2 )//����
{
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=1;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=1;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=1;//���ͼ��1      
} 

void work(int x1,int y1,int x2,int y2)//�ݹ麯�� 
{
  int i,j,p,q;   
  if(x2-x1==1)//������Ϊ2*2ʱ,��� ������ 
  {
    for(i=x1;i<=x2;i++)//���һ�����Ѹ��ǵ��ںδ� 
      for(j=y1;j<=y2;j++)
        if(c[i][j]!=0)
          p=i,q=j;
    if(p==x1 && q==y1)//�����Ͻ�
      lt(x1,y1,x2,y2);
    if(p==x1 && q==y2)  //�����½�
      lb(x1,y1,x2,y2);
    if(p==x2 && q==y1)//�����Ͻ� 
      rt(x1,y1,x2,y2);
    if(p==x2 && q==y2)  //�����½�   
      rb(x1,y1,x2,y2);
  }   
  else
  {
    for(i=x1;i<=x2;i++)  //���Ҹ÷���Ļ�����Ѹ��ǵĵ��ںδ� 
      for(j=y1;j<=y2;j++)
        if(c[i][j]!=0)
          p=i,q=j;
    if(p<=(x1+(x2-x1)/2))
      if( q<=(y1+(y2-y1)/2))//��õ�λ�����Ͻ�
        lt(x1,y1,x2,y2);
      else  //��õ������½� 
        lb(x1,y1,x2,y2);
    if(p>(x1+(x2-x1)/2))
      if (q<=(y1+(y2-y1)/2))  //��õ�λ�����Ͻ�
        rt(x1,y1,x2,y2);
      else  //��õ������½� 
        rb(x1,y1,x2,y2);
    work(x1,y1,(x1+(x2-x1)/2),(y1+(y2-y1)/2));//ƽ��Ϊ�Ŀ��ݹ� 
    work((x1+(x2-x1)/2+1),y1,x2,(y1+(y2-y1)/2));
    work(x1,(y1+(y2-y1)/2+1),(x1+(x2-x1)/2),y2);
    work((x1+(x2-x1)/2+1),(y1+(y2-y1)/2+1),x2,y2);    
  }
}

void out()//������� 
{
  int i,j;   
  for(i=1;i<=k;i++)
  {
    for(j=1;j<=k;j++)
     cout<<c[j][i]<<' ';
    cout<<endl;
  }       
}

int main()
{ 
  freopen("chessboard.in","r",stdin);
  freopen("chessboard.out","w",stdout);  
  int i,n,x,y;
  cin>>n>>x>>y;
  for(i=1;i<=n;i++)
    k=k*2;  
  c[x][y]=7;//���廵������Ϊ7 
  work(1,1,k,k);//���϶�������Ϊ��1,1)�����¶�������Ϊ��k,k�� 
  out();
  return 0;
}
