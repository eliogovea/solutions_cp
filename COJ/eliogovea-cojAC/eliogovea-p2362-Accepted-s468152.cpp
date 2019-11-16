#include<cstdio>
#include<iostream>
using namespace std;

int n;
long long m;

int main(){
    scanf("%d",&n);
    while(n--){
               scanf("%d",&m);
               cout << 2*m*(m-1)+1 << endl;
               }
    return 0;
    }
