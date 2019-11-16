#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    unsigned int digits[200];
    digits[0]=1;
    int i,j;
    int top=0;
    int carry=0;
    for(i=1; i<=n; i++){
             for(j=0; j<=top; j++){
                      carry/=10;
                      carry+=digits[j]*2;
                      digits[j]=carry%10;
                      }
             while(carry=carry/10)
             digits[++top]=carry%10;
             }
    for(i=top; i>=0; i--)cout << digits[i];
    }