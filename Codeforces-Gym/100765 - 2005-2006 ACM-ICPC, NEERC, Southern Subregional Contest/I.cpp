// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765I

#include <bits/stdc++.h>

using namespace std;

int n, k, p;
int cost_gum[650];
int tooth[650];
vector <pair <int, int> > gum[650];

vector <int> sum_gum[650];

int dp[650][650];

int sum[650];

int rec[650][650];

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("dat.txt", "r", stdin);
    cin >> n >> k >> p;
    for (int i = 1; i <= k; i++) {
        cin >> cost_gum[i];
    }
    for (int i = 1; i <= n; i++) {
        int g;
        cin >> tooth[i] >> g;
        gum[g].push_back(make_pair(tooth[i], i));
    }

    for (int i = 1; i <= k; i++) {
        sort(gum[i].begin(), gum[i].end());
        sum_gum[i].resize(gum[i].size() + 5, 0);
        sum[i] = sum[i - 1] + gum[i].size();
        for (int j = 1; j <= gum[i].size(); j++) {
            sum_gum[i][j] = sum_gum[i][j - 1] + gum[i][j - 1].first;
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;


    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= sum[i]; j++) {
            dp[i][j] = dp[i - 1][j];
            rec[i][j] = 0;
        }
        for (int j = 1; j <= sum[i]; j++) {
            for (int l = 1; l <= gum[i].size(); l++) {
                int tmp = dp[i - 1][j - l] + cost_gum[i] + sum_gum[i][l];
                if (dp[i][j] > tmp) {
                    dp[i][j] = tmp;
                    rec[i][j] = l;
                }
            }
        }
    }
    vector <int> ans;
    for (int i = n; i >= 1; i--) {
        if (dp[k][i] <= p) {
            int cur = k;
            int cnt = i;
            while (cur) {
                for (int j = 0; j < rec[cur][cnt]; j++) {
                    ans.push_back(gum[cur][j].second);
                }
                int tmp = cnt - rec[cur][cnt];
                cur = cur - 1;
                cnt = tmp;
            }
            break;
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < ans.size()) cout << " ";
    }
    cout << "\n";
}
