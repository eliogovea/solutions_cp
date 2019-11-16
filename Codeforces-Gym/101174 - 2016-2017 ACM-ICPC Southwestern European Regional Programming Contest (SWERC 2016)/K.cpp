// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

typedef pair<int,int> par;
typedef pair<int,par> tri;

vector<int> g3[MAXN];
vector<int> g2[MAXN];

map<tri,int> dic3;
map<par,int> dic2;

int n3, n2;

int p3[MAXN], p2[MAXN];

int insert3( tri nod ){
    if( !dic3.count(nod) ){
        n3++;
        dic3[ nod ] = n3;
    }

    return dic3[ nod ];
}

int insert2( par nod ){
    if( !dic2.count(nod) ){
        n2++;
        dic2[ nod ] = n2;
    }

    return dic2[ nod ];
}

bool mk3[MAXN], mk2[MAXN];

bool dfs( int u, int p, vector<int> *g, bool *mk , int *pp ){
    if( mk[u] ){
        return true;
    }

    mk[u] = true;
    pp[u] = p;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];

        if( v != p && pp[v] != u ){
            if( dfs( v , u , g , mk , pp ) ){
                return true;
            }
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int m; cin >> m;

    n3 = n2 = 0;

    for( int i = 0; i < m; i++ ){
        int x, y, z, x2, y2, z2; cin >> x >> y >> z >> x2 >> y2 >> z2;

        int u = insert3( tri( x , par( y , z ) ) );
        int v = insert3( tri( x2 , par( y2 , z2 ) ) );

        if( u != v ){
            g3[u].push_back( v );
            g3[v].push_back( u );
        }

        u = insert2( par( x , y ) );
        v = insert2( par( x2 , y2 ) );

        if( u != v ){
            g2[u].push_back( v );
            g2[v].push_back( u );
        }
    }

    bool ok3 = false;
    for( int i = 1; i <= n3 && !ok3; i++ ){
        if( !mk3[i] ){
            ok3 = dfs( i , 0 , g3 , mk3 , p3 );
        }
    }

    bool ok2 = false;

    for( int i = 1; i <= n2 && !ok2; i++ ){
        if( !mk2[i] ){
            ok2 = dfs( i , 0 , g2 , mk2 , p2 );
        }
    }

    if( !ok3 ){
        cout << "No true closed chains\n";
    }
    else{
        cout << "True closed chains\n";
    }

    if( !ok2 ){
        cout << "No floor closed chains\n";
    }
    else{
        cout << "Floor closed chains\n";
    }
}
