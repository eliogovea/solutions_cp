// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150B

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int MAXM = 15;
const int MAXN = 200;
const int MAXK = 60;

int m , c , n;
int ki[MAXN];
vector<int> request[MAXN];
int pos_request[MAXN];

set<int> D[MAXN];

map<int,int> last;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    while(cin >> m >> c >> n, ( n && m && c ) ){
        last.clear();
        for( int i = 1; i <= m+1; i++ ){
            D[i].clear();
        }
        for( int i = 0; i < n; i++ ){
            cin >> ki[i];

            request[i].clear();
            pos_request[i] = 0;

            for( int j = 0; j < ki[i]; j++ ){
                int bij; cin >> bij;
                request[i].push_back( bij );

                D[m+1].insert( bij );
                last[ bij ] = 0;
            }
        }

        ll sol = 0ll;

        int ind = 0;

        int time = 0;

        while( true ){ time++;
            int tmp = ind;

            int cc = 0;
            while( cc < n+2 ){
                if( pos_request[tmp] < ki[tmp] ){
                    break;
                }

                tmp = ( tmp + 1 ) % n;
                cc++;
            }

            if( pos_request[tmp] == ki[tmp] ){
                break;
            }

            int bij = request[tmp][ pos_request[tmp]++ ];
            last[ bij ] = time;

            ind = ( tmp + 1 ) % n;

            for( int i = 1; i <= m+1; i++ ){
                if( D[i].find( bij ) != D[i].end() ){
                    sol += i;
                    D[i].erase( bij );
                    break;
                }
            }

            if( D[1].size() < c ){
                D[1].insert( bij );
                sol += 1;
                continue;
            }

            int pos_m = -1;
            for( int i = 2; i <= m+1; i++ ){
                if( D[i].size() < c || i == m+1 ){
                    pos_m = i;
                    sol += i;
                    D[i].insert( bij );
                    break;
                }
            }

            int kk = -1;
            for( set<int>::iterator it = D[1].begin(); it != D[1].end(); it++ ){
                if( kk == -1 || last[ *it ] < last[ kk ] ){
                    kk = *it;
                }
            }

            sol++;
            D[1].erase( kk );

            for( int i = 2; i <= m+1; i++ ){
                if( D[i].size() < c || i == m+1 ){
                    D[i].insert( kk );
                    sol += i;
                    break;
                }
            }

            sol += pos_m;
            D[pos_m].erase( bij );

            sol++;
            D[1].insert( bij );
        }

        cout << sol << '\n';
    }
}
