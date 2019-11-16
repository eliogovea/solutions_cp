// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116B

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;

string s[MAXN];
int r[MAXN], c[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int tc; cin >> tc;

    while( tc-- ){
        int n, m; cin >> n >> m;

        for( int i = 0; i < n; i++ ){
            cin >> s[i];
            reverse( s[i].begin() , s[i].end() );
        }

        int sol = 0;

        for( int i = 0; i < n; i++ ){
            r[i] = 0;
        }

        for( int j = 0; j < m; j++ ){
            c[j] = 0;
        }

        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                int x = s[i][j] - '0';
                int cnt = r[i] + c[j];

                if( cnt & 1 ){
                    x ^= 1;
                }

                if( !x ){
                    sol++;
                    r[i]++;
                    c[j]++;
                }
            }
        }

        cout << sol << '\n';
    }
}
