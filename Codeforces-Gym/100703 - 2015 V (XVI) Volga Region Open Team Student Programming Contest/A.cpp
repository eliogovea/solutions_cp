// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703A

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
typedef long long ll;
typedef pair<double,int> pdi;
typedef tuple<int,int,int> edge;
int distan( const string &a, const string &b ){
    int res = 0;
    for( int i = 0; i < a.size(); i++ )
        res = max(res, abs( a[i]-b[i] ));
    return res;
}
int P[MAXN*MAXN],
    ran[MAXN*MAXN];
void makeSet( int x ){
    P[x] = x;
    ran[x] = 1;
}
int findSet( int x ){
    if( P[x] != x )
        return P[x] = findSet( P[x] );
    return P[x];
}

bool joinSet( int x, int y ){
    int px = findSet(x),
        py = findSet(y);
    if( px == py )
        return false;

    if( ran[px] > ran[py] ){
        P[py] = px;
        ran[px] += ran[py];
    }
    else{
        P[px] = py;
        ran[py] += ran[px];
    }
    return true;
}

int n, l;
string nod[MAXN];
vector<edge> e;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///freopen("data.txt", "r",stdin);
    cin >> n >> l;
    for( int i = 1; i <= n; i++ ){
        cin >> nod[i];
        makeSet( i );
        }

    for( int i = 1; i <= n; i++ )
        for( int j = i+1; j <= n; j++ ){
            int dist = distan( nod[i], nod[j] );
            e.emplace_back( dist, i, j );
            //cout << i << " " << j << " " << dist << endl;
        }
    sort( e.begin(), e.end() );
    int sol = 0;

    for( int i = 0; i < e.size(); i++ ){
        if( joinSet( get<1>(e[i]), get<2>(e[i]) ) ){
            sol = get<0>(e[i]);
            n--;
            if( n==1 )
                break;
        }

    }
    cout << sol << endl;

}
