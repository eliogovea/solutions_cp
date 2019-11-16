#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 2005;

const ull C = 531;
const ull B = 33;

int hp, wp, ht, wt;
string p[N];
string t[N];

ull Hp[N];
ull Ht[N][N];
ull Pow[N];
ull pi[N];

int main() {
    //freopen("data.txt", "r", stdin);
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> hp >> wp >> ht >> wt;
    for (int i = 0; i < hp; i++) {
        cin >> p[i];
        //ull cur = C;
        ull cur = 0;
        for (int j = 0; j < wp; j++) {
            cur = B * cur + (p[i][j] == 'o' ? 1 : 2);
        }
        Hp[i] = cur;
    }
    for (int i = 0; i < ht; i++) {
        cin >> t[i];
        //Ht[i][0] = C;
        for (int j = 1; j <= wt; j++) {
            Ht[i][j] = B * Ht[i][j - 1] + (t[i][j - 1] == 'o' ? 1 : 2);
        }
    }
    Pow[0] = 1;
    for (int i = 1; i < N; i++) {
        Pow[i] = B * Pow[i - 1];
    }
    for (int i = 1; i < hp; i++) {
        int j = pi[i - 1];
        while (j > 0 && Hp[i] != Hp[j]) {
            j = pi[j - 1];
        }
        if (Hp[i] == Hp[j]) {
            j++;
        }
        pi[i] = j;
    }

    /*for (int i = 0; i < hp; i++) {
        cout << i << " " << Hp[i] << "\n";
    }
    cout << "\n";*/

    //cout << Ht[1][4] << "\n";

    int ans = 0;
    for (int i = 0; i + wp <= wt; i++) {
        int x = 0;
        for (int j = 0; j < ht; j++) {
            ull tmp = Ht[j][i + wp] - Ht[j][i] * Pow[wp];
            //cout << i << " " << i + wp << " " << tmp << "\n";
            while (x > 0 && tmp != Hp[x]) {
                x = pi[x - 1];
            }
            if (Hp[x] == tmp) {
                x++;
            }
            if (x == hp) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
