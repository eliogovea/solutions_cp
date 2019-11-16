// 2015 German Collegiate Programming Contest (GCPC 15) + POI 10-T3
// 100753G

#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    bool ok = true;

    int back = -1;

    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        if( x < back ){
            ok = false;
        }

        back = x;
    }

    if( ok ){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
}
