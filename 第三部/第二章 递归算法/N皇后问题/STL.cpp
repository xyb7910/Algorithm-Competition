#include<bits/stdc++.h> //N»ÊºóÎÊÌâ 
int n,Max,i,sum,a[12]={1,2,3,4,5,6,7,8,9,10,11,12};
int main(){
  std::cin>>n;	
  while(std::next_permutation(a,a+n)){
	int x1[80]={0},y1[80]={0};
  	for(Max=0,i=0;i<n;Max=std::max(std::max(Max,++x1[i+a[i]]),++y1[i-a[i]+n]),i++);
    sum=(Max>1)?sum:++sum;
  }
  std::cout<<sum<<'\n';
}
