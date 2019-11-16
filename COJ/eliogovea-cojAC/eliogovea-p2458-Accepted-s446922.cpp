#include<iostream>
#include<cmath>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    while( n ){
           cout << ceil((-1+sqrt(1+8*n))/2) << endl;
           cin >> n;
           }
    return 0;
    }
