//��Ʊ��ֵ���� 
#include <stdio.h>
#include <stdlib.h>
int k,n;
int ans[11],val[11];//val[i]��ʾ��i����Ʊ�����
int f[1000],Max;

/*
ö�ٵ�dep����Ʊ����ֵ����ÿ��ȷ������ֵ�ݹ�����Խ�һ��ȷ����һ����Ʊ����ֵ
��ֻ��ǰdep-1����Ʊ�ܴճ�1~max֮������һ����������ܴճ�max+1
*/
void search(int dep,int max)//max��ʾǰdep-1����Ʊ����������յ�max������
{
  int i,j,t[1000];
  if(dep>k)//��������������Ʊ���Ѿ�ȷ�������¼��
  {
    if(max>=Max)
      for(Max=max,i=1;i<=k;i++)
		ans[i]=val[i];
    return;
  }
    
  for(i=0; i<1000; i++)  //���ݶ�������
    t[i]=f[i];
    
  int v;//��dep����Ʊ��ֵ(�ض����ڵ�dep-1����Ʊ����ֵ)
  for(v=val[dep-1]+1; v<=max+1; v++)//��vΪmax+2����max+1�޷��ճ�
  {
    val[dep]=v;
    for(int value=0; value<1000-v; value++)
      if(f[value]+1 < f[value+v])
		f[value+v]=f[value]+1;
    for(j=max; f[j]<=n; j++);//�ҵ���С��jʹ��f[j]>n
    //��f[j]>n���ʾ�޷���n����ȷ����dep����Ʊ�ճ�j
    //�������ȷ����dep����Ʊ���ֻ�ܴճ�����j-1������
      search(dep+1, j-1);//ȷ����һ����Ʊ���
    
    for(j=0;j<1000;j++)//��ԭ��������
            f[j]=t[j];
  }
}

int main()
{
  freopen("Stamp.in","r",stdin);
  freopen("Stamp.out","w",stdout);  
  int i,j;
  scanf("%d%d",&n,&k);
  val[1]=1; //һ��ʼֻȷ���˵�һ����Ʊ,��һ����Ʊ��Ȼ��1
  for(i=0; i<=n; i++)//Ҫ�ճ�������n����ֵi��Ҫi�ŵ�һ����Ʊ
    f[i]=i;
  for( ; i<1000; i++)//����n����ֵ�����ܴճ�������Ϊ����
    f[i]=1e9;
    
  //��Ϊ��һ����Ʊ��ֵ�Ѿ�ȷ����ֱ�Ӵӵڶ�����Ʊ��ʼö��
  search(2,n);//���õ�һ����Ʊ����������յ���ֵn������n�ŵ�һ����Ʊ
  for(i=1; i<=k; i++)//���
    printf("%d ",ans[i]);
  printf("%d\n",Max);
  return 0;
}
