//̫�ձ���
#include <bits/stdc++.h>
using namespace std;

struct
{
  int a,b,sum;
} t[140000];
int people[50010],SUM;//people[50010]���ÿ�����ϵĴ�����SUMΪ�����ѯ���

void make(int x,int y,int num)//�����߶���
{
  t[num].a=x; //ȷ����˵�Ϊx
  t[num].b=y; //ȷ���Ҷ˵�Ϊy
  if(x==y) //���x==y��˵���Ѿ���Ҷ�ӽ����
    t[num].sum=people[y];//������Ϊ�����ı��ݷɴ�����r[y]
  else
  {
    make(x,(x+y)/2,num+num); //�ݹ鹹���������
    make((x+y)/2+1,y,num+num+1); //�ݹ鹹���Ҷ�����
    //���������������ӽ��ɴ���֮�ͣ��߶α��ֳ�����
    t[num].sum=t[num+num].sum+t[num+num+1].sum;
  }
}

void query(int i,int j,int num)//��ʼnumΪ1�����Ӹ���㿪ʼ����
{
  if(i<=t[num].a && j>=t[num].b)//�ҵ�Ҫ����߶����䣬������ֵ
    SUM+=t[num].sum; //SUM��ʼΪ�㣬�����ۼӷɴ�������󷵻ص���SUMֵ
  else
  {
    int min=(t[num].a+t[num].b)/2;
    if(i>min) //Ҫ��ѯ���߶��ڸ��߶��ұߣ���ѯ���߶ε����ӽ��
      query(i,j,num+num);
    else if(j<=min) //Ҫ��ѯ���߶��ڸ��߶���ߣ���ѯ���߶ε����ӽ��
      query(i,j,num+num+1);
    else
    {
      //Ҫ��ѯ���߶��ڸ��߶��м䣬�ֶβ�ѯ�����ҽ�㶼��
      query(i,j,num+num);
      query(i,j,num+num+1);
    }
  }
}

void add(int i,int j,int num)//��i����������j���ɴ�����ʼnumΪ1
{
  //�Ӹ���㲻�����¸��ģ�ֻҪ�����õ�i���߶ζ�������Ӧ������j
  t[num].sum+=j;
  if(t[num].a==i && t[num].b==i)//����ҵ�i��Ҷ�ӽ�㣬��ֹͣ
    return;
  if(i>(t[num].a+t[num].b)/2) //�����i�ڸ��߶ε��ұ�
    add(i,j,num+num+1);//��ݹ�������ӽ��
  else
    add(i,j,num+num);//����ݹ�������ӽ��
}

void sub(int i,int j,int num)
{
  t[num].sum-=j;
  if(t[num].a==i && t[num].b==i)
    return;
  if(i>(t[num].a+t[num].b)/2)
    sub(i,j,num+num+1);
  else
    sub(i,j,num+num);
}

int main()
{
  int n,t,j=0;
  char command[6];
  cin>>t;
  while(t--)
  {
    int temp,a,b;
    cin>>n;
    people[0]=0;
    for(int i=1; i<=n; i++)
      cin>>people[i];
    make(1,n,1);//�Ӹ����t[1]��ʼ���߶���
    cout<<"Case "<<++j<<":"<<endl;
    while(cin>>command)
      if(strcmp(command,"End")==0)
        break;
      else if(strcmp(command,"Query")==0)
      {
        cin>>a>>b;
        SUM=0;//��ʼΪ��
        query(a,b,1);//�� �����t[1]��ʼ
        cout<<SUM<<endl;
      }
      else if(strcmp(command,"Add")==0)
      {
        cin>>a>>b;
        add(a,b,1);//�Ӹ����t[1]��ʼ
      }
      else if(strcmp(command,"Sub")==0)
      {
        cin>>a>>b;
        sub(a,b,1);//�Ӹ����t[1]��ʼ
      }
  }
  return 0;
}

