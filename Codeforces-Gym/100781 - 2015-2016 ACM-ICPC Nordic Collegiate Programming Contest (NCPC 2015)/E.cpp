// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781E

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

typedef pair<int,int> par;

par a[MAXN];
par a2[MAXN];

int solve( int n, int k , par *a ){
    multiset<int> ms;
    int sol = 0;

    for(int i = 0; i < n; i++){
        while( !ms.empty() && *ms.begin() <= a[i].first ){
            ms.erase( ms.begin() );
        }

        if( ms.size() < k ){
            sol++;
            ms.insert( a[i].second );
        }
        else if( *ms.rbegin() > a[i].second ){
            ms.erase( ms.find(*ms.rbegin()) );
            ms.insert( a[i].second );
        }
    }

    return sol;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        a2[i].first = -a[i].second;
        a2[i].second = -a[i].first;
    }

    sort( a , a + n );
    sort( a2 , a2 + n );

    int outp = solve( n , k , a );
    //outp = max( outp , solve( n , k , a2 ) );

    cout << outp << '\n';
}
