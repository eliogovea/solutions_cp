#include<iostream>
using namespace std;

int n,t,c,x;

int main(){
    cin >> n;
    while(n--){
               cin >> c;
               t=-c+1;
               while(c--){cin >> x; t+=x;}
               cout << t << endl;
               }
    return 0;
    }
