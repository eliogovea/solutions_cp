// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486H

#include <bits/stdc++.h>

using namespace std;

string line;

const int N = 105;

bool solved[N][N];

vector <long long> num;
vector <char> op;

long long dp_max[N][N];
long long dp_min[N][N];

void solve(int l, int r) {
    if (solved[l][r]) {
        return;
    }
    solved[l][r] = true;
    if (l == r) {
        dp_min[l][r] = num[l];
        dp_max[l][r] = num[l];
        return;
    }
    long long vmin = -1;
    long long vmax = -1;
    for (int i = l; i + 1 <= r; i++) {
        solve(l, i);
        solve(i + 1, r);
        if (op[i] == '*') {
            long long tmp1 = dp_min[l][i] * dp_min[i + 1][r];
            if (vmin == -1 || tmp1 < vmin) vmin = tmp1;
            long long tmp2 = dp_max[l][i] * dp_max[i + 1][r];
            if (vmax == -1 || tmp2 > vmax) vmax = tmp2;
        } else {
            long long tmp1 = dp_min[l][i] + dp_min[i + 1][r];
            if (vmin == -1 || tmp1 < vmin) vmin = tmp1;
            long long tmp2 = dp_max[l][i] + dp_max[i + 1][r];
            if (vmax == -1 || tmp2 > vmax) vmax = tmp2;
        }

    }
    //cout << l << " " << r << " " << vmin << " " << vmax << "\n";
    dp_min[l][r] = vmin;
    dp_max[l][r] = vmax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    while (getline(cin, line)) {
        if (line == "END") break;
        num.clear();
        op.clear();
        for (int i = 0, cur = 0; i <= line.size(); i++) {
            if (line[i] < '0' || line[i] > '9') {
                num.push_back(cur);
                if (!line[i]) break;
                op.push_back(line[i]);
                cur = 0;
            } else {
                cur = 10 * cur + line[i] - '0';
            }
        }

        for (int i = 0; i < num.size(); i++) {
            for (int j = i; j < num.size(); j++) {
                solved[i][j] = false;
            }
        }
        solve(0, num.size() - 1);

        cout << dp_min[0][num.size() - 1] << " " << dp_max[0][num.size() - 1] << "\n";
    }
}
