#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i,t; 
char s[500000+1];
char temp[100001];
char c1[]={" that "};//�����Ƿ������������� 
char c2[]={" this "};
char c3[]={" have "};

int compare()
{
  if(strstr(temp,c1))
  {  
    return 1; 
  }
  if(strstr(temp,c2))
  {  
    return 1; 
  }
  if(strstr(temp,c3))
  {  
    return 1; 
  } 
  return 0;
}

int change()
{  
  for(t=1;t<=26;t++)
  {
    for(i=0;i<100000;i++)
    {//Сд��ĸ��Ҫ�ر��� 
     if(temp[i]>='a' && temp[i]<='z')
      {  temp[i]++;
         if(temp[i]>'z' ||temp[i]<'a')
          temp[i]=temp[i]-26; 
      }                   
      if(temp[i]>='A' && temp[i]<='Z')
      {  temp[i]++;
        if(temp[i]>'Z')
          temp[i]=temp[i]-26; 
      }
    }  
    if(compare())
      return t;
  }                      
}

int put(int t)
{  
  for(i=0;i<strlen(s);i++)
  {//Сд��ĸ��Ҫ�ر��� 
    if(s[i]>='a' && s[i]<='z')
    {  
      s[i]=s[i]+t;
      if(s[i]>'z' ||s[i]<'a')
        s[i]=s[i]-26; 
    }                   
    if(s[i]>='A' && s[i]<='Z')
    {  
      s[i]=s[i]+t;
      if(s[i]>'Z'||s[i]<'A')
        s[i]=s[i]-26; 
    }
  }  
  puts(s);  //������                   
}

int main()
{
  freopen("MSG.in","r",stdin);
  freopen("MSG.out","w",stdout);
  
  for(i=0;scanf("%c",&s[i])!=EOF;i++);
  
  for(i=0;i<10000;i++)
    temp[i]=s[i];

  put(change());
  return 0;
}
