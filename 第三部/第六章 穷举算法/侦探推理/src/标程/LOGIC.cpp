//��̽����2003������鸴�������⣩ 
#include <iostream>
#include <string>
using namespace std;
int m,n,p,lie[20];//lie���ĳ���Ƿ�˵�ѣ���lie[1]=1�����1�˳�ʵ��-1Ϊ˵�� 
struct
{
  string name;//���� 
  int P[20+1];//˵XX���ﷸ�ı�־����p[1]=1,��ʾ��˵��һ�����ﷸ
  int NotP[20+1];//˵XX�����ﷸ�ı�־��Ҫ��ֹһ���˵�֤���Ⱥ�ì��
  int day[7+1];//��ʾ��˵���������ڼ���������һ����day[1]=1,����Ϊ-1 
  int Me;//��ʾ��˵�Լ��ǲ����ﷸ�����ǣ�Ϊ1������Ϊ0 
  int NotMe;//Ҫ��ֹһ���˵�֤���Ⱥ�ì�ܣ�һ��˵�����ﷸ��һ��˵�Ҳ����ﷸ 
}student[20+1];//���20���� 

int IsHe(int k,int g)//����K�����Ƿ�˵�������ﷸ 
{
  int i;
  for(i=1;i<=m;i++)
    if(i!=g && student[k].P[i]==1)//���˵������������˵�� 
      return 0;
  if(student[k].P[g]==1)      
    return 1;
  return -1;//��������      
}

int NotHe(int k,int g)//����K�����Ƿ�˵���˲����ﷸ 
{
  int i;
  if(student[k].NotP[g]==1)//�������ﷸȴ˵���ǵģ�˵�� 
    return 0;  
  for(i=1;i<=m;i++)
    if(i!=g && student[k].NotP[i]==1)//���˵���˲����ﷸ�ģ���ʵ 
      return 1;  
  return -1;    
}

int Today(int k,int day)//����K���˽��������ڼ��Ƿ�˵�� 
{
  for(int i=1;i<=7;i++)
    if(i!=day && student[k].day[i]==1)//˵�����Ǳ�����ڵģ�˵�� 
      return 0;
  if(student[k].day[day]==1)//˵�����ڵģ���ʵ 
    return 1;
  return -1;//��������     
}

int err(int k)//�޴��ж�Ҳ�ɹ�ȫ�����ݣ����߼�Ӧ������ 
{
  int Num=0,i;  
  for(i=1;i<=m;i++)  //ָ�ü���Ϊ�ﷸ�ģ�˵��
    if(student[k].P[i]==1)
     Num++;
  if(Num>1)
    return 0; 
  Num=0;    
  for(i=1;i<=7;i++)  //ָ�ü���Ϊ�������ģ�˵��
    if(student[k].day[i]==1)
     Num++;
  if(Num>1)
    return 0;
  return 1;    
}

