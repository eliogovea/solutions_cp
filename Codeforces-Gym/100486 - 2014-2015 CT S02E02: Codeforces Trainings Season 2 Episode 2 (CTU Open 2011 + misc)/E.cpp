// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486E

#include<bits/stdc++.h>
#include<cmath>
#include<math.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> par;
const int MAXN = 50100;
const int oo = 1<<30;

priority_queue<par, vector<par>, greater<par> > q;
vector<par> g[MAXN];
int n,m,k,a;

int d[MAXN], sol, mk[MAXN];
void dijkstra( int );
bool f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen( "data.txt", "r", stdin );

    while( cin >> n >> m >> a >> k ){
        if( !n && !m && !k && !a )
            break;
        if( f ) cout << "\n";
        f = true;
        //cout << "ok" << endl;
        sol = 0;
        for( int i = 1; i <= n; i++ ){
            g[i].clear();
            d[i] = oo;
            mk[i] = false;
        }

        for( int i = 1,x,y,z; i <= m; i++ ){
            cin >> x >> y >> z;
            g[x].push_back( make_pair(z,y) );
            g[y].push_back( make_pair(z,x) );
        }
        for( int i = 1,u; i <= a ; i++ ){
            cin >> u;
            dijkstra( u );
            cout << n-sol << '\n';
        }
    }


}


void dijkstra( int start ){
    d[start] = 0;
    q.push( make_pair(0,start) );

    while( !q.empty() ){
        int nod = q.top().second,
            cost = q.top().first;
        q.pop();
        if( !mk[nod] ){
            mk[nod] = true;
            sol++;
        }
        for( int i = 0; i < g[nod].size(); i++ ){
            int nex = g[nod][i].second,
                nc = g[nod][i].first;

            if( k > d[ nod ] + nc && d[ nex ] > d[ nod ] + nc ){
                d[ nex ] = d[nod] + nc;
                q.push( make_pair( d[nex], nex ) );
            }

        }

    }

}

