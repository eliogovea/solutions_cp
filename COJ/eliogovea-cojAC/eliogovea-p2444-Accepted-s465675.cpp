#include<iostream>
#include<sstream>
using namespace std;


int n,c,x,surv;


int main(){
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin,s);
    istringstream ss(s);
    while( ss>>n ){           
           x=n;c=0;
           while(x){c+=(x&1);x>>=1;}
           if(!(c&1))surv++;
           }
    cout << surv << endl;
    }
