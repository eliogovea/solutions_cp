#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50100;
const int ro = 250;

typedef long long ll;

int a[MAXN];
int v[MAXN];

typedef pair<int,int> par;

par x[MAXN];
ll sum[MAXN];

int n;

void upd_sqrt( int l ){
    int i = (l+ro-1) / ro;
    int j = (i*ro);
    i = j - ro + 1;
    j = min( j , n );

    for( int k = i; k <= j; k++ ){
        if( x[k].second == l ){
            x[k].first = a[l];
            break;
        }
    }

    sort( x + i, x + j + 1 );

    for( int k = i; k <= j; k++ ){
        sum[k] = v[ x[k].second ];
        if( k > i ){
            sum[k] += sum[k-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;

    map<int,int> dic;
    unordered_map<int, set<int> > pos;

    for( int i = 1; i <= n; i++ ){
        cin >> v[i];
        a[i] = dic[ v[i] ];
        pos[ v[i] ].insert(i);
        dic[ v[i] ] = i;
    }

    for( int i = 1, ini = i; i <= n; i++ ){
        x[i] = par( a[i] , i );
        if( i % ro == 0 ){
            sort( x + ini, x + i + 1 );
            for( int j = ini; j <= i; j++ ){
                sum[j] = v[ x[j].second ];
                if( j > ini ) sum[j] += sum[j-1];
            }
            ini = i+1;
        }
    }

    int m; cin >> m;

    while( m-- ){
        char t; cin >> t;
        if( t == 'U' ){
            int l, c; cin >> l >> c;
            if( v[l] == c ) continue;

            auto it = pos[ v[l] ].find(l);
            if( it != pos[ v[l] ].end() ){
                it++;
                if( it != pos[ v[l] ].end() ){
                    a[*it] = a[l];
                    upd_sqrt( *it );
                }
                it--;
            }
            pos[ v[l] ].erase(l);

            v[l] = c;
            pos[ v[l] ].insert(l);
            it = pos[ v[l] ].find(l);
            if( it != pos[ v[l] ].end() ){
                it++;
                if( it != pos[ v[l] ].end() ){
                    a[*it] = l;
                    upd_sqrt( *it );
                }
                it--;
            }

            a[l] = 0;
            if( it != pos[ v[l] ].begin() ){
                it--;
                a[l] = *it;
            }
            upd_sqrt( l );
        }
        else{
            ll sol = 0ll;

            int l, r; cin >> l >> r;
            for( int i = 1; i <= n; i += ro ){
                int j = min( n , i + ro - 1 );

                if( l <= i && j <= r ){
                    //cerr << "--->\n";
                    int p = lower_bound( x + i , x + j + 1 , par( l , 0 ) ) - x;
                    p--;
                    if( p >= i ){
                        sol += sum[p];
                    }
                }
                else if( j < l || r < i ){
                    //cerr << "--->2\n";
                    continue;
                }
                else{
                    for( int k = i; k <= j; k++ ){
                        //cerr << x[k].second << "  --> " << x[k].first << '\n';
                        if( l <= x[k].second && x[k].second <= r && x[k].first < l ){
                            sol += v[ x[k].second ];
                        }
                    }
                }
            }

            cout << sol << '\n';
        }
    }
}
