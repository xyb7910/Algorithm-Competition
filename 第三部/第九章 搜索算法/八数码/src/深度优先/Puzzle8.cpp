#include <stdio.h> 
#include <stdlib.h>
#include <queue> 
#include <stack> 

using namespace std; 
#define HashTableSize 362880 
#define NOT        ! 
#define MaxDeep 50
 
typedef struct maps 
{ 
    int detail[3][3]; 
    int x, y;            // ��¼ �ո�0�������� 
}Map,*PMap; 
Map   org;                //  ��ʼ״̬ 
Map   end;                //    Ŀ��״̬ 
bool  HashTable[HashTableSize]={false};        //hash�� 
int const derection[4][2] ={ { -1 , 0 }  , {1, 0 }, { 0 , -1 } , { 0, 1 } } ;  // ���ƶ����ĸ����� 
int   Path[ MaxDeep + 1 ]; 
int   Step; 
bool  Finish; 
/** 
 * 
 *    ����������루�����ﲻ���κ������飬����Ϊ������������ȷ�ģ� 
 * 
 **/ 
void input() 
{ 
    int i,j; 
 int sum; 
    for(i = 0 ; i < 9 ; i ++ ) 
    { 
        scanf("%1d", *org.detail + i ); 
        if(0 == *(*org.detail + i) ) 
        { 
            org.x = i / 3; 
            org.y = i % 3; 
        } 
    } 
    for(i = 0 ; i < 9 ; i ++ )                //�������� 
    { 
        if( 0 == *(*org.detail + i) )  
            continue; 
        for(j = 0 ; j < i;  j ++ ) 
            if( 0 != *(*org.detail+j) && *(*org.detail + j) < *(*org.detail + i) )  
            { 
 sum ++;  
            } 
    } 
    if( sum%2 == 0 )        // Ŀ��״̬�������ֶ�Ӧ������λ�� 
    { 
        end.detail[0][0] = 1 , end.detail[0][1] = 2 , end.detail[0][2] = 3 ; 
        end.detail[1][0] = 4 , end.detail[1][1] = 5 , end.detail[1][2] = 6 ; 
        end.detail[2][0] = 7 , end.detail[2][1] = 8 , end.detail[2][2] = 0 ; 
    } 
    else 
    { 
end.detail[0][0] = 1 , end.detail[0][1] = 2 , end.detail[0][2] = 3 ; 
        end.detail[1][0] = 8 , end.detail[1][1] = 0 , end.detail[1][2] = 4 ; 
        end.detail[2][0] = 7 , end.detail[2][1] = 6 , end.detail[2][2] = 5 ; 
    } 
    return; 
} 

inline bool IsEqual(Map a , Map b)//�������״̬�Ƿ�һ��  
{ 
    return 0 == memcmp((const void *)(*a.detail),(const void *)(*b.detail),36); 
} 

int HashValue(Map a)//hashֵ�ļ���  
{ 
   int count  ;  
   int i , j ; 
   int value =0 ; 
   static int pv[9]={1,1,2,6,24,120,720,5040,40320}; 
   for(i = 0 ; i < 9 ; i ++ ) 
   { 
       for(j = 0, count =0 ; j < i ; j ++ ) 
       { 
            if( *(*a.detail+i) < *(*a.detail+j) )  
            { 
                count ++; 
            } 
       } 
       value += pv[i]*count; 
   } 
    return value; 
}

void Dfs(Map& node , int deep )//�����������
{ 
    if(deep > MaxDeep )  
        return ; 
    if( true == IsEqual( node , end) ) 
    { 
        Finish = true; 
        Step = deep; 
        return ; 
    } 
    for(int k =0 ;k  < 4 && NOT Finish ; k ++ ) 
    { 
        Map tmp = node ;  
        tmp.x = node.x + derection[k][0], 
        tmp.y = node.y + derection[k][1]; 
  if(tmp.x < 0 || tmp.x > 2 || tmp.y <0 || tmp.y >2 )  
        { 
            continue; 
        } 
        tmp.detail[ node.x ][ node.y ] = tmp.detail[ tmp.x ][ tmp.y ];        //�ƶ��ո� 
        tmp.detail[ tmp.x ][ tmp.y ] = 0 ; 
        int tmpindex = HashValue( tmp ); 
        if(HashTable[ tmpindex ] == true ) 
            continue; 
        HashTable[ tmpindex ] = true; 
        Path[ deep ] = k ;  
        Dfs( tmp , deep + 1) ;  
        HashTable[ tmpindex ] = false; 
    } 
    return ; 
} 

void output()// ��� ���
{ 
    Map now = org ; 
    int oldx,oldy; 
    int count =0 ;  
    printf("����Ҫ %d ��.\n", Step); 
    for(int i =0 ; i < 3; i ++ ) 
    { 
        for(int j =0 ; j < 3; j  ++) 
 { 
            printf("%3d",org.detail[ i ][ j ]); 
        } 
        printf("\n"); 
    } 
    for( int k =0 ; k < Step ; k ++ ) 
    { 
        oldx = now.x , oldy = now.y ;  
        now.x += derection[ Path[ k ] ][ 0 ], now.y += derection[ Path[ k ] ][ 1 ]; 
        now.detail[ oldx ][ oldy ] = now.detail[ now.x ][ now.y ];        //�ƶ��ո� 
        now.detail[ now.x ][ now.y ] = 0 ; 
         
        printf("\n    �� ��%d��\n",++count); 
        getchar(); 
        for(int i =0 ; i < 3; i ++ ) 
        { 
            for(int j =0 ; j < 3; j  ++) 
            { 
                printf("%3d",now.detail[ i ][ j ]); 
            } 
            printf("\n"); 
        } 
    } 
    printf("\nThe End!\n"); 
    return ; 
} 

int main() 
{ 
  input(); 
  HashTable[ HashValue( org ) ] = true; 
  Dfs( org , 0 ); 
  output(); 
  return 0; 
}
