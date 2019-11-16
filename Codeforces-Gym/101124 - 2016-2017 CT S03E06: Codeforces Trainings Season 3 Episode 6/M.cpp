// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124M

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);

	//freopen("dat.txt", "r", stdin);

	ll n;

	while( cin >> n ){
        ll p = 1ll;

        while( p * 18ll < n ){
            p *= 18ll;
        }


        if( p * 9ll >= n ){
            cout << "Stan wins.\n";
        }
        else{
            cout << "Ollie wins.\n";
        }
	}
}
