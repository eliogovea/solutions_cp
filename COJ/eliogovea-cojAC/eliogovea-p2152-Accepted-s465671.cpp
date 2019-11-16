#include<iostream>
#include<cstring>

using namespace std;
int n,suma;
char c[25];
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    while(n--){
               cin >> c;
               suma=0;
               if(c[0]=='-')for(int i=1; i<strlen(c); i++)suma+=c[i]-'0';
               else for(int i=0; i<strlen(c); i++)suma+=c[i]-'0';
               cout << suma << endl;
               }
    return 0;
    }
