// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095R

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string,string> par;

// Piedra - 0
// Tijera - 1
// Papel - 2

bool first( int a, int b ){
    if( a == 0 && b == 1 ){
        return true;
    }

    if( a == 1 && b == 0 ){
        return false;
    }

    if( a == 0 && b == 2 ){
        return false;
    }

    if( a == 2 && b == 0 ){
        return true;
    }

    if( a == 1 && b == 2 ){
        return true;
    }

    if( a == 2 && b == 1 ){
        return false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    map<par,int> dic;
    dic[ par( "cs" , "Kamen" ) ] = 0;
    dic[ par( "cs" , "Nuzky" ) ] = 1;
    dic[ par( "cs" , "Papir" ) ] = 2;

    dic[ par( "en" , "Rock" ) ] = 0;
    dic[ par( "en" , "Scissors" ) ] = 1;
    dic[ par( "en" , "Paper" ) ] = 2;

    dic[ par( "fr" , "Pierre" ) ] = 0;
    dic[ par( "fr" , "Ciseaux" ) ] = 1;
    dic[ par( "fr" , "Feuille" ) ] = 2;

    dic[ par( "de" , "Stein" ) ] = 0;
    dic[ par( "de" , "Schere" ) ] = 1;
    dic[ par( "de" , "Papier" ) ] = 2;

    dic[ par( "hu" , "Ko" ) ] = 0;
    dic[ par( "hu" , "Koe" ) ] = 0;
    dic[ par( "hu" , "Ollo" ) ] = 1;
    dic[ par( "hu" , "Olloo" ) ] = 1;
    dic[ par( "hu" , "Papir" ) ] = 2;

    dic[ par( "it" , "Sasso" ) ] = 0;
    dic[ par( "it" , "Roccia" ) ] = 0;
    dic[ par( "it" , "Forbice" ) ] = 1;
    dic[ par( "it" , "Carta" ) ] = 2;
    dic[ par( "it" , "Rete" ) ] = 2;

    dic[ par( "jp" , "Guu" ) ] = 0;
    dic[ par( "jp" , "Choki" ) ] = 1;
    dic[ par( "jp" , "Paa" ) ] = 2;

    dic[ par( "pl" , "Kamien" ) ] = 0;
    dic[ par( "pl" , "Nozyce" ) ] = 1;
    dic[ par( "pl" , "Papier" ) ] = 2;

    dic[ par( "es" , "Piedra" ) ] = 0;
    dic[ par( "es" , "Tijera" ) ] = 1;
    dic[ par( "es" , "Papel" ) ] = 2;

    string sa = "";

    int game = 0;

    while( sa != "." ){ game++;
        string c1, c2, n1, n2; cin >> c1 >> n1 >> c2 >> n2;

        int ca = 0, cb = 0;

        string sb;
        while( cin >> sa && ( sa != "-" && sa != "." ) ){
            cin >> sb;

            int a = dic[par(c1,sa)];
            int b = dic[par(c2,sb)];

            if( a != b ){
                if( first( a , b ) ){
                    ca++;
                }
                else{
                    cb++;
                }
            }
        }

        cout << "Game #" << game << ":\n";
        if( ca == 1 ){
            cout << n1 << ": " <<  ca << " point\n";
        }
        else{
            cout << n1 << ": " <<  ca << " points\n";
        }

        if( cb == 1 ){
            cout << n2 << ": " <<  cb << " point\n";
        }
        else{
            cout << n2 << ": " <<  cb << " points\n";
        }

        if( ca == cb ){
            cout << "TIED GAME\n";
        }
        else{
            cout << "WINNER: ";

            if( ca > cb ){
                cout << n1;
            }
            else{
                cout << n2;
            }

            cout << '\n';
        }

        cout << '\n';
    }
}
