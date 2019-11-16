#include <bits/stdc++.h>

using namespace std;
typedef struct node;
typedef long long ll;
const int maxn = 200100;
struct node{
    node *son;
    int val;

    node(){
        son =NULL;
        val = 0;
    }
};
node* s[maxn+10];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen( "dat.txt", "r", stdin );

    int n;
    cin >> n;
    s[0] = new node();
    for( int i = 1, t, m; i <= n; i++ ){
        cin >> t >> m;
        s[i] = s[t];
        if( m == 0 ){
            s[i] = s[t]->son;
        }
        else{
            node* tmp = new node();
            tmp->son = s[i];
            tmp->val = s[i]->val + m;
            s[i] = tmp;
        }
    }
    ll ans = 0;
    for( int  i = 1; i <= n; i++ ){
        ans += s[i]->val;
    }
    cout << ans << '\n';
}
