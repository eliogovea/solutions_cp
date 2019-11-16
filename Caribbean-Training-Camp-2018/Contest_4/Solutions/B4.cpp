#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<long double> Complex;
const double PI = acos(-1);

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

vector <int> mul(vector <int> &a, vector <int> & b) {
    vector <int> res(a.size() + b.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            res[i + j] += a[i] * b[j];
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );

    string s;
    cin >> s;

    int n = 1;
    while (n < 2 * s.size() - 1) {
        n <<= 1;
    }
/*
    vector <int> T(n);
    for (int i = 0; i < n; i++) {
        T[i] = s[i] - '0';
    }

    T = mul(T, T);
    for (int i = 0; i < T.size(); i++) {
        cerr << T[i] << " ";
    }
    cerr << "\n";
*/
    vector <Complex> P(n);
    for (int i = 0; i < s.size(); i++) {
        P[i] = (int)(s[i] - '0');
    }

    fft(P, n, 1);
    for (int i = 0; i < n; i++) {
        P[i] *= P[i];
    }
    fft(P, n, -1);

    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ans += ((long long)round(P[2 * i].real()) - 1LL) / 2LL;
        }
    }

    cout << ans << "\n";
}
