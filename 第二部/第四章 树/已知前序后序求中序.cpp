//��֪ǰ����������� 
#include<iostream>
#include<string>
#define ANSN 10000
using namespace std;

string rx78;//������¼�����е��Ǹ��������ź���ĸ���ַ���
int final,cho[ANSN+1];//������ת������

void hwg(string a,string b)
{
  int i,mark,ll,lr,len=a.length();
  if(len>1)//�����ֹ��һ�����
  {
    if(a[1]==b[len-2])//�������ABXXX��XXXBA����ʽ����Ҫ���ദ��
    {
      string p1(a,1,len-1),p2(b,0,len-1);//ȡ������
      //������1�����������������ȷ��ʸ��ڵ�
      rx78+='{';
      mark=rx78.length()-1;//��¼�������ŵ�λ��
      rx78+=a[0];
      hwg(p1,p2);//���±�Ǻ�������
      rx78+='}';
      cho[mark]=rx78.length();//�������Ÿ�����ת��λ��
      mark=rx78.length()-1;//��¼�������ŵ�λ��

      //������2��������������������ʸ��ڵ�
      rx78+='{';
      hwg(p1,p2);//ͬ��
      rx78+=a[0];
      rx78+='}';
      cho[rx78.length()-1]=rx78.length();
      cho[mark]=rx78.length();//�����������Ÿ�����ת��λ��
    }
    else//�������ȷ����������
    {
      for(i=0;i<len-2;i++)
        if(a[1]==b[i])
          break;//���ҵ��������ĸ����
      ll=i+1;
      lr=len-1-ll;//�������������ĳ���
      if(ll)
      {
        string part1(a,1,ll),part2(b,0,ll);//ȡ��������
        hwg(part1,part2);//�ݹ���������
      }
      rx78+=a[0];//���������������ڷ����������󣬷���������ǰ���ʡ�
      if(lr)
      {
        string part3(a,1+ll,lr),part4(b,ll,lr);//ȡ��������
        hwg(part3,part4);//�ݹ���������
      }
    }
  }
  else//���ֻ��һ�����
    rx78+=a[0];
}

void dfs(string have,int pos)
{
  char ty=rx78[pos];
  if(pos>=final)//��������ѵ���ͷ
    cout<<have<<endl;
  else if(ty=='{')//������������ʱ
  {
    if(cho[pos]==-1)//�����������Ų�����ת����ֻ����ǰ��һ��
      dfs(have,pos+1);
    else//���������ת
    {
      dfs(have,pos+1);//Ҫôֱ����ǰ��һ��
      dfs(have,cho[pos]);//Ҫô��ת
    }
  }
  else if(ty=='}')
    dfs(have,cho[pos]);//���������Ŷ���ת
  else
  {
    have+=rx78[pos];
    dfs(have,pos+1);//��������ַ��ʹ��룬����������
  }
}

int main()
{
  int i;
  string front,back;
  cin>>front>>back;
  for(i=0;i<=ANSN;i++)
    cho[i]=-1;
  hwg(front,back); 
  final=rx78.length();
  dfs("",0);
  return 0;
}
