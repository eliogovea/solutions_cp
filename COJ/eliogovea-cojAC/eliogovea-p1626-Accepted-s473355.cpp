#include<iostream>
using namespace std;

int c;
long long a,b,ra,rb;

int main(){
    cin >> c;
    while(c--){
               ra=rb=0;
               cin >> a >> b;
               while(a){
                        ra=10*ra+a%10;
                        a/=10;
                        }
               while(b){
                        rb=10*rb+b%10;
                        b/=10;
                        }
               ra+=rb;rb=0;
               while(ra){
                         rb=10*rb+ra%10;
                         ra/=10;
                         }
               cout << rb << endl;
               }
    return 0;
    }
