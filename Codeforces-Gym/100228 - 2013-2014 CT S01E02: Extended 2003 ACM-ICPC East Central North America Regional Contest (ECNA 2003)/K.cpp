// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

char s[MAXN][MAXN];
char ss[MAXN][MAXN];

bool mk[MAXN][MAXN];

int movI[] = { -2 , -1 , 1 , 2 , -2 , -1 , 1 , 2 };
int movJ[] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 };

int mI[] = { 0 , 1 , 0 , -1 , -1 , 1 , 1 , -1};
int mJ[] = { 1 , 0 , -1 , 0 , -1 , 1 , -1 , 1};

bool can_move( int i, int j ){
    return ( i >= 0 && i < 8 && j >= 0 && j < 8 && s[i][j] == '.' );
}

void move( int i, int j ){
    if( s[i][j] == 'r' || s[i][j] == 'q' ){
        for( int k = j-1; k >= 0 && s[i][k] == '.' ; k-- ){
            mk[i][k] = true;
        }
        for( int k = j+1; k < 8 && s[i][k] == '.' ; k++ ){
            mk[i][k] = true;
        }
        for( int k = i-1; k >= 0 && s[k][j] == '.' ; k-- ){
            mk[k][j] = true;
        }
        for( int k = i+1; k < 8 && s[k][j] == '.' ; k++ ){
            mk[k][j] = true;
        }
    }
    if( s[i][j] == 'b' || s[i][j] == 'q' ){
        for( int k = 1; i-k >= 0 && j-k >= 0 && s[i-k][j-k] == '.'; k++ ){
            mk[i-k][j-k] = true;
        }
        for( int k = 1; i+k < 8 && j+k < 8 && s[i+k][j+k] == '.'; k++ ){
            mk[i+k][j+k] = true;
        }
        for( int k = 1; i-k >= 0 && j+k < 8 && s[i-k][j+k] == '.'; k++ ){
            mk[i-k][j+k] = true;
        }
        for( int k = 1; i+k < 8 && j-k >= 0 && s[i+k][j-k] == '.'; k++ ){
            mk[i+k][j-k] = true;
        }
    }

    if( s[i][j] == 'n' ){
        for( int k = 0; k < 8; k++ ){
            int ni = i + movI[k];
            int nj = j + movJ[k];

            if( can_move( ni , nj ) ){
                mk[ni][nj] = true;
            }
        }
    }

    if( s[i][j] == 'k' ){
        for( int k = 0; k < 8; k++ ){
            int ni = i + mI[k];
            int nj = j + mJ[k];

            if( can_move( ni , nj ) ){
                mk[ni][nj] = true;
            }
        }
    }

    if( s[i][j] == 'p' ){
        if( ss[i][j] == 'p' ){
            if( can_move( i+1 , j-1 ) ){
                mk[i+1][j-1] = true;
            }
            if( can_move( i+1 , j+1 ) ){
                mk[i+1][j+1] = true;
            }
        }
        else{
            if( can_move( i-1 , j-1 ) ){
                mk[i-1][j-1] = true;
            }
            if( can_move( i-1 , j+1 ) ){
                mk[i-1][j+1] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string x;

    while( cin >> x ){
        for( int i = 0; i < MAXN; i++ ){
            for( int j = 0; j < MAXN; j++ ){
                s[i][j] = '.';
                mk[i][j] = false;
            }
        }

        int i = 0, j = 0;
        for( int k = 0; k < x.size(); k++ ){
            if( x[k] == '/' ){
                i++;
                j = 0;
                continue;
            }

            if( (x[k] >= 'A' && x[k] <= 'Z') || ( x[k] >= 'a' && x[k] <= 'z' ) ){
                ss[i][j] = x[k];
                x[k] = tolower( x[k] );
                s[i][j] = x[k];
                j++;
            }

            else{
                j += ( x[k] - '0' );
            }
        }

        int sol = 0;

        for( int i = 0; i < 8; i++ ){
            for( int j = 0; j < 8; j++ ){
                if( s[i][j] == '.' ){
                    sol++;
                }
                move( i , j );
            }
        }

        for( int i = 0; i < 8; i++ ){
            for( int j = 0; j < 8; j++ ){
                if( mk[i][j] ){
                    sol--;
                }
            }
        }

        cout << sol << '\n';
    }
}
