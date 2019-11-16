#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char a[8];
int l,ans;

bool p(int n){
     if(n==1)return 0;
     if(n==2 || n==3)return 1;
     if(n%2==0)return 0;
     for(int i=3; i*i<=n; i+=2)
             if(n%i==0)return 0;
     return 1;
     }

int toint(char x[]){
    int l=strlen(x);
    int r=0;
    for(int i=0; i<l; i++)r=10*r+(x[i]-'0');
    return r;
    }

int main(){
    cin >> a;
    l=strlen(a);
    sort(a,a+l);
    do{
       if(p(toint(a)))ans++;
                }while(next_permutation(a,a+l));
    cout << ans << endl;
    return 0;
    }
