// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    ll A,B;
    while( cin >> A >> B , (A && B) ){
        map<ll,int> dicA , dicB;

        ll a = A, b = B;
        dicA[a] = 1;
        dicB[b] = 1;

        int step = 1;

        while( !dicA[b] && !dicB[a] ){
            step++;
            if( a != 1ll ){
                if( a % 2ll == 0ll ){
                    a /= 2ll;
                }
                else{
                    a = (3ll*a) + 1ll;
                }
                dicA[a] = step;
            }
            if( b != 1ll ){
                if( b % 2ll == 0ll ){
                    b /= 2ll;
                }
                else{
                    b = (3ll*b) + 1ll;
                }
                dicB[b] = step;
            }
        }

        if( dicA[b] ){
            cout << A << " needs " << dicA[b]-1 << " steps, " << B << " needs " << dicB[b]-1 << " steps, they meet at " << b << '\n';
        }
        else{
            cout << A << " needs " << dicA[a]-1 << " steps, " << B << " needs " << dicB[a]-1 << " steps, they meet at " << a << '\n';
        }
    }
}
