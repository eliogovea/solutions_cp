// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507H

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

char inv( char x ){
    if( 'a' <= x && x <= 'z' ){
        x = (char)( 'A' + (x-'a') );
    }
    else{
        x = (char)( 'a' + (x-'A') );
    }

    return x;
}

int id[MAXN];
int sol[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n; cin >> n; n*=2;
    string s; cin >> s;
    s += s;

    int A = 1, a = 1;
    for( int i = 0; i < 2*n; i++ ){
        if( i >= n ){
            id[i] = id[i-n];
        }
        else{
            if( 'a' <= s[i] && s[i] <= 'z' ){
                id[i] = a++;
            }
            else{
                id[i] = A++;
            }
        }
    }

    bool ok = false;

    for( int i = 0; i < n; i++ ){
        stack<int> st;
        for( int j = i; j < i + n; j++ ){
            if( !st.empty() && s[ st.top() ] == inv( s[j] ) ){
                int x = st.top();
                int y = j;

                if( 'a' <= s[x] && s[x] <= 'z' ){
                    swap( x , y );
                }

                sol[ id[x] ] = id[y];

                st.pop();
            }
            else{
                st.push( j );
            }
        }

        if( st.empty() ){
            ok = true;
            break;
        }
    }

    if( !ok ){
        cout << "Impossible";
        return 0;
    }

    for( int i = 1; i <= n/2; i++ ){
        cout << sol[i] << " \n"[i==n];
    }
}
