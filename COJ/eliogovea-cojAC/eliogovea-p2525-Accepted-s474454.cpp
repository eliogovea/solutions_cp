#include<iostream>
using namespace std;

bool b[10001];
int n,r,x;

int main(){
    while(cin >> n >> r){
              for(int i=1; i<=r; i++){
                           cin >> x;
                           b[x]=1;
                           }
              if(n==r)cout << "*" << endl;
              else{                   
                   for(int i=1; i<=n; i++)if(!b[i])cout << i << " ";
                   cout << endl;
                   }
                   
              for(int i=1; i<=n; i++)b[i]=0;
              }
    return 0;
    }
