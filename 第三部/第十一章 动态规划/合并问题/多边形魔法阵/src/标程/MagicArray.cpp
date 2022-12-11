//�����ħ���� 
#include <iostream>
#include <cstdlib>
#include <fstream>
#define NMAX 51

std::ifstream cin ("MagicArray.in");
std::ofstream cout("MagicArray.out");

int n;
int arr[NMAX];
char opr[NMAX];
int fmax[NMAX][NMAX],
    fmin[NMAX][NMAX];
bool bmax[NMAX][NMAX],
     bmin[NMAX][NMAX];

int calcmax(int i, int l); 
int calcmin(int i, int l); 

int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i] >> opr[i];
    
  int ans = 0x80000000, t;//��ʼ��Ϊ��Сֵ 
  for(int i = 0; i < n; i++)//ѭ��ÿ���ڵ㿪ʼ��  
    if((t = calcmax(i, n)) > ans)
      ans = t;
  cout << ans << '\n';
  return 0;
}

//���±�Ϊi��ʼ������Ϊl�������ֵ 
int calcmax(int i, int l)
{
  if(l <= 1)
    return arr[i];
  if(bmax[i][l])//���������¼�Ƿ��Ѿ����㣬��ֹ���Ϊ0���¶������ 
    return fmax[i][l];//����Ѽ���ͷ���  
  int ret = 0x80000000;//��ʼ��Ϊ��Сֵ 
  for(int t = 0; t < l - 1; t++)
  {
    int tmp;
    if(opr[(i + t) % n] == '+')
    {//�Ӻ�ֻ�ü����������ֵ 
      tmp = calcmax(i, t + 1) + 
      calcmax((i + t + 1) % n, l - t - 1);
      if(tmp > ret)
        ret = tmp;
    }
    else
    {//�˷������������Сֵ��⣬ͳ�����ֵ 
      tmp = calcmax(i, t + 1) *
      calcmax((i + t + 1) % n, l - t - 1);
      if(tmp > ret)
        ret = tmp;
      tmp = calcmax(i,t+1)*calcmin((i+t+1)%n,l-t-1);
      if(tmp > ret)
        ret = tmp;
      tmp = calcmin(i,t+1)*calcmax((i+t+1)%n,l-t-1);
      if(tmp > ret)
        ret = tmp;
      tmp = calcmin(i,t+1)*calcmin((i+t+1)%n,l-t-1);
      if(tmp > ret)
        ret = tmp;
    }
  }
  bmax[i][l] = true;//�����Ѿ����� 
  fmax[i][l] = ret;//������ 
  return ret;
}

//���±�Ϊi��ʼ������Ϊl������Сֵ������ͬ�ϣ�  
int calcmin(int i, int l)
{
  if(l <= 1)
    return arr[i];
  if(bmin[i][l])
    return fmin[i][l];
  int ret = 0x7FFFFFFF;
  for(int t = 0; t < l - 1; t++)
  {
    int tmp;
    if(opr[(i + t) % n] == '+')
    {
      tmp=calcmin(i,t+1)+calcmin((i+t+1)%n,l-t-1);
      if(tmp < ret)
        ret = tmp;
    }
    else
    {
      tmp = calcmin(i,t+1)*calcmin((i+t+1)%n,l-t-1);
      if(tmp < ret)
        ret = tmp;
      tmp=calcmax(i,t+1)*calcmin((i+t+1)%n,l-t-1);
      if(tmp < ret)
        ret = tmp;
      tmp=calcmin(i,t+1)*calcmax((i+t+1)%n,l-t-1);
      if(tmp < ret)
        ret = tmp;
      tmp=calcmax(i,t+1)*calcmax((i+t+1)%n,l-t-1);
      if(tmp < ret)
        ret = tmp;
    }
  }
  bmin[i][l] = true;
  fmin[i][l] = ret;
  return ret;
}
