// 2016-2017 National Taiwan University World Final Team Selection Contest
// 101234C

#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

bool used[N + 5][N + 5];

inline int sign(long long x) {
    if (x < 0) {
        return -1;
    }
    if (x > 0) {
        return 1;
    }
    return 0;
}

inline long long cross(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (dx == 0 || dy == 0) {
            continue;
        }

        int g = __gcd(abs(dx), abs(dy));

        //cerr << g << "\n";

        if (sign(dx) == sign(dy)) {
            //cerr << "case 1\n";
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            dx = x2 - x1;
            dy = y2 - y1;

            dx /= g;
            dy /= g;

            //cerr << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
            //cerr << dx << " " << dy << "\n\n";

            for (int i = 0; i < g; i++) {
                int curX = x1 + dx * i;
                int curY = y1 + dy * i + 1;
                int nextX = x1 + dx * (i + 1);
                int nextY = y1 + dy * (i + 1);
                //cerr << "cur " << curX << " " << curY << "\n";
                //cerr << "next " << nextX << " " << nextY << "\n";
                //cerr << "cross "  << cross(curX - x1, curY - y1, curX - x2, curY - y2) << "\n";
                while (true) {
                    //cerr << "mark -->> " << curX << " " << curY << "\n";
                    used[curX + 1][curY] = true;
                    while (cross(curX + 1 - x1, curY - y1, curX + 1 - x2, curY - y2) > 0) {
                        curX++;
                        //cerr << "mark " << curX << " " << curY << "\n";
                        used[curX + 1][curY] = true;
                    }
                    if (curY == nextY) {
                        break;
                    }
                    curY++;
                }
            }
        } else {
            //cerr << "case 2\n";
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }
            dx = x2 - x1;
            dy = y2 - y1;

            dx /= g;
            dy /= g;

            for (int i = 0; i < g; i++) {
                int curX = x1 + dx * i;
                int curY = y1 + dy * i - 1;
                int nextX = x1 + dx * (i + 1);
                int nextY = y1 + dy * (i + 1);
                while (true) {
                    used[curX + 1][curY + 1] = true;
                    //cerr << "mark " << curX << " " << curY << "\n";
                    while (cross(curX + 1 - x1, curY - y1, curX + 1 - x2, curY - y2) < 0) {
                        curX++;
                        //cerr << "mark " << curX << " " << curY << "\n";
                        used[curX + 1][curY + 1] = true;
                    }
                    if (curY == nextY) {
                        break;
                    }
                    curY--;
                }
            }
        }
    }
    int ans = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (used[x][y]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
