// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124D

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

struct pos{
    par a;
    par c;
    par wr;
    par br;

    pos( par aa, par cc, par wrr, par brr ){
        a = aa;
        c = cc;
        wr = wrr;
        br = brr;
    }
};

par getIJ( string &x ){
    int i = 8 - (x[1]-'0') + 1;
    int j = x[0] - 'a' + 1;

    return par( i , j );
}

string getX( int i, int j ){
    char f = '0' + (8 - i + 1);
    char c = 'a' + (j-1);

    string ret = "";
    ret += c;
    ret += f;
    return ret;
}

bool can_move( int i, int j ){
    return ( i >= 1 && j >= 1 && i <= 8 && j <= 8 );
}

int movIC[] = { -2 , -1 , 1 , 2 , -2 , -1 , 1 , 2 };
int movJC[] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 };

int movIA[] = { 1 , -1 , 1 , -1 };
int movJA[] = { 1 , -1 , -1 , 1 };

int movIR[] = { 1 , -1, 1 ,-1, 0 , 1 , -1 , 0 };
int movJR[] = { 1 , -1,-1 , 1, 1 , 0 , 0 , -1 };

vector<par> getMovesC( par pos, set<par> mk ){
    vector<par> ret;

    int i = pos.first;
    int j = pos.second;

    for( int k = 0; k < 8; k++ ){
        int ii = i + movIC[k];
        int jj = j + movJC[k];

        if( can_move( ii , jj ) ){
            ret.push_back( par(ii,jj) );
        }
    }

    return ret;
}

vector<par> getMovesR( par pos, set<par> mk ){
    vector<par> ret;

    int i = pos.first;
    int j = pos.second;

    for( int k = 0; k < 8; k++ ){
        int ii = i + movIR[k];
        int jj = j + movJR[k];

        if( can_move( ii , jj ) && mk.find( par( ii , jj ) ) == mk.end() ){
            ret.push_back( par(ii,jj) );
        }
    }

    return ret;
}

vector<par> getMovesA( par pos, set<par> mk ){
    vector<par> ret;

    int i = pos.first;
    int j = pos.second;

    for( int k = 0; k < 4; k++ ){
        for( int c = 1; c <= 10; c++ ){
            int ii = i + c*movIA[k];
            int jj = j + c*movJA[k];

            if( can_move( ii , jj ) ){
                ret.push_back( par(ii,jj) );

                if( mk.find( par( ii , jj ) ) != mk.end() ){
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    return ret;
}

bool mate( pos p ){
    //cerr << p.a.first << ' ' << p.a.second << '\n';

    set<par> mk;
    vector<par> moves = getMovesR( p.wr, set<par>() );
    for( int i = 0; i < moves.size(); i++ ){
        mk.insert( moves[i] );
    }

    moves = getMovesC( p.c, set<par>() );
    for( int i = 0; i < moves.size(); i++ ){
        mk.insert( moves[i] );
    }

    set<par> tmp;
    tmp.insert( p.wr );
    tmp.insert( p.c );
    tmp.insert( p.br );

    moves = getMovesA( p.a, tmp );
    for( int i = 0; i < moves.size(); i++ ){
        mk.insert( moves[i] );
    }

    if( mk.find( p.br ) != mk.end() ){
        moves = getMovesR( p.br, mk );

        return ( moves.size() == 0 );
    }

    return false;
}

int dii( par x, par y ){
    return abs( x.first - y.first ) + abs( x.second - y.second );
}

string solve( pos p ){  //cerr << p.a.first << ' ' << p.a.second << '\n';

    set<par> mk;
    mk.insert( p.br );
    mk.insert( p.wr );
    mk.insert( p.a );
    mk.insert( p.c );

    string sol = "B";
    int i = p.a.first;
    int j = p.a.second;

    for( int k = 0; k < 4; k++ ){
        for( int c = 1; c <= 10; c++ ){
            int ii = i + c * movIA[k];
            int jj = j + c * movJA[k];

            if( !can_move( ii , jj ) || mk.find( par( ii , jj ) ) != mk.end() ){
                break;
            }

            pos tmp = p;
            tmp.a = par( ii , jj );

            if( mate( tmp ) ){
                sol += getX( ii , jj );
                return sol;
            }
        }
    }

    sol = "K";
    i = p.wr.first;
    j = p.wr.second;

    for( int k = 0; k < 8; k++ ){
        int ii = i + movIR[k];
        int jj = j + movJR[k];

        bool ok = true;

        for( int k2 = 0; k2 < 8; k2++ ){
            int iii = ii + movIR[k2];
            int jjj = jj + movJR[k2];

            if( iii == p.br.first && jjj == p.br.second ){
                ok = false;
                break;
            }
        }

        if( can_move( ii , jj ) && mk.find( par( ii , jj ) ) == mk.end() && ok ){
            pos tmp = p;
            tmp.wr = par( ii , jj );

            if( mate( tmp ) ){
                sol += getX( ii , jj );
                return sol;
            }
        }
    }

    sol = "N";
    i = p.c.first;
    j = p.c.second;

    for( int k = 0; k < 8; k++ ){
        int ii = i + movIC[k];
        int jj = j + movJC[k];

        if( can_move( ii , jj ) && mk.find( par( ii , jj ) ) == mk.end() ){
            pos tmp = p;
            tmp.c = par( ii , jj );

            if( mate( tmp ) ){
                sol += getX( ii , jj );
                return sol;
            }
        }
    }

    return "impossible";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string wr, a, c, br; cin >> wr >> a >> c >> br;

    pos p = pos( getIJ( a ) , getIJ( c ) , getIJ( wr ) , getIJ( br ) );

    cout << solve( p ) << '\n';
}
