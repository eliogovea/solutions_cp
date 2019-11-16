// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703K

#include <bits/stdc++.h>

using namespace std;

int as, fs;
int n;

int qA[300];
int qF[300];

int ok( string s, int p ){
    if( as > p || fs > s.size() - p ){
        return -1;
    }

    int enqA =0, enqF = 0, deqA = 0, deqF = 0;

    int outp = 0;

    for( int i = p; i < n; i++ ){
        if( s[i] == 'A' ){
            qA[ enqA++ ] = i;
        }
    }

    for( int i = p-1; i >= 0; i-- ){
        if( s[i] == 'F' ){
            qF[ enqF++ ] = i;
        }
    }

    while( (enqA - deqA) && (enqF - deqF) ){
        int a = qA[ deqA++ ];
        int f = qF[ deqF++ ];

        outp += abs( a - f );
    }

    while( (enqF - deqF) && !(enqA - deqA) ){
        outp += p - qF[ deqF++ ];
    }
    while( !(enqF - deqF) && (enqA - deqA) ){
        outp += qA[ deqA++ ] - (p-1);
    }

    return outp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;

    string s; cin >> s;

    as = fs = 0;

    for( int i = 0; i < n; i++ ){
        if( s[i] == 'A' ){
            as++;
        }
        else if( s[i] == 'F' ){
            fs++;
        }
    }

    int outp = (1<<29);

    for( int i = 0, z; i < n; i++ ){
        if( (z = ok( s , i )) != -1 ){
            outp = min( outp , z );
        }
    }

    cout << outp << '\n';
}