int judge(int g,int day)//����Ϊ�ﷸ�������� 
{
  int j,k,lieNum;
  memset(lie,0,sizeof(lie));//ע������Ҫ����Ϊ0 
  for(k=1;k<=m;k++)//��G���ﷸ
  { 
    if(err(k)==0)//ָ�ü���Ϊ�ﷸ�ģ�˵�ѣ�ָ�ü���Ϊ�������ģ�˵�� 
    { 
      if(lie[k]==1)
        return 0;  
      else
        lie[k]=-1;
    }
    if(student[k].Me==1 && k==g)//�ﷸk���Գ���
    {  
      if (lie[k]==-1)
        return 0;//��˵�滰��˵�ٻ���ì���˳�
      else
        lie[k]=1;//��Ǳ��˳�ʵ
    }
    if(student[k].NotMe==1 && k==g)//�ﷸk�Լ����������ﷸ
    {
      if(lie[k]==1)
        return 0;//��˵�滰��˵�ٻ���ì���˳� 
      else     
        lie[k]=-1;//˵�� 
    } 
    if(student[k].Me==1 && k!=g)//�����ﷸK�ı��˳����Լ����ﷸ�� 
    {
      if(lie[k]==1)
        return 0;
      else
        lie[k]=-1;     
    }
    if(student[k].NotMe==1 && k!=g)//�����ﷸK�ı��˲������Լ����ﷸ�� 
    {
      if(lie[k]==-1)
        return 0;
      else
        lie[k]=1;       
    }
    if(student[k].P[g]==1)//�ﷸK�����˵�����ﷸ
    {
      if(lie[k]==-1) 
        return 0;
      else
        lie[k]=1;//�����ǳ�ʵ��
    }    
    if(student[k].NotP[g]==1)//�ﷸK�����˵�������ﷸ
    {
      if(lie[k]==1)
        return 0;
      else  
        lie[k]=-1;//˵��
    }     
    if(IsHe(k,g)==0)//�ﷸK�����˵�������ﷸ��,��˵�� 
    {
      if(lie[k]==1)
        return 0;
      else 
        lie[k]=-1;      
    } 
    if(NotHe(k,g)==1)//�ﷸK�����˵���˲����ﷸ��,��ʵ 
    {
      if(lie[k]==-1)
        return 0;
      else 
        lie[k]=1;      
    }
    if(Today(k,day)==0)//˵�������ѵ�
    {
      if(lie[k]==1)
        return 0;
      else 
        lie[k]=-1;           
    }   
    if(Today(k,day)==1)//˵����������
    {
      if(lie[k]==-1)
        return 0;
      else 
        lie[k]=1;           
    }     
  } 
  lieNum=0;  
  for(j=1;j<=m;j++)//ͳ��˵������ 
    if(lie[j]==-1)
     lieNum++;
  if(lieNum>n)//˵�����������޶���ì�ܣ��˳� 
    return 0;  
  
  lieNum=0;   
  for(j=1;j<=m;j++)//ͳ��˵�滰���� 
    if(lie[j]==1)
     lieNum++;
  if(lieNum>m-n)//˵�滰���������޶���ì�ܣ��˳� 
    return 0;
    
  return 1;//��������������ˣ�˵���������һ����ȷ�⣬����1 
}

int main()
{
  freopen("LOGIC.in","r",stdin);
  freopen("LOGIC.out","w",stdout);
  int i,j,index,BadManNum=0;
  string temp,BadMan;
  char word[250];
  cin>>m>>n>>p;
  for(i=1;i<=m;i++)//��ȡ����      
    cin>>student[i].name;
  gets(word);//ֻ�м���һ�䣬������ȷ��֤�� 
  for(i=1;i<=p;i++)//���벢����֤�� 
  {
    string temp=gets(word);
    int pos=temp.find(":",0);
    string t1(temp,0,pos);

    for(j=1;j<=m;j++)//ȷ�����ĸ���˵�Ļ� 
      if(student[j].name==t1)
        index=j;
    temp.erase(0,pos+2);//ɾ��":"ǰ������
    if(temp=="I am guilty.")
      student[index].Me=1;
    else if(temp=="I am not guilty.")
      student[index].NotMe=1;
    else if(temp=="Today is Monday.")
      student[index].day[1]=1;  
    else if(temp=="Today is Tuesday.")
      student[index].day[2]=1; 
    else if(temp=="Today is Wednesday.")
      student[index].day[3]=1; 
    else if(temp=="Today is Thursday.")
      student[index].day[4]=1; 
    else if(temp=="Today is Friday.")
      student[index].day[5]=1; 
    else if(temp=="Today is Saturday.")
      student[index].day[6]=1;   
    else if(temp=="Today is Sunday.")
      student[index].day[7]=1;
    else
    {
      for(j=1;j<=m;j++)
      {
        t1=student[j].name+" is guilty.";
        if(temp==t1)
          student[index].P[j]=1;
      }   
      for(j=1;j<=m;j++)
      {
        t1=student[j].name+" is not guilty.";
        if(temp==t1)
          student[index].NotP[j]=1;
      }        
    }                         
  }//Ԥ�������,�˴�Ӧ��֤�Ƿ�������ȷ�����Ա�һ������������� 

  for(i=1;i<=m;i++)//��ٿ��ܵ��ﷸ
    for(j=1;j<=7;j++)//��ٿ��ܵ�������
    {
      if(judge(i,j)==0)//���֤����ì�� 
        continue;
      else if(judge(i,j)==1)//���֤�ʶ����� 
      {
        if(BadMan!=student[i].name)//���壡������Ϊ���ظ�֤��ĳ�����ﷸ�� 
          BadManNum++;//�ﷸ������1 
        BadMan=student[i].name;   
      }                                     
    }
  if(BadManNum==1)
    cout<<BadMan<<endl;
  else if(BadManNum>1)
    cout<<"Cannot Determine"<<endl;
  else
    cout<<"Impossible"<<endl; 
  return 0;
}
