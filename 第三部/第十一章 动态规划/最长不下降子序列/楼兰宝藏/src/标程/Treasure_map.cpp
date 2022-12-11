//楼兰宝藏
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int x, y;
} s[100005];

int cmp(node a, node b)
{
  if(a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

int main()
{
  freopen("Treasure_map.in","r",stdin);
  freopen("Treasure_map.out","w",stdout);
  int n,m,p;
  scanf("%d%d%d", &n, &m, &p);
  vector <int> v;//此处vector当堆栈使用
  for(int i = 0; i < p; i++)
    scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s+p, cmp);//按x值排序
  for(int i = 0; i < p; i++)
  {
    //it为迭代器，upper_bound在vector里找到大于s[i].y的第一个位置
    //upper_bound和lower_bound必须在有序的序列里使用，使用二分查找
    vector<int>::iterator it=upper_bound(v.begin(),v.end(),s[i].y);
    if(it != v.begin())//如果不是头元素
    {
      it--;
      *it = s[i].y;//把该位置的值替换为point[i].y
    }
    else//如果s[i].y>头元素,则直接插入
      v.insert(v.begin(), s[i].y);
  }
  printf("%d\n", v.size());
  return 0;
}

