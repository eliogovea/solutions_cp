#include<iostream>
using namespace std;

int n,mx,mn,s,x;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++){
            mx=0;mn=101;s=0;
            for(int j=0; j<10; j++){cin >> x; s+=x; if(mx<x)mx=x; if(mn>x)mn=x;}
            cout << i+1 << " " <<  s-mx-mn << endl;
            }
    return 0;
    }
