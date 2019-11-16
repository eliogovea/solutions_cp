#include<iostream>
#include<cstdio>
using namespace std;

const int c[5]={1,5,10,25,50};
long w[7490],n;

int main(){
    w[0]=1;
    for(int i=0; i<5; i++)
    for(int j=c[i]; j<=7498; j++)w[j]+=w[j-c[i]];
    
    while(scanf("%d",&n)!=EOF)printf("%d\n",w[n]);
    }
