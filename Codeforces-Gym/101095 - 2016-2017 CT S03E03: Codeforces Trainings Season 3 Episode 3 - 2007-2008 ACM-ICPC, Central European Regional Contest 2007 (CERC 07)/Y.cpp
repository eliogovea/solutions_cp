// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095Y

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int p[MAXN];
int em[MAXN];
vector<int> p2[MAXN];

int sol[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, t, e; cin >> n >> t >> e;

    for( int i = 1; i <= e; i++ ){
        int h, pp; cin >> h >> pp;
        p[h] += pp;
        em[h]++;
        p2[h].push_back( pp );
    }

    for( int i = 1; i <= n; i++ ){
        if( i == t ){
            continue;
        }

        if( p[i] < em[i] ){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        sort( p2[i].begin() , p2[i].end() , greater<int>() );

        int j = 0;
        while( em[i] > 0 ){
            sol[i]++;
            em[i] -= p2[i][j++];
        }
    }

    for( int i = 1; i <= n; i++ ){
        if( i > 1 ){
            cout << ' ';
        }
        cout << sol[i];
    }
    cout << '\n';
}

