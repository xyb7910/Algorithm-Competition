// ͳ������� 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Max 1001
using namespace std;
int n,a[Max],temp[Max];//����n,��������a,��ʱ����temp
int ans=0;//���

void sort(int i,int j)//�鲢���� 
{
  if(i==j)
    return;
  int mid=(i+j)/2;
  sort(i,mid);
  sort(mid+1,j);
  int l,r,k;//lΪ��벿ָ�룬rΪ�Ұ벿ָ�� 
  for(l=i,r=mid+1,k=i;k<=j;k++)//k��iɨ�赽j 
  {
    if(l>mid)//�����ָ���ѵ����� 
    {
      temp[k]=a[r];//���Ұ벿���� 
      r++;
    }
    else if(r>j)//�����ָ���ѵ�ĩβ 
    {
      temp[k]=a[l];//����벿���� 
      l++;
    }
    else if(a[l]<=a[r])//����������������� 
    {
      temp[k]=a[l];//������ 
      l++;
    }
    else//�������С������ 
    {
      temp[k]=a[r];//������ 
      r++;
      ans+=mid-l+1;//ͳ���������
    }
  }
  for(k=i;k<=j;k++)
    a[k]=temp[k];//��������temp��a
}

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  sort(0,n-1);
  printf("%d\n",ans);
  return 0;
}
