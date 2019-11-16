#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<long double> Complex;
const long double PI = acos(-1);

void fft( vector<Complex> &a, int n, int dir ){

    int lg = 0;
    while( n > (1<<lg) ) lg++;

    assert( n == (1<<lg) );

    for( int i = 0; i < n; i++ ){
        int pos = 0;
        for( int j = 0; j < lg; j++ ){
            pos <<= 1;
            pos |= (i>>j) & 1;
        }

        if( i < pos ){
            swap( a[i], a[pos] );
        }
    }

    for( int i = 1; i <= lg; i++ ){

        int m = 1<<i;
        int k = m>>1;
        Complex w, wn, u, t;
        wn = Complex( cos( (long double)dir*2.0*PI/(long double)m), sin( (long double)dir*2.0*PI/(long double)m ) );

        for( int j = 0; j < n; j += m ){
            w = Complex( 1.0, 0.0 );
            for( int l = j; l < j+k; l++ ){
                t = w*a[l+k];
                u = a[l];
                a[l] = u + t;
                a[l+k] = u - t;
                w *= wn;
            }
        }

    }
    if( dir == -1 ){
        for( int i = 0; i < n; i++ ){
            a[i] /= (long double)n;

        }

    }

}

inline int power(int x, int n, int m) {
    int y = 1 % m;
    while (n) {
        if (n & 1) {
            y = (long long)y * x % m;
        }
        x = (long long)x * x % m;
        n >>= 1;
    }
    return y;
}

int B = 1000;
int D = 2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );

    int n, m;
    cin >> n >> m;

    vector <int> f(m);
    for (int x = 1; x < m; x++) {
        f[power(x, n, m)]++;
    }


    vector <int> g(m);
    for (int x = 1; x < m; x++) {
        g[(2 * power(x, n, m)) % m]++;
    }

    int l = 1;
    while (l < m + m - 1) {
        l <<= 1;
    }

    vector <Complex> P(l);
    for (int i = 0; i < m; i++) {
        P[i] = f[i];
    }

    fft(P, l, 1);
    for (int i = 0; i < l; i++) {
        P[i] *= P[i];
    }
    fft(P, l, -1);

    vector <long long> ff(l);
    for (int i = 0; i < l; i++) {
        ff[i] = round(P[i].real());
    }

    for (int i = m; i < l; i++) {
        ff[i - m] += ff[i];
    }

    long long ans = 0;

    for (int i = 0; i < m; i++) {
        long long x = (ff[i] + (long long)g[i]) / 2LL;
        ans += (long long)x * f[i];
    }

    cout << ans << "\n";

}
