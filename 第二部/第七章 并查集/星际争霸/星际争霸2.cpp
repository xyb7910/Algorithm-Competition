//�Ǽ�����2 
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int fa[30001],s[30001],t[30001],m;
/*
fa[i]  i�ĸ���  ��ʼֵΪi  �Լ�
s[i]   i���ڶ����� i֮ǰ��Ԫ�صĸ���  ��ʼֵΪ0
t[i]   i���ڶ����� ���е�Ԫ�غ�       ��ʼֵΪ1 
*/

/*�鼯��ʱ����·��ѹ��������·��ѹ����ʱ��sҲҪ�����޸ģ�
s[i]=s[i]+s[fa[i]]  ��ΪiҪ���ڸ��ϣ�  ����Ҫ������S */
int find(int v)
{
  int p;
  if(fa[v]==v)return(v);
  p=find(fa[v]);
  s[v]+=s[fa[v]];
  fa[v]=p;
  return(fa[v]);
}

int main()
{
  int i,fx,fy,x,y;
  char ch;
  freopen("galaxy.in","r",stdin);
  freopen("galaxy.out","w",stdout);
  scanf("%d\n",&m);

  for(i=1;i<=30000;i++)
  {
    fa[i]=i; 
	s[i]=0;
	t[i]=1;
  }

  for(i=1;i<=m;i++)
  {
	scanf("%c %d %d\n",&ch,&x,&y);
	fx=find(x);
	fy=find(y);
	if(ch=='M')
    {
	 if(fx!=fy)
     {
		fa[fx]=fy;
		s[fx]+=t[fy];
		t[fy]+=t[fx];
	 }
	}
	else{
     if(fx!=fy)
		printf("-1\n");
	 else 
		if(x==y)printf("0\n");
		else printf("%d\n",int(abs(s[x]-s[y])-1));
	}
  }
  fclose(stdin);
  fclose(stdout);
  return(0);
}
