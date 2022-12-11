//�״����� 
#include<iostream>
#include<cmath>
using namespace std;
struct coordinate//����ṹ��(x,y)
{
  int x,y;
}p[1001];

struct interval//����ṹ��[a,b]
{
	double a;
	double b;
}b[1001];

int cmp_interval(const void *a,const void *b)//qsort�ıȽϺ���
{
	interval *A = (interval*) a;
	interval *B = (interval*) b;
	return (*A).b > (*B).b ? 1: -1;
}

double search(coordinate a,int d)//�ҳ����������Ӧ��Բ������Χ
{
	double x;
	x = sqrt((double)(d*d - a.y*a.y)) + a.x;
	return x;
}
int main()
{
  freopen("radar.in","r",stdin);
  freopen("radar.out","w",stdout);  
  int n,d,c = 0,r;//r = number of radar,c = case
  bool impossible;
  while(cin >> n >> d)
  {
    if(n == 0)
      break;
    ++c;
    impossible = 0;
    r = 1;
    for(int i = 0;i < n;++i)
    {
	  cin >> p[i].x >> p[i].y;
      if(abs(p[i].y) > d)
		impossible = 1;
      b[i].a = 2*p[i].x - search(p[i],d);
      b[i].b = search(p[i],d);
    }
    qsort(b,n,sizeof(b[0]),cmp_interval);//�����䰴�ұ߽��С��������
    if(impossible)
      cout <<"Case "<< c <<": " << -1 <<endl;
    else
    {
      int temp = 0;
      
      for(int i = 0;i < n;++i)
      {
		if(b[i].a > b[temp].b)//�԰�������ȡ���Ҷ˵ĵ�
		{
		  ++r;//����߽����֮ǰ������ұ߽磬����������״� 
		  temp = i;
        }
      }
      cout <<"Case "<< c <<": " << r << endl;
    }
  }
  return 0;
}
