// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196I

#include <bits/stdc++.h>

using namespace std;

const int oo = ( 1 << 29 );
const int MAXN = 500;
const int MAXM = 100100;

int n, s, t, E;
int ady[MAXM], next[MAXM], cap[MAXM], flow[MAXM];
int last[MAXN], now[MAXN];

void init_MAXFLOW( int _n , int _s , int _t ){
    E = 2;
    n = _n;
    s = _s;
    t = _t;

    for( int i = 0; i <= n; i++ ){
        last[i] = 0;
    }
}

void add_edge( int u, int v, int c ){
    ady[E] = v; cap[E] = c; flow[E] = 0; next[E] = last[u]; last[u] = E++;
    ady[E] = u; cap[E] = 0; flow[E] = 0; next[E] = last[v]; last[v] = E++;
}

int d[MAXN];
bool bfs(){
    for( int i = 1; i <= n; i++ ){
        d[i] = 0;
    }
    d[s] = 1;
    queue<int> q;
    q.push( s );

    while( !q.empty() ){
        int u = q.front(); q.pop();
        for( int e = last[u]; e; e = next[e] ){
            int v = ady[e];
            if( !d[v] && flow[e] < cap[e] ){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    return d[t] > 0;
}

int dfs( int u, int FLOW ){
    if( u == t ){
        return FLOW;
    }

    for( int e = now[u], f; e; e = now[u] = next[e] ){
        int v = ady[e];
        if( d[u] + 1 == d[v] && flow[e] < cap[e] ){
            if( (f = dfs( v , min( FLOW , cap[e] - flow[e] ))) ){
                flow[e] += f;
                flow[e^1] -= f;
                return f;
            }
        }
    }

    return 0;
}

int MAXFLOW(){
    int flow = 0, f = 0;

    while( bfs() ){
        for( int i = 0; i <= n; i++ ){
            now[i] = last[i];
        }

        while( (f = dfs( s , oo )) ){
            flow += f;
        }
    }

    return flow;
}


bool kk[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

    int boys, toys, cats; cin >> boys >> toys >> cats;
    cats++;

    int n = boys + toys + cats + 2;
    int s = boys + toys + cats + 1;
    int t = boys + toys + cats + 2;

    init_MAXFLOW( n, s, t );

    for( int bi = 1; bi <= boys; bi++ ){
        add_edge( s , bi , 1 );

        int ki; cin >> ki;

        for( int i = 0; i < ki; i++ ){
            int ti; cin >> ti;

            add_edge( bi , boys + ti , 1 );
        }
    }

    for( int ci = 1; ci <= cats; ci++ ){
        int r = oo;

        if( ci == cats ){
            for( int ti = 1; ti <= toys; ti++ ){
                if( !kk[ti] ){
                    add_edge( boys + ti , boys + toys + ci , 1 );
                }
            }
        }
        else{
            int ki; cin >> ki;
            for( int i = 0; i < ki; i++ ){
                int ti; cin >> ti;
                kk[ti] = true;

                add_edge( boys + ti , boys + toys + ci , 1 );
            }

            cin >> r;
        }

        add_edge( boys + toys + ci , t , r );
    }

    cout << MAXFLOW() << '\n';
}
