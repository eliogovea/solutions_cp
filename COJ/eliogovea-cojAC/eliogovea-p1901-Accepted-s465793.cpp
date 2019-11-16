#include<iostream>
using namespace std;

long n,k,t,f,c;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> c;
    while(c--){
               cin >> n >> k >> t >> f;
               cout << n+k*(f-n)/(k-1) << endl;
               }
    return 0;
    }
