#include<iostream>
using namespace std;
int main(){
    unsigned long long a,b;
    cin >> a >> b;
    int sol=0;
    unsigned long long c=a;
    while(c){
             unsigned long long  d=b;
             while(d){
                     sol+=(c%10)*(d%10);
                     d=int(d/10); 
                      }
             c=int(c/10);
             }
    cout << sol << endl;
    }