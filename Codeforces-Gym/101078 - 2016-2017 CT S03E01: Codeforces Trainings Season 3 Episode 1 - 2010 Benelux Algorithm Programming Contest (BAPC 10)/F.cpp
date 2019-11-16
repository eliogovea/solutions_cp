// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10010;
const int MAXX = 410;
vector<int> g[MAXN+10];
int mk[MAXX+400][MAXX+400];
int X[MAXN+10], Y[MAXN+10];
int door, NODES;

char opuesto( char a ){
    if( a == 'N' )
        return 'S';
    if( a == 'S' )
        return 'N';
    if( a == 'E' )
        return 'W';
    if( a == 'W' )
        return 'E';
}

pii get_coor( char a ){
    int x, y;
    if( a == 'N' ){
        x = -1;
        y = 0;
    }
    if( a == 'S' ){
        x = +1;
        y = 0;
    }
    if( a == 'E' ){
        y = +1;
        x = 0;
    }
    if( a == 'W' ){
        y = -1;
        x = 0;
    }
    return make_pair( x,y );
}

void dfs( int nod, char p ){
    cout << p << endl;
    string dir;
    cin >> dir;
    if( dir[ dir.size()-1 ] == '*' )
        door = nod;
    for( int i = 0; i < dir.size(); i++ ){
        if( dir[i] == '*' ) continue;
        pii d = get_coor( dir[i] );
        d.first += X[nod];
        d.second+= Y[nod];
        if( !mk[ d.first ][ d.second ] ){
            mk[ d.first ] [ d.second ] = ++NODES;
            g[ nod ].push_back( NODES );
            X[ NODES ] = d.first;
            Y[ NODES ] = d.second;
            dfs( NODES, dir[i] );
        }
        else{
            g[nod].push_back( mk[ d.first ][ d.second ] );
        }
    }
    cout << opuesto( p ) << endl;
    cin >> dir;
}
int d[MAXN+10];

void bfs( int u ){
    queue< int > q;
    q.push( u );
    d[u] = 0;
    while( !q.empty() ){
        u = q.front(); q.pop();
        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];
            if( d[u] +1 < d[v] ){
                d[v] = d[u]+1;
                q.push( v );
            }
        }
    }

}


int main(){
//    freopen("dat.txt","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        for( int i = 0; i < MAXX+1; i++ )
            fill( mk[i], mk[i]+MAXX+1,0 );
        fill( d, d+MAXN+1, 1<<29 );
        for( int i = 1; i <= MAXN; i++ ){
            g[i].clear();
            X[i] = Y[i] = 0;
        }
        NODES = 1;
        door = -1;
        X[1] = MAXX/2;
        Y[1] = MAXX/2;
        mk[ X[1] ][ Y[1] ] = 1;
        string dir;
        cin >> dir;
        if( dir[ dir.size()-1 ] == '*' )
            door = 1;
        for( int i = 0; i < dir.size(); i++ ){
            if( dir[i] == '*' ) continue;
            pii d = get_coor( dir[i] );
            d.first += X[1];
            d.second+= Y[1];
            if( !mk[ d.first ][ d.second ] ){
                mk[ d.first ] [ d.second ] = ++NODES;
                g[ 1 ].push_back( NODES );
                X[ NODES ] = d.first;
                Y[ NODES ] = d.second;
                dfs( NODES, dir[i] );
            }
            else{
                g[1].push_back( mk[ d.first ][ d.second ] );
            }
        }
        if( door != -1 ){
            bfs( 1 );
            cout << d[door] << endl;
        }
        else
            cout << door << endl;
        cin >> dir;
    }
}
