// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116J

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 400;

par xs[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen( "dat.txt", "r", stdin );

    int tc; cin >> tc;

    while( tc-- ){
        int n; cin >> n;

        for( int i = 0; i < n; i++ ){
            cin >> xs[i].first >> xs[i].second;
        }

        sort( xs , xs + n );

        int sol = 1000000000;

        for( int i = 0; i+n/2 < n; i++ ){
            vector<int> ys;
            for( int j = i; j < n; j++ ){
                ys.push_back( xs[j].second );
                int k = ys.size()-1;
                while( k > 0 && ys[k] < ys[k-1] ){
                    swap( ys[k] , ys[k-1] );
                    k--;
                }

                //sort( ys.begin() , ys.end() );

                for( int b = n/2; b < ys.size(); b++ ){
                    /*cerr << "--------------------------\n";
                    cerr << i << ' ' << j << '\n';
                    cerr << b << '\n';
                    cerr << xs[j].first << ' ' << xs[i].first << " ---- " << ys[b] << ' ' << ys[b-n/2] << '\n';*/
                   // cerr << "--------------------------\n";

                    sol = min( sol , (xs[j].first - xs[i].first) * (ys[b] - ys[b-n/2]) );
                }
            }
        }

        cout << sol << '\n';
    }
}
