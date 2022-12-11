//�ڣ�С���� 
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
const int sup = 100010;
int A[sup], B[sup];

bool myCMP(int a, int b)
{
  return a < b;
}

int Bsearch(int s1, int e1, int s2, int e2, int kth)
{
  int idxA = (s1 + e1) >> 1;//һ��Ϊ�� 
  int idxB = (s2 + e2) >> 1;
  int lenA = idxA - s1 + 1;
  int lenB = idxB - s2 + 1;
  if(s1 > e1)  
    lenA = 0;
  if(s2 > e2)  
    lenB = 0;
  int Len = lenA + lenB;//���������е�ǰȡ����Ԫ�ظ�����
  //������Ҫ���k��Ԫ�أ���ô���ݲ�ͬ�����
  //�����������е�һ���ص���벿�֣�����ǰ�벿��
  if(Len > kth) 
  {
    //����AΪ�ջ�ǰB�е��м�Ԫ�ظ���,���k���������ڴ���B��ǰ�벿��
    if(0!=lenB && (0==lenA || A[idxA]<=B[idxB]))//B�л���Ԫ��
      return Bsearch(s1, e1, s2, idxB - 1, kth);//�ص�B������һ��Ԫ��
    else  
      return Bsearch(s1, idxA - 1, s2, e2, kth);//����ֻ�ܽ�ȡA�е�Ԫ��
  }
  else//����������ѡȡ��Ԫ�ظ�������k������ô���ݲ�ͬ�����
      //�����������е�һ�����Ƶ���벿��
  {
    if(kth == Len)//�������
    {
      if(0 == lenA) 
        return B[idxB];
      else if(0 == lenB)//��������һ���ǿ�  
        return A[idxA];
    }
    if(0 != lenA && (0 == lenB || A[idxA] <= B[idxB]))//����ͬ�� 
      return Bsearch(idxA + 1, e1, s2, e2, kth - lenA);
    else //��֪��ǰlenA����ģ���ʣ�µ�Ԫ�����ҵ���kth - lenA����� 
      return Bsearch(s1, e1, idxB + 1, e2, kth - lenB);
    }
}

int main()
{
  freopen("k2.in","r",stdin);
  freopen("k2.out","w",stdout);  
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; ++ i) 
    cin>>A[i];
  for(int i = 0; i < m; ++ i)  
    cin>>B[i];
  sort(A, A + n, myCMP);//�������������������� 
  sort(B, B + m, myCMP);
  printf("%d\n", Bsearch(0, n - 1, 0, m - 1, k));
  return 0;
}
