// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673D

#include <bits/stdc++.h>

using namespace std;
int n, m;
stack<int> s;
int egg = 0;
void rot( int x ){
    egg = s.top();
    egg += x;
    egg %= n;
    egg = (egg + n)%n;
    s.push(egg);
}
void undo( int x ){
    while( x-- )
        s.pop();
    egg = s.top();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen("dat.txt","r",stdin);
    cin >> n >> m;
    s.push(egg);
    for( int i = 0, x;i < m; i++ ){
        string t;
        cin >> t;
        if( t == "undo" ){
            cin >> x;
            undo(x);
        }
        else{
            stringstream fi(t);
            fi >> x;
            rot(x);
        }
        //cerr << egg << endl;
    }
    cout << egg << '\n';
}
