//���޾���1 
#include <cstdio>
#include <cstring>
#define N 15
#define M 110
#define MAX 550

int s[MAX];//��¼һ�����ڿ��ܵ�״̬
int num[MAX];//��Ӧÿ��״̬���˶��ٸ����� 
int states; //״̬����
long long f[N][M][MAX];//f[i][j][k]����i��״̬Ϊk,������j������
                       //ע��˴����±궨�����в�ͬ  
int n,m;

void DP()
{
  int i,j,a,c,mm,b,cc;
  long long ans;
  memset(f,0,sizeof(f));
  //�ȼ����1�е����
  for(i=0; i<states; i++)//ö��һ�п��ܳ��ֵ�״̬
  {
    j=num[i];  //�����״̬�·��˶��ٸ����� 
    if(j<=m) 
      f[1][j][i]++;//���зŵĸ������ܳ�������
  }

  for(i=2; i<n; i++) //�ӵ�2��dp����n-1��
    for(j=0; j<=m; j++)//����i�У�һ������j������
      for(a=0; a<states; a++)//��ǰ��i�е�״̬
      {
        c=num[a];//c��ʾ��i�з��˶��ٸ�����
        if(c>j) 
          continue; //����ǰ�е���������������j�������
        mm=j-c;  //��ôǰi-1�е�������mm
        for(b=0; b<states; b++)//ö�ٵ�i-1�е�״̬
        {
          cc=num[b];//cc��ʾ��i-1�з��˶��ٸ����� 
          if(cc>mm) 
            continue; //����ǰ�е���������������mm�����
          if(s[a] & s[b]) //�й���
            continue;     
          if(s[a] & (s[b]<<1))//�й��� 
            continue;
          if(s[b] & s[a]<<1)//�й���   
            continue;
          f[i][j][a] += f[i-1][mm][b];
        }
  }
    
  ans=0;
  for(a=0; a<states; a++)//ö�����һ�е�״̬
  {
    c=num[a];//���е�������
    if(c>m) 
      continue;//���е��������ͳ�������������
    j=m-c;  //ǰn-1�е�����
    for(b=0; b<states; b++)  //��n-1�е�״̬
    {
      cc=num[b];  //��n-1�е�״̬
      if(cc>j) 
        continue;//��n-1�е�����������������
      if(s[a] & s[b]) 
        continue;
      if(s[a] & (s[b]<<1)) 
        continue;
      if(s[b] & s[a]<<1)   
        continue;
      f[n][m][a] += f[n-1][j][b];
    }
    ans += f[n][m][a];
  }
  printf("%lld\n",ans);
}

void init_state()
{
  states=0;
  for(int i=0; i<(1<<n); i++)//ö�����п���״̬
  {
    if( i & (i<<1) )//�����ڻ��๥������ 
      continue; 
    int t=i;
    num[states]=0;
    while(t)//ͳ�������i״̬�·��˶��ٸ����� 
    { 
      num[states] += (t&1); 
      t=t>>1; 
    }
    s[states++]=i;//��������Ϸ���״̬
  }
}

int main()
{
  freopen("embattle.in","r",stdin);
  freopen("embattle.out","w",stdout);
  scanf("%d%d",&n,&m);
  init_state();  //�ҳ����п��ܵ�״̬
  DP();  //��̬�滮���
  return 0;
}
