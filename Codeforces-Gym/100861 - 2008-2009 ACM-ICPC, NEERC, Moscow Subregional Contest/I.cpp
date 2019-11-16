// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861I

#include <bits/stdc++.h>

using namespace std;

const int MAXX = 10005;
const int MAXN = 1010;

int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

vector<int> inix[MAXX];
vector<int> iniy[MAXX];

int sol[MAXX];

bool solv( int len, vector<int> *ini, int *L, int z1, int z2 ){
    if( z1 == z2 ){
        return false;
    }

    fill( sol , sol + len + 1 , 0 );

    if( z1 > z2 ){
        swap(z1 , z2);
    }

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int X, Y; cin >> X >> Y;

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        inix[ x2[i] ].push_back( i );
        iniy[ y2[i] ].push_back( i );
    }

    int a, b; cin >> a >> b;

    inix[ x2[a] ].clear();
    iniy[ y2[a] ].clear();
    inix[ x2[b] ].clear();
    iniy[ y2[b] ].clear();

    inix[ x2[a] ].push_back( a );
    iniy[ y2[a] ].push_back( a );
    inix[ x2[b] ].push_back( b );
    iniy[ y2[b] ].push_back( b );

    int len = 0;
    int *L;

    if( solv( X , inix , x1 , x2[a] , x2[b] ) ){
        len = X;
        L = x1;
    }
    else if( solv( Y , iniy , y1 , y2[a] , y2[b] ) ){
        len = Y;
        L = y1;
    }

    if( !len ){
        cout << "-1\n";
    }
    else{
        vector<int> ans;
        while( len ){
            ans.push_back( sol[len] );
            len = L[ sol[len] ];
        }

        reverse( ans.begin() , ans.end() );

        cout << ans.size() << '\n';
        for( int i = 0; i < ans.size(); i++ ){
            cout << ans[i] << " \n"[i+1==ans.size()];
        }
    }
}
