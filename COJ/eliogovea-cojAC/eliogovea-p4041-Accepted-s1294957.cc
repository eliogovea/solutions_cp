#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string l = "XBGCRMYW";

    int value[256];

    for (int i = 0; i < 8; i++) {
        value[(int)l[i]] = i;
    }

    int t;
    cin >> t;

    int n;
    string a, b;

    while (t--) {
        cin >> a >> b;
        n = a.size();
        int last = -1;
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            int va = value[(int)a[i]];
            int vb = value[(int)b[i]];
            for (int j = 2; j >= 0; j--) {
                answer++;
                if ((va & (1 << j)) == (vb & (1 << j))) {
                    cnt++;
                    int p = 3 * i + (2 - j);
                    if (last != -1 && !(cnt & 1)) {
                        answer += 2 * (p - last);
                    }
                    last = p;
                }
            }
        }

        if (cnt & 1) {
            answer = -1;
        }

        cout << answer << "\n";
    }
}
