//�и������� 
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ 
  freopen("CuttingSticks.in","r",stdin);
  freopen("CuttingSticks.out","w",stdout);  
  int length,n,i,j,x,y,temp,l,k,tt,sum;
  int t[51][51],p[51]; 
  while((scanf("%d",&length)) && length)
  { 
    cin>>n; //����и�Ĵ��� 
	y=0; 
	for(i=1;i<=n;i++)
    { 
	  cin>>x; //����и�λ�� 
	  p[i]=x-y; //ת����С������������ 
	  y=x; 
	} 
	p[i]=length-y;//���һ���������ĳ��� 
	
	n = i;
	for(i=0;i<=n;i++) 
	  t[i][i] = 0; //��ʼ��,��i�ε���i�ε���С����Ϊ0 
	for(l=2;l<=n;l++)
    { 
	  for(i=1;i<=n-l+1;i++)
      { 
		j=i+l-1; 
		t[i][j]=100000;//��ȡ�����ֵ 
		for(k=i;k<=j-1;k++)//�����k��ֵ 
        { 
		  temp=t[i][k]+t[k+1][j]; 
		  sum = 0; 
		  for(tt=i;tt<=j;tt++) 
			sum+=p[tt]; 
		  temp+=sum; 
		  if(temp<t[i][j]) 
			t[i][j] = temp; 
		} 
	  } 
   } 
   printf("The minimum cutting is %d.\n",t[1][n]); 
 } 
}
