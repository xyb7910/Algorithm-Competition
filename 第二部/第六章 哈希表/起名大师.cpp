//������ʦ 
#include <bits/stdc++.h>
using namespace std;
# define ULL unsigned long long

const int p=233;
const int maxn=400005;
char c[maxn];
ULL Hash[maxn];//ע��hash����Сд���Է�ֹ���Ƴ�ͻ
ULL Pow[maxn]= {1};//Pow[0]=1 

int main()
{
  for (int i=1; i<=maxn; ++i)//Ԥ�������p^i
    Pow[i]=Pow[i-1]*p;
  while (scanf("%s",c+1)!=EOF)
  {
    int l=strlen(c+1);
    for (int i=1; i<=l; ++i)
      Hash[i]=Hash[i-1]*p+c[i]-'a'+1;
    for (int i=1; i<=l; ++i)
      if(Hash[i]==Hash[l]-Hash[l-i]*Pow[i])
        printf("%d ",i);
    printf("\n");
  }
  return 0;
}

