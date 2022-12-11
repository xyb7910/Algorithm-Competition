//�������֣��ӣԣ̰� 
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void)
{
  freopen("dictionary.in","r",stdin);
  freopen("dictionary.out","w",stdout);    
  char english[11],foreign[11];
  map<string,bool>appear;  //��¼foreign��engliash�����ӳ���Ƿ����
  map<string,string>translate; //��¼foreign��engliash��ӳ��

  while(true)//�����ֵ� 
  {
    char t;  //��ʱ���� 
    if((t=getchar())=='\n')  //�ж��Ƿ������˿���
      break;
    else     //����english
    {
      english[0]=t;
      int i=1;
      while(true)
      {
		t=getchar();
		if(t==' ')
		{
		  english[i]='\0';
		  break;
		}
		else
		  english[i++]=t;
      }
    }
    cin>>foreign;
    getchar();  //���� ����foreign��� �س���

    appear[foreign]=true;
    translate[foreign]=english;
  }

  char word[11];
  while(cin>>word)//��ʼ���� 
  {
    if(appear[word])
      cout<<translate[word]<<endl;
    else
      cout<<"eh"<<endl;
  }
  return 0;
}
