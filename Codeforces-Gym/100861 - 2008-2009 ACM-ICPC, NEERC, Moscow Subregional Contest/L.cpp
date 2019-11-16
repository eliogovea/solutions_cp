// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861L

#include <bits/stdc++.h>

using namespace std;

const int MAXX = 10005;
const int MAXN = 1010;

int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

vector<int> inix[MAXX];
vector<int> iniy[MAXX];

int sol[MAXX];

bool solv( int len, vector<int> *ini, int *L, int z1, int z2 ){
    fill( sol , sol + len + 1 , 0 );

    int z = 0;

    for( int i = 1; i <= len; i++ ){
        for( int j = 0; j < ini[i].size(); j++ ){
            int id = ini[i][j];
            int l = L[id];

            if( l < z ){
                continue;
            }

            if( l == 0 || sol[l] > 0 ){
                sol[i] = id;
                break;
            }
        }

        if( i >= z1 ){
            z = z1;
        }
        if( i >= z2 ){
            z = z2;
        }
    }

    return sol[len];
}

void solveL() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cout << "9";
    }
    cout << "8";
    for (int i = 0; i < n; i++) {
        cout << "9";
    }
    cout << "\n";
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << "9";
    }
    cout << "8";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    solveL(); return 0;

    int X, Y; cin >> X >> Y;

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        inix[ x2[i] ].push_back( x1[i] );
        iniy[ y2[i] ].push_back( y1[i] );
    }

    int a, b; cin >> a >> b;
}
