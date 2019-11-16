#include<iostream>
using namespace std;
int SL(char *a){
    char *p=a;
    while(*p++);
    return p-a-1;
    }
int main(){
    for(int i=1; i>0; i++){
            char n[1000];
            cin >> n;
            if(n[0]=='0')break;
            else{
            int l=SL(n);
            int c1=0;
            int c2=0;
            for(int j=0; j<l; j+=2)c1+=n[j]-'0';
            for(int k=1; k<l; k+=2)c2+=n[k]-'0';
            if((c1-c2)%11==0)cout << n << " is a multiple of 11.\n";
            else cout << n << " is not a multiple of 11.\n";
            }
            }
    }

