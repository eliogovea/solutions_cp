// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150C

#include <bits/stdc++.h>

using namespace std;

int r[][6]= { { 1 , 6 , 3 , 2 , 4 , 5 } ,
                { 1 , 6 , 2 , 4 , 5 , 3 } ,
                { 1 , 6 , 4 , 5 , 3 , 2 } ,
                { 1 , 6 , 5 , 3 , 2 , 4 } ,

                { 2 , 5 , 1 , 3 , 6 , 4 } ,
                { 2 , 5 , 3 , 6 , 4 , 1 } ,
                { 2 , 5 , 6 , 4 , 1 , 3 } ,
                { 2 , 5 , 4 , 1 , 3 , 6 } ,

                { 3 , 4 , 2 , 1 , 5 , 6 } ,
                { 3 , 4 , 1 , 5 , 6 , 2 } ,
                { 3 , 4 , 5 , 6 , 2 , 1 } ,
                { 3 , 4 , 6 , 2 , 1 , 5 } ,

                { 4 , 3 , 1 , 2 , 6 , 5 } ,
                { 4 , 3 , 2 , 6 , 5 , 1 } ,
                { 4 , 3 , 6 , 5 , 1 , 2 } ,
                { 4 , 3 , 5 , 1 , 2 , 6 } ,

                { 5 , 2 , 1 , 4 , 6 , 3 } ,
                { 5 , 2 , 4 , 6 , 3 , 1 } ,
                { 5 , 2 , 6 , 3 , 1 , 4 } ,
                { 5 , 2 , 3 , 1 , 4 , 6 } ,

                { 6 , 1 , 4 , 2 , 3 , 5 } ,
                { 6 , 1 , 2 , 3 , 5 , 4 } ,
                { 6 , 1 , 3 , 5 , 4 , 2 } ,
                { 6 , 1 , 5 , 4 , 2 , 3 }
              };

int n;
int c[23][23];
int sol;
int a[23];

int cont[30];

void solve( int x ){
    if( x == n ){
        int tmp = 0;
        for( int i = 0; i < 6; i++ ){
            int mx = 0;
            fill( cont , cont + 30 , 0 );
            for( int j = 0; j < n; j++ ){
                cont[ c[j][ r[ a[j] ][i] ] ]++;
                if( cont[ c[j][ r[ a[j] ][i] ] ] > mx ){
                    mx = cont[ c[j][ r[ a[j] ][i] ] ];
                }
            }
            tmp += n - mx;
        }

        sol = min( sol , tmp );
        return;
    }

    for( a[x] = 0 ; a[x] < 24; a[x]++ ){
        solve( x+1 );
    }
}

map<string,int> dic;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

    while( cin >> n, n ){ dic.clear();
        int sz = 0;

        for( int i = 0; i < n; i++ ){
            for( int j = 1; j <= 6; j++ ){
                string tmp; cin >> tmp;
                if( dic.find( tmp ) == dic.end() ){
                    dic[ tmp ] = ++sz;
                }

                c[i][j] = dic[tmp];
            }
        }

        sol = ( 1 << 29 );
        solve( 0 );

        cout << sol << '\n';
    }
}
