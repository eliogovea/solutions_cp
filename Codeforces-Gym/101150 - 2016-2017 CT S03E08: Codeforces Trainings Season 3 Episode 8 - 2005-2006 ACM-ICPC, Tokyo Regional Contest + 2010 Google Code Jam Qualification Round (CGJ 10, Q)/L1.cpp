// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150L1

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int MAXN = 2000;

ll n, r, k;

ll a[MAXN];
ll suma[MAXN];

ll sum( int i, int j ){
    if( i == 0 ){
        return suma[j];
    }

    return suma[j] - suma[i-1];
}

ll find_sum( int ini, int steps ){
    if( ini + steps <= n ){
        return sum( ini , ini + steps - 1ll );
    }

    ll ret = sum( ini , n-1 );
    steps -= (n - ini);

    ret += suma[n-1] * ( steps / n );
    steps %= n;

    if( steps ){
        ret += suma[steps-1];
    }

    return ret;
}

ll sum_next[MAXN];
ll next[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> r >> k >> n;
    for( int i = 0; i < n; i++ ){
        cin >> a[i];
        suma[i] = a[i];
        if( i > 0 ){
            suma[i] += suma[i-1];
        }
    }

    for( int i = 0; i < n; i++ ){
        int steps = 1;
        int ini = 1;
        int fin = k;

        while( ini <= fin ){
            int mid = ( ini + fin ) / 2;
            ll sum_tmp = 0;
            if( ( sum_tmp = find_sum( i , mid ) ) <= min(k,suma[n-1]) ){
                sum_next[i] = sum_tmp;
                steps = mid;
                ini = mid+1;
            }
            else{
                fin = mid-1;
            }

            next[i] = ( i + steps ) % n;
        }
    }

    int cur = 0;
    ll sol = 0ll;

    for( int i = 0; i < r; i++ ){
        sol += sum_next[cur];
        cur = next[cur];
    }

    cout << sol << '\n';
}
