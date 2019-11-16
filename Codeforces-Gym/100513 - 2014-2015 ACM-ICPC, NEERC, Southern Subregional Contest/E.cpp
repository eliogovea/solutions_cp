// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513E

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 200100;

int a[MAXN], b[MAXN];
int r[MAXN];

bool mk[MAXN];

int tot;

bool ok( int i ){
    if( r[i] != 1 && r[i+1] != 1 ){
        return true;
    }

    return a[i] + a[i+1] > b[i] + b[i+1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n; cin >> n;

    int A = 0;

    for( int i = 1; i <= n; i++ ){
        cin >> a[i] >> b[i];

        if( a[i] == b[i] ){
            r[i] = 0;
        }
        else if( a[i] > b[i] ){
            r[i] = 1;
            A++;
        }
        else{
            r[i] = -1;
        }
    }

    tot = n;

    vector<par> sol;

    for( int i = 1; i < n && A*2 <= tot; i++ ){
        if( mk[i] || mk[i+1] ){
            continue;
        }

        if( (r[i] != 1 || r[i+1] != 1) && ok(i) ){
            mk[i] = mk[i+1] = true;
            tot--;
            sol.push_back( par( i , i+1 ) );
        }
    }

    if( A*2 <= tot ){
        cout << "-1\n";
        return 0;
    }

    cout << sol.size() << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i].first << ' ' << sol[i].second << '\n';
    }
}
