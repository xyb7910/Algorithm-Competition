//��10-500���ȫ��������������ʹ��Ƕ��forѭ������
# include <iostream>
# include <math.h>
using namespace std;
int main()
{	
 int number,i,n=0;
 for(number=11;number<=500;number+=2)
 {
   for(i=2;i<=sqrt(number);i++) 
      if(number%i==0) break; 
   if(i>sqrt(number))  
   {
      cout<<number<<" ";
      n++;   //nΪ��������ۼ�ֵ
      if(n%10==0) 
         cout<<"\n";  //һ�����10�����ݼ�����
   }//end if
 }//end for
 system("pause");
 return 0;
}
