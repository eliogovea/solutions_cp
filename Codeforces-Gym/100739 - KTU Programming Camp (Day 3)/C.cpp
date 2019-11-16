// KTU Programming Camp (Day 3)
// 100739C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

int dp[MAXN][MAXN][4];
string mapa[MAXN];

int n;

struct it{
    int i, j, d;
    it(){ i = j = d = -1; }
    it(int ii,int jj,int dd){
        i = ii; j = jj; d = dd;
    }
};

it cola[MAXN * MAXN];
bool mk[MAXN][MAXN][4];

bool can_move(int i,int j){
    return ( i >= 0 && j >= 0 && i < n && j < n && mapa[i][j] != '#' );
}

int movI[] = { 1 ,  0, -1, 0 };
int movJ[] = { 0 , -1,  0, 1 };

int solve(){
    int enq = 0, deq = 0;

    cola[enq++] = it(0,0,0);
    mk[0][0][0] = true;

    int lev = 0;

    while( enq - deq && !mk[n-1][n-1][0] ){ lev++;
        
        int sz = (enq - deq);
        
        for(int c = 0; c < sz && !mk[n-1][n-1][0]; c++){
            it x = cola[deq++];
            int d = x.d;

            if( can_move( x.i + movI[d] , x.j + movJ[d] ) &&
                !mk[ x.i + movI[d] ][  x.j + movJ[d] ][d] ){
                    
                mk[ x.i + movI[d] ][  x.j + movJ[d] ][d] = true;
                cola[enq++] = it( x.i + movI[d] , x.j + movJ[d] , d );
                
                if( x.i == n-1 && x.j == n-1 && d == 0 ){
                    return lev;
                }
            }

            if( !mk[ x.i ][ x.j ][ (d + 3) % 4 ] ){
                
                cola[enq++] = it( x.i, x.j, (d + 3) % 4 );
                
                mk[ x.i ][ x.j ][ (d + 3) % 4 ] = true;
            }
        }
    }

    return lev;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> mapa[i];
    }

    cout << solve() << '\n';
}
