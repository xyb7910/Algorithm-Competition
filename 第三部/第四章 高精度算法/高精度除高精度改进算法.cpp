//高精度数除高精度数改进算法
#include <bits/stdc++.h>
using namespace std;
#define maxn 5100
#define limit 5000 //限制输出5000个数字 

struct BigNum
{
  int data[maxn];//整数部分，data[0]为位数，如567，共3位，则存为376500...00
  int frac[maxn];//小数部分，frac[0]为位数，如.789,共3位，则存为378900...00
  int &operator[](int n)//重载运算符[]
  {
    return data[n];//返回data[n]的地址
  }
  int &operator()(int n)//重载运算符()
  {
    return frac[n];//返回frac()的地址
  }
  BigNum()  //构造函数,用于初始化成员变量
  {
    data[0]=1;//初始化为0
    data[1]=0;//则整数位数为1
    frac[0]=0;//小数部分为0
  }
};

void output(BigNum temp)//输出高精度数
{
  for(int i=temp[0]; i>0; i--) //输出整数部分
    cout<<temp[i];
  if(temp(0)!=0)  //如果有小数部分，则输出小数部分
  {
    cout<<".";
    for(int i=1; i<=limit-temp[0] && i<=temp(0); i++) //控制小数输出位数
      cout<<temp(i);
  }
}

BigNum init(string str)  //将字符串转化为高精度数
{
  BigNum temp;
  temp[0]=str.size();
  for(int i=1; i<=temp[0]; ++i)
    temp[i]=str[temp[0]-i]-'0';
  return temp;
}

BigNum sub(BigNum &a,BigNum &b)//高精度数a－高精度数b,a永远大于等于b
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

BigNum mul(BigNum &a,int &k)//计算高精度数a乘低精度数k的值
{
  BigNum temp;
  for(int i=1; i<=a[0]; ++i)
  {
    temp[i]+=a[i]*k;
    temp[i+1]=temp[i]/10;
    temp[i]%=10;
  }
  temp[0]=a[0]+(temp[a[0]+1]!=0);//更新位数
  return temp;
}

BigNum result[10];//_b[i]存除数b[]乘k的值
bool saved[10];//判断是否已存b*i的值

BigNum Dichotomy(BigNum &a,BigNum &b,int &k)//二分试除,返回余数及k值(0<=k<10)
{
  int L=1,R=9;//左边最小值为1，右边最大值为9
  while(L<=R)
  {
    int m=(L+R)/2;//取中间值m
    if(saved[m]==0)  //若b*m的值未保存，则保存
    {
      saved[m]=1;
      result[m]=mul(b,m);//计算b*m的值
    }

    int t=0;
    if(result[m][0]>a[0])//如b*m的位数>a，则t=1
      t=1;
    else if(result[m][0]<a[0])//如b*m的位数<a,则t=－1
      t=-1;
    else//如位数相等，则t=0,则逐数进行比较
    {
      for(int i=result[m][0]; t==0 && i>0; i--)
        if(result[m][i]>a[i])
          t=1;
        else if(result[m][i]<a[i])
          t=-1;
    }
    t>0?R=m-1:L=m+1;//范围缩小一半
  }
  k=L-1;//确定了K的值
  return sub(a,result[k]);//返回余数为a－b*k
}

BigNum div(BigNum &a,BigNum &b)
{
  BigNum c,t;//c为a/b的结果,t为临时变量,用于存储余数
  int point,j;

  /*整数部分的运算*/
  if(a[0]>=b[0])//当a的位数大于b的位数
  {
    t[0]=b[0];//保存位数
    for(point=a[0]-b[0]+1; point<=a[0]; ++point) //取a前b[0]位给t
      t[point-a[0]+b[0]]=a[point];//倒序排

    point=a[0]-b[0]+1;//表示定位
    c[0]=point;

    do
    {
      t=Dichotomy(t,b,c[point]);//t=余数，除出来的商写在c[point]里
      if(point==c[0] && c[point]==0)//避免出现a取前b[0]位的数小于b的情况
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
      c[0]=1;//避免a取前b[0]位的数小于b时c[0]减少到0,而无法将小数点前的0输出
  }
  else
    t=a;

  /*小数部分的运算*/
  for(c(0)=1; c(0)<maxn && !(t[0]==1 && t[1]==0)/*余数为0则结束除法*/; ++c(0))
  {
    for(j=++t[0]; j>1; j--) //此处默认整数除以整数,因此除完后直接用0来填充
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
