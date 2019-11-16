// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765G

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

int st[MAXN];

string s;

int get_tag( int &j ){
    string tag = "";
    tag += s[j];
    j++;
    while( s[j] != '>' ){
        tag += s[j];
        j++;
    }
    tag += s[j];

    if( tag == "<UP>" ){
        return 2;
    }
    if( tag == "</UP>" ){
        return -2;
    }

    if( tag == "<DOWN>" ){
        return 1;
    }
    if( tag == "</DOWN>" ){
        return -1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);

    cin >> s;

    int n = s.size();

    int sz = 0;
    st[ sz++ ] = 0;

    for(int i = 0; i < n; i++){
        int tag = st[sz-1];

        if( s[i] == '<' ){
            tag = get_tag(i);
            if( tag < 0 ){
                sz--;
            }
            else{
                st[ sz++ ] = tag;
            }
            continue;
        }

        if( tag == 0 ){
            cout << s[i];
        }
        else if( tag == 1 ){
            if( s[i] >= 'a' && s[i] <= 'z' ){
                cout << s[i];
            }
            else{
                //cout << s[i];
                cout << (char)( 'a' + ( s[i] - 'A' ) );
            }
        }
        else if( tag == 2 ){
            if( s[i] >= 'A' && s[i] <= 'Z' ){
                cout << s[i];
            }
            else{
                //cout << s[i];
                cout << (char)( 'A' + ( s[i] - 'a' ) );
            }
        }
    }
    cout << '\n';
}
