#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char a[100][100],s[1000000];
int n,k;

int main(){
    cin >> n;
    while(n--){
               cin >> s;
               k=0;
               int l=strlen(s),sl=(int)sqrt(l);
               
               for(int i=sl-1; i>=0; i--)
               for(int j=i; j<l; j+=sl)cout << s[j];
               
               cout << endl;
               }
    return 0;
    }
