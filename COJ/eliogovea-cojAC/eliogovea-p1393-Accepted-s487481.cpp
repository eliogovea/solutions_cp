#include<iostream>
using namespace std;

long d[94000],carry,i,j,base,expo,top;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> base >> expo;
    d[0]=1;
    for(i=1; i<=expo; i++){
            for(j=0; j<=top; j++){
                    carry/=10;
                    carry+=d[j]*base;
                    d[j]=carry%10;
                    }
            while(carry = carry/10)d[++top]=carry%10;
            }
    for(i=top; i>=0; i--){
               cout << d[i];
               if((top-i+1)%70==0)cout << endl;
               }
    if((top+1)%70!=0)cout << endl;
    return 0;
    }
