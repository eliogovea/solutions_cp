#include <iostream>
#include <cstring>

using namespace std;

const int L = 10;
const int A = 26;

long long C[A + 10][A + 10];

char s[L + 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= A; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        } 
    }


    cin >> s;
    int t = strlen(s);

    for (int i = 1; i < t; i++) {
        if (s[i] <= s[i - 1]) {
            cout << "0\n";
            return 0;
        }
    }

    long long answer = 1;
    for (int l = 1; l < t; l++) {
        answer += C[A][l];
    }

    for (int l = 0; l < t; l++) {
        char start = 'a';
        if (l > 0) {
            start = s[l - 1] + 1;
        }
        for (char c = start; c < s[l]; c++) {
            int chars = A - (c - 'a' + 1);
            int len = t - l - 1;
            if (chars >= len) {
                answer += C[chars][len];
            }
        }
    }

    cout << answer << "\n";
}
