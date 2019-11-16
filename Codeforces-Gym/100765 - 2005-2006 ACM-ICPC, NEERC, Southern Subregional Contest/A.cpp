// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765A

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

int st[MAXN];
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);

    string s; cin >> s;
    int k; cin >> k;

    int n = s.size();

    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }

    int j = 0;
    int sz = 0;

    while( k && j < n ){

        st[sz++] = a[j];

        while( k && sz-1 > 0 && a[j] > st[sz-2] ){
            sz--;
            st[sz-1] = a[j];
            k--;
        }

        j++;
    }

    if( k > 0 ){
        for(int i = 0; i < sz - k; i++){
            cout << st[i];
        }
        cout << '\n';
    }
    else{
        for(int i = 0; i < sz; i++){
            cout << st[i];
        }
        for(int i = j; i < n; i++){
            cout << a[i];
        }
        cout << '\n';
    }
}
