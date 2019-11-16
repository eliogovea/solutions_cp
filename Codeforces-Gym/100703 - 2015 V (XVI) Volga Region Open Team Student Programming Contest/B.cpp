// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703B

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int x[MAXN];
int s[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 0; i < n; i++ ){
        cin >> x[i];
        s[i] = x[i];

        if( i > 0 ){
            s[i] += s[i-1];
        }
    }

    int q; cin >> q;

    int mx = s[n-1] / m;
    if( s[n-1] % m != 0 ){
        mx++;
    }

    while( q-- ){
        int c; cin >> c;

        c = min( c , mx );
        int tot = c * m;

        int a = upper_bound( s , s + n , tot ) - s;
        if( a == n ){
            cout << n << ' ' << tot - s[n-1] << '\n';
        }
        else{
            cout << a << ' ' << tot - s[a-1] << '\n';
        }
        //cout << tot << ' ' << s[a-1] << ' ' << a << "-----\n";
    }
}
