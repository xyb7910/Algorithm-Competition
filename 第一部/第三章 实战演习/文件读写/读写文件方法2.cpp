//��д�ļ�����2 
#include <iostream>
#include <cstdlib>
int main()
{
 int i,len=0,temp[100];
 FILE *in=fopen("a.txt","r");//ָ��ָ�������ļ�
 FILE *out=fopen("b.txt","w");//����ļ���ʽ 
 for(i=0;!feof(in);i++)//��δ���ļ�ĩβ
 {
   fscanf(in,"%d",&temp[i]);//��ȡ�ļ��е�����
   len++;
 }
 for(i=0;i<len-1;i++)  //д���ļ�
   fprintf(out,"%d ",temp[i]);
 fclose(in);//�ر��ļ���
 fclose(out);//�ر��ļ���
}
