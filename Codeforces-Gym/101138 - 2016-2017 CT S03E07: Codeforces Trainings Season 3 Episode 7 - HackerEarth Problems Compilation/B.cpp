// 2016-2017 CT S03E07: Codeforces Trainings Season 3 Episode 7 - HackerEarth Problems Compilation
// 101138B

#include <bits/stdc++.h>

using namespace std;

string s;

bool ok( int i, int j ){
    if( j == i ){
        return true;
    }

    if( i+1 == j ){
        return ( s[i] == 'P' || s[j] == 'P' );
    }

    if( (j - i + 1) & 1 ){
        return false;
    }

    return ok( i , (i+j)/2 ) && ok( (i+j)/2 + 1 , j );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    int tc; cin >> tc;

    while( tc-- ){
        cin >> s;
        if( ok( 0 , s.size()-1 ) ){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
