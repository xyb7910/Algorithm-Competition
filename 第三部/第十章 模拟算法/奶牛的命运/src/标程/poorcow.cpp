//��ţ������ 
#include <cstdio>
#include <limits.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

long h[1001+10],p[1001+10],pro[1001+10];
long milk[1001+10][250+1];
char del[1001+10];
long k,i,j,round,n;
long ob,Min,ans,ans2,now,change;//changeͳ���ж�����û��ɱ��ţ�� 
char allk;

int main()
{
  freopen("poorcow.in","r",stdin);
  freopen("poorcow.out","w",stdout);  
  scanf("%ld",&k);
  for(round=1;round<=k;round++)
  {
    memset(h,0,sizeof(h));//���������ж��飬����Ҫ��ʼ�� 
    memset(milk,0,sizeof(milk));//m����Ϊ�������� 
    memset(del,0,sizeof(del));
    memset(pro,0,sizeof(pro));
    ans=0;
    ans2=0;
    change=0;
    scanf("%ld",&n);//������ţ�� 
    for(i=1;i<=n;i++)
    {
      scanf("%ld",&p[i]);//������ţ�������� 
      for(j=1;j<=p[i];j++)
        scanf("%ld",&milk[i][j]);
    }
    while(1)
    {
      ans++;
      for(i=1;i<=n;i++)
        if(!del[i])//������ţû�б�ɱ 
        {
          h[i]=h[i]%p[i]+1;
          pro[i]=milk[i][h[i]];
        }
      Min=LONG_MAX;
      for(i=1;i<=n;i++)
        if(!del[i])
          if(pro[i]<Min)
            Min=pro[i];//�ҵ��������ٵ���ֻţ 
      now=0;
      for(i=1;i<=n;i++)//������û�и������ţ����һ���� 
        if(!del[i])
          if(pro[i]==Min) 
          {
            now++;
            ob=i;
          }
      if(now==1)//������ֻ��һͷ��ţ�������� 
      {
        del[ob]=1;//ɱ�˸���ţ 
        ans2=ans;
        change=0;
      }
      else
        change++;
      if(change>500)//��һֱû����ţ��ɱ��������ѭ�� 
        break;
      allk=1;
      for(i=1;i<=n;i++)
        if(!del[i])
          allk=0;
      if(allk)//��ȫ����ɱ������ѭ�� 
        break;
    }
    ans=0;
    for(i=1;i<=n;i++)
      if(!del[i])
        ans++;
    printf("%ld %ld\n",ans,ans2);
  }
  return 0;
}
