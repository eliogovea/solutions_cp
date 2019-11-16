// KTU Programming Camp (Day 2)
// 100738D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> par;

const int MAXN = 200100ll;

par arr[MAXN];
par arcs[MAXN];

bool ok(int n){
    if( n == 1 ){
        return (arr[0].first == 0ll);
    }

    if(arr[0].first != 1ll){
        return false;
    }

    int h = 0, v = 0;

    for(; v < n; v++){
        if( arr[v].first > 1 ){
            break;
        }
    }

    if( v == n ){
        return false;
    }

    int sz = 0;
    for(; v < n-1; v++){
        while( h < v && arr[v].first > 1ll ){
            arr[v].first--;
            arcs[sz++] = par(arr[v].second , arr[h].second);
            h++;
        }
        if(arr[v].first > 1ll){
            return false;
        }
    }

    while( h < v && arr[v].first >= 0ll ){
        arr[v].first--;
        arcs[sz++] = par(arr[h].second , arr[v].second);
        h++;
    }

    if(arr[v].first != 0ll || h != v){
        return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort( arr, arr + n );

    if( !ok(n) ){
        cout << "-1\n";
    }
    else{
        for(int i = 0; i < n-1; i++){
            cout << arcs[i].first << ' ' << arcs[i].second << '\n';
        }
    }
}
