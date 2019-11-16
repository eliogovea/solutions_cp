// KTU Programming Camp (Day 2)
// 100738B

#include<bits/stdc++.h>
#define MAXN 18
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vi::iterator viit;
typedef vi::reverse_iterator virit;
const ull M = 1000000000ull;
ull n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    //freopen( "d.txt", "r", stdin );
    cin >> n;
    ull a = 0, sol = 0;
    do{
        a = (n/2)*( n/2 + (n&1) );
        if( a <= n ){
            cout << "-1\n";
            return 0;
        }
        n = a;
        sol++;
    }while( n < M );

    cout << sol << "\n";

}
