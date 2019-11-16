#include <bits/stdc++.h>

using namespace std;

const int millon = 1000002;
const int MAXN = 300100;
const int MAX = 2000010;

typedef pair<int,int> par;

vector<par> ini[MAX];
vector<par> fin[MAX];

int X1[MAXN], Y1[MAXN], X2[MAXN], Y2[MAXN];

struct menor{
    bool operator () ( const int &aa, const int &bb ) const {
        int a = aa;
        int b = bb;
        if( X1[a] == X1[b] ){
            return Y1[a] < Y1[b];
        }

        bool inv = false;
        if (X1[a] > X1[b]) {
            swap(a, b);
            inv = true;
        }

        int xv1 = X2[a] - X1[a];
        int yv1 = Y2[a] - Y1[a];
        int xv2 = X1[b] - X1[a];
        int yv2 = Y1[b] - Y1[a];
        long long c = (long long)xv1 * yv2 - (long long)xv2 * yv1;
        if (c > 0) {
            return !inv;
        }
        return inv;
    }
};

int getXCAE( int id ){
    if( Y1[id] < Y2[id] ){
        return X1[id];
    }

    return X2[id];
}

int go[MAXN];
int Xgo[MAX];

bool mk[MAXN];
int sol[MAXN];
int solve( int id ){
    if( mk[id] ){
        return sol[id];
    }

    mk[id] = true;
    if( go[id] == 0 ){
        sol[id] = getXCAE(id);
    }
    else{
        sol[id] = solve( go[id] );
    }

    return sol[id];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        X1[i] += millon;
        Y1[i] += millon;
        X2[i] += millon;
        Y2[i] += millon;

        ini[ X1[i] ].push_back( par( Y1[i] , i ) );
        fin[ X2[i] ].push_back( par( Y2[i] , i ) );
    }

    set<int,menor> dic;
    set<int>::iterator it;

    for( int x = 0; x < MAX; x++ ){
        sort( ini[x].begin() , ini[x].end() );
        sort( fin[x].begin() , fin[x].end() , greater<par>() );

        for( int i = 0; i < ini[x].size(); i++ ){
            int id = ini[x][i].second;

            if( Y1[id] < Y2[id] ){//cae en ini
                it = dic.upper_bound( id );
                if( it != dic.begin() ){
                    it--;
                    go[id] = (*it);
                }
            }

            dic.insert(id);
        }

        if( !dic.empty() ){
            Xgo[x] = (*dic.rbegin());
        }

        for( int i = 0; i < fin[x].size(); i++ ){
            int id = fin[x][i].second;

            if( Y1[id] > Y2[id] ){//cae en fin
                it = dic.find( id );
                if( it != dic.begin() ){
                    it--;
                    go[id] = (*it);
                }
            }

            dic.erase(id);
        }
    }

    int m; cin >> m;
    for( int i = 0; i < m; i++ ){
        int x; cin >> x; x += millon;
        if( Xgo[x] == 0 ){
            cout << x - millon << '\n';
        }
        else{
            cout << solve( Xgo[x] ) - millon << '\n';
        }
    }
}
