#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

int t;
int n, p;
int u[N], v[N];
int last[N];
int tou[N], tov[N];
long long dp[N];
pair <long long, int> events[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> p;

        for (int i = 1; i <= n; i++) {
            last[i] = 0;
        }

        long long answer = 0;

        for (int i = 1; i <= p; i++) {
            cin >> u[i] >> v[i];
            answer += 10 + abs(u[i] - v[i]);

            tou[i] = last[u[i]];
            tov[i] = last[v[i]];

            last[u[i]] = i;
            last[v[i]] = i;
        }

        for (int i = 1; i <= p; i++) {
            long long s = max(dp[tou[i]], dp[tov[i]]);
            dp[i] = s + 10LL + (long long)abs(u[i] - v[i]);
            
            events[i - 1] = make_pair(s, -1);
            events[p + i - 1] = make_pair(dp[i] - 1, 1);
        }

        long long maxt = 0;
        for (int i = 1; i <= p; i++) {
            maxt = max(maxt, dp[i]);
        }

        sort(events, events + 2 * p);

        int open = 0;
        int maxh = 0;
        for (int i = 0; i < 2 * p; i++) {
            open -= events[i].second;
            maxh = max(maxh, 2 * open);
        }
            
        cout << maxt << " " << maxh << "\n";
    }
}



