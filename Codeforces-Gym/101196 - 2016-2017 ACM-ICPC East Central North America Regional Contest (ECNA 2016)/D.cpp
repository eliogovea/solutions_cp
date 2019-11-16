// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> par;
typedef pair<ll,par> edge;

const ll oo = ( 1ll << 60ll );
const int MAXN = 110;
const int MAXM = 5000;

par e[MAXM];
edge arcs[MAXM];

vector<int> g[MAXN];
ll d[MAXN];
bool mk[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

    int n, m; cin >> n >> m;
    n++;

    map<string,int> dic;
    dic["English"] = 1;

    for( int i = 2; i <= n; i++ ){
        string x; cin >> x;
        dic[x] = i;
    }

    for( int i = 0; i < m; i++ ){
        string a, b; cin >> a >> b;
        int u = dic[a];
        int v = dic[b];

        ll c; cin >> c;
        e[i] = par( u , v );
        arcs[i] = edge( c , e[i] );
    }

    sort( arcs , arcs + m );

    fill( d , d + n + 1 , oo );
    d[1] = 0;

    for( int i = 1; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            int u = e[j].first;
            int v = e[j].second;

            d[u] = min( d[u] , d[v] + 1ll );
            d[v] = min( d[v] , d[u] + 1ll );
        }
    }

    ll sol = 0ll;
    int cs = 0;

    for( int i = 0; i < m; i++ ){
        int u = arcs[i].second.first;
        int v = arcs[i].second.second;
        ll c = arcs[i].first;

        if( d[u] > d[v] ){
            swap( u , v );
        }

        if( d[u] + 1 == d[v] && !mk[v] ){
            cs++;
            mk[v] = true;
            sol += c;
        }
    }

    if( cs != n-1 ){
        cout << "Impossible\n";
    }
    else{
        cout << sol << '\n';
    }
}