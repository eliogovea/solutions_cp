// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174C

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

    int d, r, t;
    cin >> d >> r >> t;
    int ar = 4;
    int cr = 4;
    int at = ar - d;
    int ct = at == 3 ? 3 : 0;
    while (cr <= r) {
        int x = r - cr;
        if (t + x == ct) {
            cout << x << "\n";
            return 0;
        }
        ar++;
        cr += ar;
        at++;
        if (at >= 3) {
            ct += at;
        }
    }
    return 0;
}
