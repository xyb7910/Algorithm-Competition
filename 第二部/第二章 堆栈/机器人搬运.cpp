//������˳���8���ľ 
#include <stdio.h>

int a[4]={1,4,3,2},b[4]={5,8,7,6};//��ʼ�� 
int c[2],d[2],e[2],f[2];//������ 
int A[4],B[4];//����� 
int X[4]={1,2,3,4},Y[4]={5,6,7,8};//�Ա��� 
int aa,bb,cc,dd,ee,ff,AA,BB,XX,YY;//�����ǵ�ָ�� 
int STEP;//ͳ�Ʋ��� 

int OK()//ͨ��Ŀ���̺Ͳο��̶Աȣ��ж��Ƿ�ɹ� 
{
  int i;
  for(i=0;i<=3;i++)
    if(X[i]!=A[i])
      return 0;
  for(i=0;i<=3;i++)
    if(Y[i]!=B[i])
      return 0;  
  return 1;      
}

void out()//�����ã�����ʽ���� 
{
  int i; 
  printf("a: ");  
  for(i=0;i<=3;i++)
   printf("%2d ",a[i]);
  printf("  ");
  
  printf("b: ");  
  for(i=0;i<=3;i++)
   printf("%2d ",b[i]);
  printf("    ");  
  
  printf("     c: ");  
  for(i=0;i<=1;i++)
   printf("%d ",c[i]);
  printf("  ");
  
  printf("d: ");  
  for(i=0;i<=1;i++)
   printf("%d ",d[i]);
  printf("  ");  

  printf("e: ");  
  for(i=0;i<=1;i++)
   printf("%d ",e[i]);
  printf(" ");  
  
  printf("f: ");  
  for(i=0;i<=1;i++)
   printf("%d ",f[i]);
  printf("\n");
  
  printf("A: ");  
  for(i=0;i<=3;i++)
   printf("%2d ",A[i]);
  printf("  ");
  
  printf("B: ");  
  for(i=0;i<=3;i++)
   printf("%2d ",B[i]);
  //printf("\n");  
  /* 
  printf("a:%d=%d,b:%d=%d  ",aa,a[aa],bb,b[bb]);
  printf("  c:%d=%d d:%d=%d ",cc,c[cc],dd,d[dd]);
  printf("e:%d=%d f:%d=%d   ",ee,e[ee],ff,f[ff]);
  printf("  A:%d=%d,B:%d=%d  ",AA,A[AA],BB,B[BB]);
  printf("  X:%d=%d,Y:%d=%d\n\n",XX,X[XX],YY,Y[YY]);  */
}

void step(char x,char y)//ͳ�Ʋ�������ӡ������ʵ���ƶ������ô����ӿ� 
{
   ++STEP;
   printf("%c->%c\n",x,y);  
}

void move(char W)//�ƶ������� 
{
  if(W=='a')//������ƶ�a�� 
  {
    if(cc==-1)//���c��Ϊ�գ����c�� 
    {
      step('a','c');          
      c[++cc]=a[aa];  
      a[aa--]=-1;
    } 
    else if(cc==0 && a[aa]<c[cc])//���c������һ�������Ҵ��ŵı����ҪС 
    {
      step('a','c'); //���ٷ�һ������֤�����һ���������С���Է�ֹ���� 
      c[++cc]=a[aa];  
      a[aa--]=-1;
    }   
    else if(ee==-1)//���e��Ϊ�գ����  
    {
      step('a','e');  
      e[++ee]=a[aa];  
      a[aa--]=-1;
    }
    else if(ee==0 && a[aa]<e[ee])//���e������һ������Ҫ��֤���ٵ�ҪС 
    {
      step('a','e');  
      e[++ee]=a[aa];  
      a[aa--]=-1;
    }    
    else if(dd==-1)//����Ƽ��Ĺ����������ܷţ���ֻ�ܽ�������������    
    {
      step('a','d');  
      d[++dd]=a[aa];  
      a[aa--]=-1;
    }
    else if(ff==-1)
    {
      step('a','f');  
      f[++ff]=a[aa];  
      a[aa--]=-1;
    }   
  }
  if(W=='b')//ͬ�� 
  {
    if(dd==-1)
    {
      step('b','d');  
      d[++dd]=b[bb];   
      b[bb--]=-1;
    } 
    else if(dd==0 && b[bb]<d[dd])  
    {
      step('b','d');  
      d[++dd]=b[bb];   
      b[bb--]=-1;
    } 
    else if(ff==-1)
    {
      step('b','f');  
      f[++ff]=b[bb];  
      b[bb--]=-1;
    }
    else if(ff==0 && b[bb]<f[ff])
    {
      step('b','f');  
      f[++ff]=b[bb];  
      b[bb--]=-1;
    }   
    else if(cc==-1 )
    {
      step('b','c');  
      c[++cc]=b[bb];  
      b[bb--]=-1;
    }              
    else if(ee==-1 )
    {
      step('b','e');  
      e[++ee]=b[bb];  
      b[bb--]=-1;
    } 
  }     
}


