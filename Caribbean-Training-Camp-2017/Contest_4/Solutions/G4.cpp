#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int from[MAXN];
bool mk[MAXN];
vector<int> g[MAXN];

int id1[MAXN];
int id2[MAXN];
bool ok[MAXN];

bool dfs( int u ){
    if( mk[u] || !ok[ id1[u] ] ){
        return false;
    }

    mk[u] = true;
    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( ok[ id2[v] ] && (!from[v] || dfs( from[v] )) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

int n, m;
int kuhn(){
    fill( from , from + m + 1 , 0 );

    int mxf = 0;
    for( int i = 1; i <= n; i++ ){
        fill( mk , mk + n + 1 , false );
        if( dfs(i) ){
            mxf++;
        }
    }

    return mxf;
}

char y[MAXN];
int nod[MAXN];
vector<int> G2[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    string s;
    int k; cin >> k;
    getline(cin,s);

    n = m = 0;

    for( int i = 1; i <= k; i++ ){
        getline( cin , s );
        stringstream sin(s);

        sin >> y[i];
        if( y[i] == 'Y' ){
            nod[i] = ++n;
            id1[ nod[i] ] = i;
        }
        else{
            nod[i] = ++m;
            id2[ nod[i] ] = i;
        }

        int j;
        while( sin >> j ){
            G2[i].push_back(j);
        }
    }

    for( int i = 1; i <= k; i++ ){
        for( int e = 0; e < G2[i].size(); e++ ){
            int j = G2[i][e];

            if( y[i] == y[j] ){
                continue;
            }

            int u = nod[i];
            int v = nod[j];

            if( y[i] == 'N' ){
                swap( u , v );
            }

            g[u].push_back(v);
        }
    }

    fill( ok , ok + k + 1 , true );

    int mxf = kuhn();
    cout << mxf << '\n';
    if( !mxf ){
        return 0;
    }

    vector<int> sol;

    for( int i = 1; i <= k && mxf; i++ ){
        ok[i] = false;
        if( kuhn() == mxf - 1 ){
            sol.push_back(i);
            mxf--;
        }
        else{
            ok[i] = true;
        }
    }

    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i] << " \n"[i+1==sol.size()];
    }
}
