#include<iostream>
using namespace std;

double a,x,y,sol;

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> a >> x >> y ){
              sol=x*a/(2.0*(x+y));
              if(sol-int(sol)>=0.5)cout << int(sol)+1 << endl;
              else cout << int(sol) << endl;
              }
    return 0;
    }
