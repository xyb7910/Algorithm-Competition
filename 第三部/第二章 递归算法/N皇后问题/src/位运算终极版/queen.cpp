#include <iostream>
using namespace std;
int upperlim,sum;

void test(int row,int ld,int rd)
{
  int pos,p;
  if(row!=upperlim)//δ����������Ϊ11111111ʱ
  {
    pos=upperlim & ~(row | ld | rd);//ȡ����õ����п��Էŵ�λ��
    while(pos!=0)
    {
      p=pos & -pos;//ȡ�����ұߵ�1���г���
      pos=pos-p;//����λ�õ�P��pos���Ƴ�
      test(row+p,(ld+p)<<1,(rd+p)>>1);
    }  
  }
  else
    sum++;
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  int n;
  cin>>n;
  upperlim=(1 << n)-1;//���Ϊ11111111
  test(0,0,0);//���У���Խ��ߣ��ҶԽ���
  cout<<sum<<endl;
  
  //system("pause");
  return 0;
}

