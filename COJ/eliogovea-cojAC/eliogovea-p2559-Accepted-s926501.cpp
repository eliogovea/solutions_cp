#include <bits/stdc++.h>

using namespace std;

const int N = 505;

const int INF = 1e8;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int r, c;
int h[N][N];

int dist[N][N];
bool mark[N][N];

queue <pair <int, int> > Q;

bool check(int t) {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            mark[i][j] = false;
            dist[i][j] = INF;
        }
    }
    dist[1][1] = t;
    Q = queue <pair <int, int> >();
    Q.push(make_pair(1, 1));
    while (!Q.empty() && !mark[r][c]) {
        int x = Q.front().first;
        int y = Q.front().second;
        int d = dist[x][y];
        Q.pop();
        if (mark[x][y]) {
            continue;
        }
        mark[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= r && yy >= 1 && yy <= c) {
                if (d + 1 < h[xx][yy]) {
                    if (dist[xx][yy] > d + 1) {
                        dist[xx][yy] = d + 1;
                        Q.push(make_pair(xx, yy));
                    }
                }
            }
        }
    }

    return mark[r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> h[i][j];
        }
    }

    int lo = 0;
    int hi = h[1][1] - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}
