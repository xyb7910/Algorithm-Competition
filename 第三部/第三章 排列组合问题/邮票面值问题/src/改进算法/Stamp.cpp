//��Ʊ��ֵ���⣭�Ľ� 
#include <stdio.h>
#include <stdlib.h> 
FILE *in=fopen("Stamp.in","r"),*out=fopen("Stamp.out","w");
 
#define M 50  // N+K��40
int N,K;
int k[M],n[M];  //k����ѡ�е���ֵ��ϣ�n[i]��ʾѡ����k[i]��ֵ������
bool line[300];  //line[i]��ʾ�ܷ�õ���ֵi����Ϊ1������Ϊ0������MAX������300
int ANS;  //����MAX
int ans[M];  //�����������

void finish()
//����c.����MAX�����ж��Ƿ����Ž�
{
	int i,MAX;
	for(i=1;line[i];i++) line[i]=0;
	MAX=i-1;   //��¼��ǰ��ȡ�õ�MAX
	for(;i<300;i++) line[i]=0;   //��ʼ��line����
	
	if(MAX>ANS)  //�����ǰMAXΪ���ţ�����֮
	{
		ANS=MAX;
		for(i=2;i<=K;i++)
			ans[i]=k[i];
	}
}

void toline()
{
	int i,s=0;
	for(i=1;i<=K;i++)
		s+=k[i]*n[i];
     //���㵱ǰ���������ֵ

	if(s<300)  //��ֹ����line��������������
		line[s]=1;
}

void nn(int dep,int s)
//����b.������� n[dep]:��ֵk[dep]����Ʊ������;s:ʣ�����������
{
	int i;
	for(i=0;i<=s;i++)  //k[dep]��ȡ0��s��
	{
		n[dep]=i;
	    if(s-i<0) return;
	    
		else if(dep==K)
			toline();  //����ǰƴ������ֵ����line��
			
		else if(dep<K)
			nn(dep+1,s-i);
	}
}

void kk(int dep)
//����a.��ֵ���,55ѡK
{
	int i;
	for(i=k[dep-1]+1;i<=55-K+dep;i++)
	{
		k[dep]=i;
		if(dep==K)  //��ɲ���a.��ȷ��һ�����
		{
			nn(1,N);  //b.���ѡ�еĸ���ֵ��Ʊ������
			finish();  //c.ȷ������ϵ�MAX�����жϸ���ֵ����Ƿ����
		}
		else
			kk(dep+1);
	}
}

int main()
{
	fscanf(in,"%d %d",&N,&K);
	k[1]=1;ans[1]=1;
	kk(2);  //k[1]��Ϊ1����2��ʼ�ݹ����

	//���
	int i;
	for(i=1;i<=K;i++)
	    fprintf(out,"%d ",ans[i]);
	fprintf(out,"%d\n",ANS);
	return 0;
}
