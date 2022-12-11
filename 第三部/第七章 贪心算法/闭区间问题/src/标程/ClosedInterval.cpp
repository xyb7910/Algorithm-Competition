//���������� 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=40002;

struct segment
{
  int begin, end;
  segment(int _b=0, int _e=0):begin(_b),end(_e){};
  inline bool operator<( const segment& ss ) const
  {//����������Ҷ˵�����
    return end<ss.end || (end==ss.end)&&(begin<ss.begin);
  }
  inline void input()
  {
    scanf("%d %d",&begin, &end);
    if(begin>end)//��������֤��˵�ֵ�����Ҷ˵��
    begin^=end, end^=begin, begin^=end;
  }
}seg[maxn];

int main()
{
  freopen("ClosedInterval.in","r",stdin);
  freopen("ClosedInterval.out","w",stdout);  
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    int i, res=1, limit;
    for(i=0; i<n; i++)
      seg[i].input();
    sort(seg,seg+n);
    limit=seg[0].end;
    for(i=1; i<n; i++)
    {//seg[i].begin<=limit���������䶼���໥�ཻ�ģ�
    //��Ϊ��Щ�����Ȼ�й�����limit����ĳһ��������Ҷ˵�
      if(seg[i].begin>limit)
        res++, limit=seg[i].end;
    }
    printf("%d\n",n-res);
  }
  return 0;
}
