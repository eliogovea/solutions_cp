#include<iostream>
using namespace std;

int p[1000001];
int a,b;

int main(){
    for(int i=2; i<1000002; i++)p[i]=1;
    for(int i=2; i*i<=1000000; i++)
            for(int j=i*i; j<=1000000; j+=i)p[j]=0;
    
    for(int i=3; i<1000001; i++)p[i]+=p[i-1];
    while(cin >> a >> b){
              if(a==0 && b==0)break;
              else cout << p[b]-p[a-1] << endl;
              }
    return 0;
   }
