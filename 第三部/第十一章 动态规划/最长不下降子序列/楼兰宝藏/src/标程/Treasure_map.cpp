//¥������
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
  vector <int> v;//�˴�vector����ջʹ��
  for(int i = 0; i < p; i++)
    scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s+p, cmp);//��xֵ����
  for(int i = 0; i < p; i++)
  {
    //itΪ��������upper_bound��vector���ҵ�����s[i].y�ĵ�һ��λ��
    //upper_bound��lower_bound�����������������ʹ�ã�ʹ�ö��ֲ���
    vector<int>::iterator it=upper_bound(v.begin(),v.end(),s[i].y);
    if(it != v.begin())//�������ͷԪ��
    {
      it--;
      *it = s[i].y;//�Ѹ�λ�õ�ֵ�滻Ϊpoint[i].y
    }
    else//���s[i].y>ͷԪ��,��ֱ�Ӳ���
      v.insert(v.begin(), s[i].y);
  }
  printf("%d\n", v.size());
  return 0;
}

