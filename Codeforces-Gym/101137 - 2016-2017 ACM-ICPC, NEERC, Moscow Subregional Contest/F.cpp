// 2016-2017 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101137F

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

string abc = "";

string solve( bool *mk, bool xorr = false ){
    string sol = "%[";
    if( xorr ){
        sol += "^";
    }

    vector<par> kk;

    for( int i = 0; i < abc.size(); i++ ){
        int j = i;
        while( mk[j] ){
            if( j+1 == abc.size() || !mk[j+1] ){
                break;
            }
            j++;
        }

        if( mk[i] ){
            kk.push_back( par( i , j ) );
            i = j;
        }
    }

    for( int i = 0; i < kk.size(); i++ ){
        int l = kk[i].first;
        int r = kk[i].second;

        if( r == l ){
            sol += (char)( abc[l] );
        }
        else if( r == l+1 ){
            sol += (char)( abc[l]);
            sol += (char)( abc[r]);
        }
        else{
            sol += (char)( abc[l] );
            sol += "-";
            sol += (char)( abc[r] );
        }

        //cout << abc[l] << ' ' << abc[r] << '\n';
    }

    sol += "]";

    for( int i = 0; i < sol.size()-1; i++ ){
        if( sol[i+1] == '-' ){
            if( sol[i] == '0' ){
                sol[i] = '!';
            }
            else if( sol[i] == 'A' ){
                sol[i] = ':';
            }
            else if( sol[i] == 'a' ){
                sol[i] = '[';
            }
        }
    }

    if( sol == "%[^]" ){
        return "%[^!]";
    }

    return sol;
}

bool mk[200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    abc = " ";
    for( char ch = '0'; ch <= '9'; ch++ ){
        abc += ch;
    }

    for( char ch = 'A'; ch <= 'Z'; ch++ ){
        abc += ch;
    }

    for( char ch = 'a'; ch <= 'z'; ch++ ){
        abc += ch;
    }

    string s;
    getline( cin , s );
    //s = abc;

    for( int i = 0; i < abc.size(); i++ ){
        mk[i] = (bool)(s.find(abc[i]) != -1);
    }

    string sol1 = solve( mk );

    for( int i = 0; i < abc.size(); i++ ){
        mk[i] ^= true;
    }

    string sol2 = solve( mk , true );
    if( sol2.size() < sol1.size() || ( sol2.size() == sol1.size() && sol2 < sol1 ) ){
        sol1 = sol2;
    }

    cout << sol1 << '\n';
}
