// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503A

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;

int d[MAXN][MAXN];
bool mk[MAXN][MAXN];

typedef pair<int,int> par;

int sol;

int n, m;

bool can_move( int i, int j ){
    return ( i >= 0 && j >= 0 );
}

bool move( par &pos , int dir  ){
    if( dir == 1 ){
        pos.second++;
        if( can_move( pos.first-1, pos.second ) ){
            if( mk[pos.first-1][pos.second] ){
                sol += d[pos.first-1][pos.second]/2;
            }
            else{
                sol += d[pos.first-1][pos.second];
                mk[pos.first-1][pos.second] = true;
            }
        }
        if( can_move( pos.first+1, pos.second ) ){
            if( mk[pos.first+1][pos.second] ){
                sol += d[pos.first+1][pos.second]/2;
            }
            else{
                sol += d[pos.first+1][pos.second];
                mk[pos.first+1][pos.second] = true;
            }
        }
        pos.second++;
    }
    else if( dir == 3 ){
        pos.second--;
        if( can_move( pos.first-1, pos.second ) ){
            if( mk[pos.first-1][pos.second] ){
                sol += d[pos.first-1][pos.second]/2;
            }
            else{
                sol += d[pos.first-1][pos.second];
                mk[pos.first-1][pos.second] = true;
            }
        }
        if( can_move( pos.first+1, pos.second ) ){
            if( mk[pos.first+1][pos.second] ){
                sol += d[pos.first+1][pos.second]/2;
            }
            else{
                sol += d[pos.first+1][pos.second];
                mk[pos.first+1][pos.second] = true;
            }
        }
        pos.second--;
    }
    else if( dir == 0 ){
        pos.first--;
        if( can_move( pos.first, pos.second-1 ) ){
            if( mk[pos.first][pos.second-1] ){
                sol += d[pos.first][pos.second-1]/2;
            }
            else{
                sol += d[pos.first][pos.second-1];
                mk[pos.first][pos.second-1] = true;
            }
        }
        if( can_move( pos.first, pos.second+1 ) ){
            if( mk[pos.first][pos.second+1] ){
                sol += d[pos.first][pos.second+1]/2;
            }
            else{
                sol += d[pos.first][pos.second+1];
                mk[pos.first][pos.second+1] = true;
            }
        }
        pos.first--;
    }
    else{
        pos.first++;
        if( can_move( pos.first, pos.second-1 ) ){
            if( mk[pos.first][pos.second-1] ){
                sol += d[pos.first][pos.second-1]/2;
            }
            else{
                sol += d[pos.first][pos.second-1];
                mk[pos.first][pos.second-1] = true;
            }
        }
        if( can_move( pos.first, pos.second+1 ) ){
            if( mk[pos.first][pos.second+1] ){
                sol += d[pos.first][pos.second+1]/2;
            }
            else{
                sol += d[pos.first][pos.second+1];
                mk[pos.first][pos.second+1] = true;
            }
        }
        pos.first++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m;

    for( int i = 0; i < n; i++ ){
        string s; cin >> s;
        for( int j = 0; j < m; j++ ){
            d[i*2+1][j*2+1] = s[j]-'0';
        }
    }

    string s; cin >> s;

    par pos = par( 0, 0 );
    int dir = 1;

    sol = 0;

    for( int i = 0; i < s.size(); i++ ){
        if( s[i] == 'L' ){
            dir = ( dir - 1 + 4 ) % 4;
        }
        else if( s[i] == 'R' ){
            dir = ( dir + 1 ) % 4;
        }
        else{
            move( pos , dir );
        }
    }

    cout << sol << '\n';
}
