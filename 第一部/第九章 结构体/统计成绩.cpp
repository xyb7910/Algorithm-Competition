//ͳ�Ƴɼ�
#include <iostream>
#include <iomanip>
using namespace std;
#define N 10

struct student
{
  char num[6];
  char name[8];
  int score[4];
  float avr;
}stu[N];

int main()
{
  int i,j,max,maxi,sum;
  float average;
  for(i=0;i<N;i++)
  {
    cout<<"\n����ѧ�� "<<i+1<<" ��ѧ��\n";
    cout<<"NO.:";
    cin>>stu[i].num;
    cout<<"name:";
    cin>>stu[i].name;
    for(j=0;j<3;j++)
    {
      cout<<"����"<<j+1<<":";
      cin>>stu[i].score[j];
    }
  }
  average=0;
  max=0;
  maxi=0;
  for(i=0;i<3;i++)
  {
    sum=0;
    for(j=0;j<3;j++)
     sum+=stu[i].score[j];
    stu[i].avr=sum/3.0;
    average+=stu[i].avr;
    if(sum>max)
    {
      max=sum;
      maxi=i;
    }
  }
  average/=N;
  cout<<"NO.  name  score1  score2  score3  average\n";

  for(i=0;i<N;i++)
  {
    cout<<stu[i].num<<setw(5)<<stu[i].name;
    for(j=0;j<3;j++)
      cout<<setw(9)<<stu[i].score[j];
    cout<<setw(8)<<stu[i].avr<<endl;
  }
  cout<<"ƽ����="<<average<<endl;
  cout<<"��߷���:"<<stu[maxi].name;
  cout<<" �ܷ���:"<<max;
  system("pause");
  return 0;
}
