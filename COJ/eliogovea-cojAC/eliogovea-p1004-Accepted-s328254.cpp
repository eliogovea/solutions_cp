#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int r=1; r<=n; r++){
            int n,m;
            cin >> n >> m;
            if(n==m && n%2==0) cout << "L\n";
            if(n==m && n%2!=0) cout << "R\n";
            if(n>m && m%2==0) cout << "U\n";
            if(n>m && m%2==1 ) cout << "D\n";
            if(n<m && n%2==0) cout << "L\n";
            if(n<m && n%2==1) cout << "R\n";
            }
return 0;
    }
