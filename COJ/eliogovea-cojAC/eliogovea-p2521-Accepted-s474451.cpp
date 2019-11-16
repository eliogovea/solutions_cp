#include<iostream>
using namespace std;

char a,b,c;

int main(){
    while(cin >> a >> b >> c){
              if(a==b && a!=c)cout << "C" << endl;
              else if(a==c && a!=b)cout << "B" << endl;
              else if(b==c && b!=a)cout << "A" << endl;
              else if(a==b && b==c)cout << "*" << endl;
              }
    return 0;
    }
