#include <bits/stdc++.h>

using namespace std;

int n;

int first( long long n ){
    if( n == 2 ) return 0;
    if( n == 3 ) return 1;
    long long E = n * (n-1ll) / 2ll;
    if( n & 1 ) return E % 2ll;

    return first( n-1 ) ^ 1;
}

const int N = 105;



int dp[55][N][N];
vector <int> v[55];
vector <int> o[55];
bool solved[55][N][N];
vector <pair <int, int> > segs[55][105];


int solve(int id, int l, int r) {
    if (l == r) {
        dp[id][l][r] = 1;
        return 1;
    }
    if (solved[id][l][r]) {
        return dp[id][l][r];
    }
    solved[id][l][r] = true;
    set <int> S;
    set <int> used;
    for (int i = l; i <= r; i++) {
        if (S.find(v[id][i]) == S.end()) {
            S.insert(v[id][i]);
            int xorSum = 0;
            for (auto s : segs[id][ v[id][i] ]) {
                if (s.second < l || s.first > r) {
                    continue;
                }
                xorSum ^= solve(id, max(l, s.first), min(r, s.second));
            }
            used.insert(xorSum);
        }
    }
    int g = 0;
    while (used.find(g) != used.end()) {
        g++;
    }
    dp[id][l][r] = g;
    return g;
}

void B() {
    int x1, x2, a, b;
    cin >> x1 >> x2 >> a >> b;

    if (x1 + a <= x2 && x2 <= x1 + b) {
        cout << "FIRST\n";
        return;
    }

    bool sw = false;

    if (x1 > x2) {
        sw = true;
        swap(x1, x2);
        a = -a;
        b = -b;
    }

    if (b <= 0) {
        cout << "DRAW\n";
    } else {
        if (a <= 0) {
            cout << "DRAW\n";
        } else {
            int d = x2 - x1;

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        v[i].resize(k);
        o[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> o[i][j];
            v[i][j] = o[i][j];
        }

        vector <int> vals = v[i];
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for (int j = 0; j < k; j++) {
            v[i][j] = lower_bound(vals.begin(), vals.end(), v[i][j]) - vals.begin();
        }

        int t = vals.size();
        for (int j = 0; j < t; j++) {
            int s = 0;
            while (s < k) {

                while (s < k && v[i][s] <= j) {
                    s++;
                }
                if (s == k) {
                    break;
                }

                int e = s;
                while (e < k && v[i][e] > j) {
                    e++;
                }

                segs[i][j].push_back(make_pair(s, e - 1));

                s = e;
            }
        }
    }

    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum ^= solve(i, 0, v[i].size() - 1);
    }

    if (xorSum == 0) {
        cout << "S\n";
    } else {
        cout << "G\n";
        for (int i = 0; i < n; i++) {
            // if (dp[i][0][v[i].size() - 1] ^ xorSum < dp[i][0][ v[i].size() ]) {
                set <int> s;
                for (int j = 0; j < v[i].size(); j++) {
                    if (s.find(v[i][j]) == s.end()) {
                        s.insert(v[i][j]);
                        int sum = 0;
                        for (auto & seg : segs[i][ v[i][j] ]) {
                            sum ^= solve(i, seg.first, seg.second);
                        }
                        if ((xorSum ^ dp[i][0][ v[i].size() - 1 ] ^ sum) == 0) {
                            cout << i + 1 << " " << j + 1 << "\n";
                            return 0;
                        }
                    }
                }
            // }
        }
    }
}
