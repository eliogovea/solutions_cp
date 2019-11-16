#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int L = 50;

int C[L][L];

int solve(int n) {
    if (n == 0) {
        return 0;
    }

    vector <int> d;
    while (n) {
        d.push_back(n & 1);
        n >>= 1;
    }

    reverse(d.begin(), d.end());

    int answer = 0;

    for (int l = 1; l < (int)d.size(); l++) {
        for (int zeros = 0; zeros < l; zeros++) {
            int ones = l - zeros;
            if (zeros >= ones) {
                answer += C[l - 1][zeros];
            }
        }
    }

    int zeros = 0;
    int ones = 1;

    for (int l = 1; l < (int)d.size(); l++) {
        if (d[l] == 1) { // 0
            for (int nzeros = 0; l + 1 + nzeros <= (int)d.size(); nzeros++) {
                int nones = (int)d.size() - l - 1 - nzeros;

                if (zeros + 1 + nzeros >= ones + nones) {
                    answer += C[(int)d.size() - l - 1][nzeros];
                }
            }
        }

        if (d[l] == 0) {
            zeros++;
        } else {
            ones++;
        }
    }

    if (zeros >= ones) {
        answer++;
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < L; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    int a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1) << "\n";
}
