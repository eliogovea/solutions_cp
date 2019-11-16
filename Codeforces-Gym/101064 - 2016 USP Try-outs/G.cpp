// 2016 USP Try-outs
// 101064G

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200100;

int first[MAXN];
int p[MAXN];
vector<int> g[MAXN];

int x[MAXN];

int sol[MAXN];

bool isq[MAXN];

int nod[MAXN];

void solve( int u, int lev ){
    nod[lev] = x[u];

    sol[u] = nod[first[u]-1];
    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        solve( v , lev+1 );
    }

    nod[lev] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int q; cin >> q;
    first[0] = 1;

    for( int i = 1; i <= q; i++ ){
        char typ; cin >> typ;

        if( typ == 'E' ){
            int u; cin >> u >> x[i];
            p[i] = u;
            g[p[i]].push_back(i);
            first[i] = first[p[i]];
        }
        else{
            int u; cin >> u;
            p[i] = p[u];
            x[i] = x[u];

            g[p[i]].push_back(i);
            first[i] = first[u]+1;
            isq[i] = true;
        }
    }

    solve( 0 , 0 );
    for( int i = 1; i <= q; i++ ){
        if( isq[i] ){
            cout << sol[i] << '\n';
        }
    }
}
