// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174E

#include <bits/stdc++.h>

using namespace std;

int n, a, b;
string bl[55];

const int SIZE = 55 * 25;
const int ALPH = 26;

int next[SIZE][ALPH];
int fail[SIZE];
bool end[SIZE];

int size;

int getNew() {
    for (int i = 0; i < ALPH; i++) {
        next[size][i] = -1;
    }
    fail[size] = -1;
    end[size] = false;
    return size++;
}

void init() {
    size = 0;
    getNew();
}

void add(string &s) {
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i] - 'a';
        if (next[now][c] == -1) {
            next[now][c] = getNew();
        }
        now = next[now][c];
    }
    end[now] = true;
}

void build() {
    queue <int> Q;
    for (int i = 0; i < ALPH; i++) {
        if (next[0][i] == -1) {
            next[0][i] = 0;
        } else {
            int x = next[0][i];
            fail[x] = 0;
            Q.push(x);
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        end[now] |= end[fail[now]];
        for (int i = 0; i < ALPH; i++) {
            if (next[now][i] == -1) {
                next[now][i] = next[fail[now]][i];
            } else {
                fail[next[now][i]] = next[fail[now]][i];
                Q.push(next[now][i]);
            }
        }
    }
}

inline int val(char c) {
    if ('0' <= c && c <= '9') {
        return 0;
    }
    if ('a' <= c && c <= 'z') {
        return 1;
    }
    return 2;
}

const int MOD = 1000003;

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int dp[55][10][SIZE];

inline char get(char c) {
    if ('a' <= c && c <= 'z') {
        return c;
    }
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }
    if (c == '0') {
        return 'o';
    }
    if (c == '1') {
        return 'i';
    }
    if (c == '3') {
        return 'e';
    }
    if (c == '5') {
        return 's';
    }
    if (c == '7') {
        return 't';
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        cin >> bl[i];
    }

    init();
    for (int i = 0; i < n; i++) {
        add(bl[i]);
    }
    //bl[n] = "leet";
    //add(bl[n]);

    build();

    dp[0][0][0] = 1;
    for (int l = 0; l < b; l++) {
        for (int m = 0; m < 8; m++) {
            for (int s = 0; s < size; s++) {
                if (end[s] || dp[l][m][s] == 0) {
                    continue;
                }
                for (char c = '0'; c <= '9'; c++) {
                    char cc = get(c);
                    if (!cc) {
                        add(dp[l + 1][m | (1 << val(c))][0], dp[l][m][s]);
                    } else {
                        int ns = next[s][cc - 'a'];
                        if (!end[ns]) {
                            add(dp[l + 1][m | (1 << val(c))][ns], dp[l][m][s]);
                        }
                    }
                }
                for (char c = 'a'; c <= 'z'; c++) {
                    char cc = get(c);
                    if (!cc) {
                        add(dp[l + 1][m | (1 << val(c))][0], dp[l][m][s]);
                    } else {
                        int ns = next[s][cc - 'a'];
                        if (!end[ns]) {
                            add(dp[l + 1][m | (1 << val(c))][ns], dp[l][m][s]);
                        }
                    }
                }
                for (char c = 'A'; c <= 'Z'; c++) {
                    char cc = get(c);
                    if (!cc) {
                        add(dp[l + 1][m | (1 << val(c))][0], dp[l][m][s]);
                    } else {
                        int ns = next[s][cc - 'a'];
                        if (!end[ns]) {
                            add(dp[l + 1][m | (1 << val(c))][ns], dp[l][m][s]);
                        }
                    }
                }
            }
        }
    }
    int answer = 0;
    for (int l = a; l <= b; l++) {
        for (int s = 0; s < size; s++) {
            add(answer, dp[l][7][s]);
        }
    }
    cout << answer << "\n";
}
