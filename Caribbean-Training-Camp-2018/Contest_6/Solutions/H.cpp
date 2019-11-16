#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1000100;

ll c1[MAXN], c2[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 0; i < n; i++ ){
        int x; cin >> x;
        c2[x]++;
    }
    for( int i = 0; i < m; i++ ){
        int x; cin >> x;
        c1[x]++;
    }

    ll tot = 0;

    for( int i = 1; i <= 1000000; i++ ){
        for( int j = i; j <= 1000000; j+=i ){
            tot += c1[i] * c2[j] * (j/i);
        }
    }

    cout << tot << '\n';
}
