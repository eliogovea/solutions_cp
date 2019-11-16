// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572J

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int a, b; cin >> a >> b;

    if( a + b == 0 ){
        cout << "Not a moose\n";
    }
    else{
        cout << ( a == b ? "Even " : "Odd " ) << max( a , b ) * 2 << '\n';
    }
}
