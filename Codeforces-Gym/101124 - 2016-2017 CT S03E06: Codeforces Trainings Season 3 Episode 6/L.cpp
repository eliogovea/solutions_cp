// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124L

#include <bits/stdc++.h>

using namespace std;

const double oo = 1e18;
const int MAXN = 1010;

double g[MAXN][MAXN];

int x[MAXN], y[MAXN];

double dii( int i, int j ){
    double da = x[i] - x[j];
    double db = y[i] - y[j];

    return sqrt( da*da + db*db );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n = 2;
    cin >> x[1] >> y[1] >> x[2] >> y[2];

    n++;
    while( cin >> x[n] >> y[n] ){
        n++;
        while( cin >> x[n] >> y[n] ){
            if( x[n] == -1 ){
                break;
            }

            g[n][n-1] = g[n-1][n] = 60.0 * dii( n , n-1 ) / 40000.0;
            n++;
        }
    }
    n--;

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            if( i != j && g[i][j] == 0.0 ){
                g[i][j] = 60.0 * dii( i , j ) / 10000.0;
            }
        }
    }

    for( int k = 1; k <= n; k++ ){
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= n; j++ ){
                g[i][j] = min( g[i][j] , g[i][k] + g[k][j] );
            }
        }
    }

    cout.precision(0);
    cout << fixed << g[1][2] << '\n';
}
