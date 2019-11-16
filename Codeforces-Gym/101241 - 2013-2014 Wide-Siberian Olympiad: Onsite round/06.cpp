// 2013-2014 Wide-Siberian Olympiad: Onsite round
// 10124106

#include <bits/stdc++.h>

using namespace std;

int get_id( char x ){
    if( x == '{' ){
        return 0;
    }
    if( x == '<' ){
        return 1;
    }
    if( x == '(' ){
        return 2;
    }
    if( x == '[' ){
        return 3;
    }
    if( x == '}' ){
        return 4;
    }
    if( x == '>' ){
        return 5;
    }
    if( x == ')' ){
        return 6;
    }
    if( x == ']' ){
        return 7;
    }
}

inline bool isempty( vector<int> &x ){
    return (x[0]+x[1]+x[2]+x[3] == 0);
}

vector<int> get_next( string &s, int &i, bool &open ){
    int n = s.size();
    vector<int> cnt( 4 , 0 );
    if( i == n ){
        return cnt;
    }

    open = (get_id(s[i]) < 4);
    while( i < n && (get_id(s[i])<4) == open ){
        cnt[ get_id(s[i]) % 4 ]++;
        i++;
    }

    return cnt;
}

bool ok( string &s ){
    stack<vector<int> > st;

    int n = s.size();

    int i = 0;
    while( i < n ){
        bool open = false;
        vector<int> x = get_next( s , i , open );

        if( open ){
            st.push(x);
            continue;
        }

        while( !st.empty() && !isempty(x) ){
            vector<int> o = st.top(); st.pop();

            for( int j = 0; j < 4; j++ ){
                if( o[j] >= x[j] ){
                    o[j] -= x[j];
                    x[j] = 0;
                }
                else{
                    x[j] -= o[j];
                    o[j] = 0;
                }
            }

            if( !isempty(o) ){
                if( !isempty(x) ){
                    return false;
                }
                st.push(o);
            }
        }

        if( !isempty(x) ){
            return false;
        }
    }

    return st.empty();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tc; cin >> tc;

    while( tc-- ){
        string s; cin >> s;

        if( ok(s) ){
            cout << "T\n";
        }
        else{
            cout << "NIL\n";
        }
    }
}
