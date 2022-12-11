//�߾��������߾������Ľ��㷨
#include <bits/stdc++.h>
using namespace std;
#define maxn 5100
#define limit 5000 //�������5000������ 

struct BigNum
{
  int data[maxn];//�������֣�data[0]Ϊλ������567����3λ�����Ϊ376500...00
  int frac[maxn];//С�����֣�frac[0]Ϊλ������.789,��3λ�����Ϊ378900...00
  int &operator[](int n)//���������[]
  {
    return data[n];//����data[n]�ĵ�ַ
  }
  int &operator()(int n)//���������()
  {
    return frac[n];//����frac()�ĵ�ַ
  }
  BigNum()  //���캯��,���ڳ�ʼ����Ա����
  {
    data[0]=1;//��ʼ��Ϊ0
    data[1]=0;//������λ��Ϊ1
    frac[0]=0;//С������Ϊ0
  }
};

void output(BigNum temp)//����߾�����
{
  for(int i=temp[0]; i>0; i--) //�����������
    cout<<temp[i];
  if(temp(0)!=0)  //�����С�����֣������С������
  {
    cout<<".";
    for(int i=1; i<=limit-temp[0] && i<=temp(0); i++) //����С�����λ��
      cout<<temp(i);
  }
}

BigNum init(string str)  //���ַ���ת��Ϊ�߾�����
{
  BigNum temp;
  temp[0]=str.size();
  for(int i=1; i<=temp[0]; ++i)
    temp[i]=str[temp[0]-i]-'0';
  return temp;
}

BigNum sub(BigNum &a,BigNum &b)//�߾�����a���߾�����b,a��Զ���ڵ���b
{
  BigNum t;
  for(int i=1; i<=a[0]; ++i)
  {
    t[i]+=a[i]-b[i];
    t[i+1]=0;
    if(t[i]<0)
    {
      t[i]+=10;
      t[i+1]--;
    }
    if(t[i]!=0)
      t[0]=i;
  }
  return t;
}

BigNum mul(BigNum &a,int &k)//����߾�����a�˵;�����k��ֵ
{
  BigNum temp;
  for(int i=1; i<=a[0]; ++i)
  {
    temp[i]+=a[i]*k;
    temp[i+1]=temp[i]/10;
    temp[i]%=10;
  }
  temp[0]=a[0]+(temp[a[0]+1]!=0);//����λ��
  return temp;
}

BigNum result[10];//_b[i]�����b[]��k��ֵ
bool saved[10];//�ж��Ƿ��Ѵ�b*i��ֵ

BigNum Dichotomy(BigNum &a,BigNum &b,int &k)//�����Գ�,����������kֵ(0<=k<10)
{
  int L=1,R=9;//�����СֵΪ1���ұ����ֵΪ9
  while(L<=R)
  {
    int m=(L+R)/2;//ȡ�м�ֵm
    if(saved[m]==0)  //��b*m��ֵδ���棬�򱣴�
    {
      saved[m]=1;
      result[m]=mul(b,m);//����b*m��ֵ
    }

    int t=0;
    if(result[m][0]>a[0])//��b*m��λ��>a����t=1
      t=1;
    else if(result[m][0]<a[0])//��b*m��λ��<a,��t=��1
      t=-1;
    else//��λ����ȣ���t=0,���������бȽ�
    {
      for(int i=result[m][0]; t==0 && i>0; i--)
        if(result[m][i]>a[i])
          t=1;
        else if(result[m][i]<a[i])
          t=-1;
    }
    t>0?R=m-1:L=m+1;//��Χ��Сһ��
  }
  k=L-1;//ȷ����K��ֵ
  return sub(a,result[k]);//��������Ϊa��b*k
}

BigNum div(BigNum &a,BigNum &b)
{
  BigNum c,t;//cΪa/b�Ľ��,tΪ��ʱ����,���ڴ洢����
  int point,j;

  /*�������ֵ�����*/
  if(a[0]>=b[0])//��a��λ������b��λ��
  {
    t[0]=b[0];//����λ��
    for(point=a[0]-b[0]+1; point<=a[0]; ++point) //ȡaǰb[0]λ��t
      t[point-a[0]+b[0]]=a[point];//������

    point=a[0]-b[0]+1;//��ʾ��λ
    c[0]=point;

    do
    {
      t=Dichotomy(t,b,c[point]);//t=����������������д��c[point]��
      if(point==c[0] && c[point]==0)//�������aȡǰb[0]λ����С��b�����
        c[0]--;
      point--;
      if(point<1)
        break;
      for(j=++t[0]; j>1; j--)
        t[j]=t[j-1];
      t[1]=a[point];
      if(t[t[0]]==0)
        t[0]--;
    }
    while(1);

    if(c[0]==0)
      c[0]=1;//����aȡǰb[0]λ����С��bʱc[0]���ٵ�0,���޷���С����ǰ��0���
  }
  else
    t=a;

  /*С�����ֵ�����*/
  for(c(0)=1; c(0)<maxn && !(t[0]==1 && t[1]==0)/*����Ϊ0���������*/; ++c(0))
  {
    for(j=++t[0]; j>1; j--) //�˴�Ĭ��������������,��˳����ֱ����0�����
      t[j]=t[j-1];
    t[1]=0;
    t=Dichotomy(t,b,c(c(0)));
  }
  c(0)--;
  return c;
}

int main()
{
  freopen("div.in","r",stdin);
  freopen("div.out","w",stdout);
  string a,b;
  cin>>a>>b;
  BigNum m,n;
  m=init(a);
  n=init(b);

  if(n[0]==1 && n[1]==0)
    cout<<"Divisor is 0";
  else
    output(div(m,n));
  cout<<endl;
  return 0;
}
