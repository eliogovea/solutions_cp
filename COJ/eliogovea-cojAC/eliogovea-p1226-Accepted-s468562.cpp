#include<iostream>
using namespace std;

unsigned long long n,m,i;

int main(){
    while(cin >> n && n!=-1){
              while(n%2==0){cout << "    "<< 2 << endl; n/=2;}
              for(i=3; i*i<=n; i+=2)while(n%i==0){cout << "    " << i << endl; n/=i;}
              if(n>1)cout  << "    " << n << endl << endl;
              }
    return 0;
    }