int main()
{
  int i;

  /*for(i=0;i<=3;i++)//�����ʼ�� 
    scanf("%d",&a[i]);
  for(i=0;i<=3;i++)
    scanf("%d",&b[i]);*/
    
  //for(i=0;i<=3;i++)//����Ŀ��ο��� 
  //  X[i]=i+1;//�˴�Ĭ��1,2,3,4,5,6,7,8 
  //  scanf("%d",&X[i]);
  //for(i=0;i<=3;i++)
  //  Y[i]=i+5;
  //  scanf("%d",&Y[i]);
  XX=0;YY=0;//�Ƚ���ָ��ָ����ײ� 
  aa=3;bb=3;//ָ��ָ��3 
  cc=-1,dd=-1,ee=-1,ff=-1,AA=-1,BB=-1;//ָ���ʼ��    
  while(!OK())//��û�гɹ�ʱ,�ڷŲ������ܷžͷţ����ܾ����Ƶ������� 
  {                          
    if(a[aa]==X[XX] && aa>=0 && XX<=3)//a��������Ĳ��������Ƿ�ָֹ��Խ�� 
    {
      step('a','A');
      A[++AA]=a[aa];
      a[aa--]=-1;
      XX++;
    }
    else if(a[aa]==Y[YY] && aa>=0 && YY<=3)//����Ҫ��ָֹ��Խ�磬������ 
    {
      step('a','B');
      B[++BB]=a[aa];
      a[aa--]=-1;
      YY++;         
    }                                  
    else if(b[bb]==X[XX] && bb>=0 && XX<=3)//b�� 
    {
      step('b','A');
      A[++AA]=b[bb];
      b[bb--]=-1;
      XX++;         
    } 
    else if(b[bb]==Y[YY] && bb>=0 && YY<=3)
    {
      step('b','B');
      B[++BB]=b[bb];
      b[bb--]=-1;
      YY++;         
    } 
    else if(c[cc]==X[XX] && cc>=0 && cc<=1 && XX<=3)//c�� 
    {
      step('c','A');
      A[++AA]=c[cc];
      c[cc--]=-1;
      XX++;         
    } 
    else if(c[cc]==Y[YY] && cc>=0 && cc<=1 && YY<=3)
    {
      step('c','B');
      B[++BB]=c[cc];
      c[cc--]=-1;
      YY++;         
    }  
    else if(d[dd]==X[XX] && dd>=0 && dd<=1 && XX<=3)//d�� 
    {
      step('d','A');
      A[++AA]=d[dd];
      d[dd--]=-1;
      XX++;         
    } 
    else if(d[dd]==Y[YY] && dd>=0 && dd<=1 && YY<=3)
    {
      step('d','B');
      B[++BB]=d[dd];
      d[dd--]=-1;
      YY++;         
    }            
    else if(e[ee]==X[XX] && ee>=0 && ee<=1 && XX<=3)//e�� 
    {
      step('e','A');
      A[++AA]=e[ee];
      e[ee--]=-1;
      XX++;         
    } 
    else if(e[ee]==Y[YY] && ee>=0 && ee<=1 && YY<=3)
    {
      step('e','B');
      B[++BB]=e[ee];
      e[ee--]=-1;
      YY++;         
    }            
    else if(f[ff]==X[XX] && ff>=0 && ff<=1 && XX<=3)//f�� 
    {
      step('f','A');
      A[++AA]=f[ff];
      f[ff--]=-1;
      XX++;         
    } 
    else if(f[ff]==Y[YY] && ff>=0 && ff<=1 && YY<=3)
    {
      step('f','B');
      B[++BB]=f[ff];
      f[ff--]=-1;
      YY++;         
    }
    else//�������ֱ�ӷţ������Ƶ��������� 
    {
      int u,v;
      if(aa<0)//���a���Ѿ����� 
        move('b');//��ô����b�� 
      else if(bb<0)//���b���Ѿ����� 
        move('a');//��ô����a�� 
      else//�ҵ��������Ƶ����ӣ���Ŀ������ϵ����� 
      {
        for(u=aa;u>=0;u--)
          if(a[u]==X[XX] || a[u]==Y[YY])
            break;
        for(v=bb;v>=0;v--)
          if(b[v]==X[XX] || b[v]==Y[YY])
            break;    
        if(u>v)
          move('a');
        else
          move('b');     
      }                      
    }   
    out(); 
    getchar();     
  }  
  printf("Use %d steps,OK!",STEP);
  getchar();
  return 0;
}
