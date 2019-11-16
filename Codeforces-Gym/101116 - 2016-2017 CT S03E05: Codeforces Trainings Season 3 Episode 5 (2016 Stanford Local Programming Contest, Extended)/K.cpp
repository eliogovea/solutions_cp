// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];

int solve( int u ){
    int sol = (int)g[u].size() + 1;

    vector<int> hs;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        hs.push_back( solve( v ) );
    }

    sort( hs.begin() , hs.end() , greater<int>() );

    for( int i = 0; i < hs.size(); i++ ){
        sol = max( sol , hs[i] + i );
    }

    return sol;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen( "dat.txt", "r", stdin );

    int n; cin >> n;

    map<string,int> dic;
    int sz = 0;

    for( int i = 1; i <= n; i++ ){
        string tmp; cin >> tmp;
        if( !dic[tmp] ){
            ++sz;
            dic[tmp] = sz;
        }

        int u = dic[tmp];

        int m; cin >> m;
        for( int j = 0; j < m; j++ ){
            cin >> tmp;
            if( tmp[0] < 'A' || tmp[0] > 'Z' ){
                continue;
            }

            if( !dic[tmp] ){
                ++sz;
                dic[tmp] = sz;
            }
            int v = dic[tmp];

            g[u].push_back(v);
        }
    }

    cout << solve(1) << '\n';
}
