// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

bool v[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n, f; cin >> n >> f;

    vector<int> x( n , 0 );
    for( int i = 0; i < n; i++ ){
        cin >> x[i];
        v[ x[i] ] = true;
    }

    vector<int> sol;

    for( int i = 0; i < n; i++ ){
        if( !v[ x[i] ] ){
            continue;
        }

        if( f < x[i] ){
            while( f < x[i] ){
                if( v[f] ){
                    sol.push_back( f );
                }
                v[f] = false;
                f++;
            }
            if( v[f] ){
                sol.push_back( f );
            }
            v[f] = false;
        }
        else{
            while( f > x[i] ){
                if( v[f] ){
                    sol.push_back( f );
                }
                v[f] = false;
                f--;
            }
            if( v[f] ){
                sol.push_back( f );
            }
            v[f] = false;
        }
    }

    for( int i = 0; i < n; i++ ){
        cout << sol[i] << " \n"[i+1==n];
    }
}
