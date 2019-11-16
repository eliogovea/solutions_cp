// 2013-2014 Wide-Siberian Olympiad: Onsite round
// 10124105

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, l;
int m[1000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    cin >> n >> l;
    for( int i = 0,x; i < n; i++ ){
        cin >> x;
        m[x]++;
    }
    bool f = true;
    for( int i = 1; i <= 100010 && f; i++ ){
        if( m[i]%l ){
            f = false;
        }
    }

    if( f )
        cout << "OK\n";
    else
        cout << "ARGH!!1\n";
}
