// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116E

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;
map<string, int> NodId;
int NODES;
int st, en, m;
vector<int> start, check;
vector<int> g[4*MAXN];
string word[4*MAXN];
bool mk[4*10100];

void dfs( int u ){
    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !mk[v] )
            dfs( v );
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen( "dat.txt", "r", stdin );
    int tc;
    cin  >> tc;
    while( tc-- ){
        NODES = 0;


        cin >> st >> en >> m;
        string name;
        for( int i = 0; i < st; i++ ){
            cin >> name;
            int x = NodId[name];
            if( !x )
                x = NodId[name] = ++NODES;
            word[x] = name;
            start.push_back( x );
        }
        for( int i = 0; i < en; i++ ){
            cin >> name;
            int x = NodId[name];
            if( !x )
                x = NodId[name] = ++NODES;
            word[x] = name;
            check.push_back(x);

        }
        string name2;
        for( int i = 0; i < m; i++ ){
            cin >> name >> name2;
            int x = NodId[name],
                y = NodId[name2];
            if( !x )
                x = NodId[name] = ++NODES;
            word[x] = name;
            if( !y )
                y = NodId[name2] = ++NODES;
            word[y] = name2;
            g[ x ].push_back(y);
        }
        for( int i = 0; i < start.size(); i++ )
            if( !mk[ start[i] ] )
                dfs( start[i] );
        vector<string> sol;
        for( int i = 0; i < check.size(); i++ ){
            if( mk[ check[i] ] )
                sol.push_back( word[ check[i] ] );
        }
        sort( sol.begin(), sol.end() );
        for( int i = 0; i < sol.size(); i++ )
            cout << sol[i] << " \n"[ i+1 == sol.size()];

        start.clear();
        check.clear();
        NodId.clear();
        fill( mk, mk+NODES+1, false );

        for( int i = 0; i < NODES + 10; i++ ){
            g[i].clear();
        }
    }
}
