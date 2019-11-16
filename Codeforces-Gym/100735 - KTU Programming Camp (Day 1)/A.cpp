// KTU Programming Camp (Day 1)
// 100735A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 100100ll;

ll l[MAXN];
ll c[MAXN];
ll sol[MAXN];

ll pila[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string s; cin >> s;

    ll n = s.size();

    ll pos = 0ll;

    for(ll i = 0ll; i < n; i++){
        if( i > 0ll ) c[i] = c[i-1ll];

        if( s[i] == '(' ){
            pila[ pos++ ] = i;
        }
        else{
            c[i]++;

            ll k = pila[ --pos ];
            l[k] = (i - k + 1ll);

            if( pos > 0ll ){
                ll t = pila[ pos - 1ll ];

                ll x = (c[i] - c[k]);

                sol[t] += x * ( c[k] - c[t] ) ;

                /*if( t == 0 ){
                    cout << x << ' ' << c[k] - c[t] << '\n';
                }*/
            }
        }
    }

    ll outp = 0ll;

    for(ll i = 0ll; i < n; i++){
        outp += ( l[i] * sol[i] );
        //cout << sol[i] << ' ';
    }
    //cout << '\n';

    cout << outp << '\n';

}
