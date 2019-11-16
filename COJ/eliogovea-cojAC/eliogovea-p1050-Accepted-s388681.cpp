#include<iostream>
using namespace std;
int mcd(long n, long m){    
    if(m==0) return n;
    else return mcd(m,n%m);
    }

int main(){
     int n,c;
     cin >> n;
     c=1;
     for(int i=2; i<n; i++){
     if(mcd(i,n)==1) c++;}
     cout << c;
     }