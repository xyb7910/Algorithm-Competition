//���������� 
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int>freq;//�ַ���������ӳ�䣬�����յĴ����������飬�±�Ϊ�ַ��� 

string key(const string &s)//����ȫ���������� 
{
  return s.substr(0,s.find(" "));//�ҵ�һ���ո�Ȼ��ȡ��ǰ��Ĵ�       
}

int cmp(const string &a,const string &b)
{
  return freq[key(a)]>freq[key(b)];   
}

int main()
{
   ifstream fin("friends.in");
   ofstream fout("friends.out");
   vector<string> v;//�ɱ䳤���飬����������С 
   string s1,s2;
   while(fin>>s1>>s2)
   {
     v.push_back(s1+" "+s2);//��push_back,pop_back��ĩβ���ɾ��Ԫ�� 
     ++freq[s1];                  
   }
   stable_sort(v.begin(),v.end(),cmp);//�ȶ����򣬿ɱ�������ǰ��˳�� 
   for(int i=0;i<(int)v.size();i++)
     fout<<v[i]<<endl;
   return 0;     
}
