// 2015 United Kingdom and Ireland Programming Contest (UKIEPC 2015)
// 100800I

#include <bits/stdc++.h>

using namespace std;

char mn[] = { 'b', 'c', 'd', 'g', 'k', 'n', 'p', 't' };
char mx[] = { 'B', 'C', 'D', 'G', 'K', 'N', 'P', 'T' };

bool low( char x ){
    return ( 'a' <= x && x <= 'z' );
}

char getNear( char x ){
    if( low(x) ){
        char HC = 'b';
        for( int i = 1; i < 8; i++ ){
            if( abs( HC - x ) > abs( mn[i] - x ) ){
                HC = mn[i];
            }
        }

        return HC;
    }

    char HC = 'B';
    for( int i = 1; i < 8; i++ ){
        if( abs( HC - x ) > abs( mx[i] - x ) ){
            HC = mx[i];
        }
    }

    return HC;
}

bool isHC( char x ){
    for( int i = 0; i < 8; i++ ){
        if( mn[i] == x || mx[i] == x ){
            return true;
        }
    }

    return false;
}

char replaceHC( char x, char HC ){
    if( low(x) ){
        if( !low(HC) ){
            HC = 'a' + (HC - 'A');
        }
    }
    else if( low(HC) ){
        HC = 'A' + (HC - 'a');
    }

    return HC;
}

string getFin( char HC ){
    if( !low(HC) ){
        return "ah";
    }

    int a = abs( HC - 'a' );
    int o = abs( HC - 'o' );
    int u = abs( HC - 'u' );

    if( a <= o && a <= u ){
        return "ah";
    }
    if( o <= u ){
        return "oh";
    }

    return "uh";
}

string get_word( string w ){
    int n = w.size();
    string ret = "";

    ret += (char)getNear( w[0] );
    bool ok = false;

    for( int i = 1; i < n; i++ ){
        if( w[i] == '-' ){
            ok = true;
            continue;
        }

        if( isHC(w[i]) && ok ){
            ret += (char)replaceHC( w[i] , ret[0] );
        }
        else{
            ret += (char)w[i];
        }
    }

    if( isHC( ret[ ret.size()-1 ] ) ){
        ret += getFin( ret[ ret.size()-1 ] );
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string line; getline( cin , line );
    string w = "";

    for( int i = 0; i < line.size(); i++ ){
        if( line[i] != ' ' ){
            w += (char)line[i];
        }
        else{
            cout << get_word(w) << ' ';
            w = "";
        }
    }

    cout << get_word(w) << '\n';
}
