//��������
#include <stdio.h>

int main()
{
  int leap(int year);
  struct
  {
    int year;
    int month;
    int day;
  }date;
  printf("�������ڣ�");
  scanf("%d%d%d",&date.year,&date.month,&date.day);
  if(date.year>0)
  switch(date.month)
  {
    case 1: if(date.day>0 && date.day<=31)
              printf("�������������һ��֮�еĵ�%d�졣\n",date.day);
            else printf("���ڴ���\n");break;
    case 2: if(date.day>0 && date.day<=(leap(date.year)?29:28))
              printf("�������������һ��֮�еĵ�%d�졣\n",31+ date.day); 
            else printf("���ڴ���\n");break;
    case 3: if(date.day>0 && date.day<=31)
              printf("�������������һ��֮�еĵ�%d�졣\n",59+date.day+leap (date.year));
            else printf("���ڴ���\n");break;
    case 4: if(date.day>0 && date.day<=30)
              printf("�������������һ��֮�еĵ�%d�졣\n",90+date.day+leap (date.year));
            else printf("���ڴ���\n");break;
    case 5: if(date.day>0 && date.day<=31)
              printf("�������������һ��֮�еĵ�%d�졣\n",120+date.day+leap (date.year));
            else printf("���ڴ���\n");break;
    case 6: if(date.day>0 && date.day<=30)
              printf("�������������һ��֮�еĵ�%d�졣\n",151+date.day+leap (date.year)); 
            else printf("���ڴ���\n");break;
    case 7: if(date.day>0 && date.day<=31)
              printf("�������������һ��֮�еĵ�%d�졣\n",181+date.day+leap (date.year));
            else printf("���ڴ���\n");break;
    case 8: if(date.day>0 && date.day<=31)
              printf("�������������һ��֮�еĵ�%d�졣\n",212+date.day+leap (date.year)); 
            else printf("���ڴ���\n");break;
    case 9: if(date.day>0 && date.day<=30)
              printf("�������������һ��֮�еĵ�%d�졣\n",243+date.day+leap (date.year));
            else printf("���ڴ���\n");break;
    case 10: if(date.day>0 && date.day<=31)
               printf("�������������һ��֮�еĵ�%d�졣\n",273+date.day+leap (date.year)); 
             else printf("���ڴ���\n");break;
    case 11: if(date.day>0 && date.day<=30)
               printf("�������������һ��֮�еĵ�%d�졣\n",304+date.day+leap (date.year)); 
             else printf("���ڴ���\n");break;
    case 12: if(date.day>0 && date.day<=31)
               printf("�������������һ��֮�еĵ�%d�졣\n",334+date.day+leap (date.year)); 
             else printf("���ڴ���\n");break;
    default: printf("���ڴ���\n"); break;
 }
 else
  printf("���ڴ���\n");getchar();getchar();
}

int leap(int year)
{
  if((year%4==0 && year%100!=0) || year%400==0)
    return 1;
  else
    return 0;
}
