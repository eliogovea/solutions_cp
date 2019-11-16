#include <bits/stdc++.h>

using namespace std;


int n;
long long rx, ry;
long long cnt[4][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("dat.txt", "r", stdin);

    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> rx >> ry;
        int x = abs(rx % 2LL);
        int y = abs(ry % 2LL);
        for (int px1 = 0; px1 < 2; px1++) {
            for (int py1 = 0; py1 < 2; py1++) {
                for (int px2 = 0; px2 < 2; px2++) {
                    for (int py2 = 0; py2 < 2; py2++) {
                        if (!( px1 < px2 || ( px1 == px2 && py1 <= py2 ) )) {
                            continue;
                        }
                        int xx1 = (px1 != x);
                        int yy1 = (py1 != y);
                        int xx2 = (px2 != x);
                        int yy2 = (py2 != y);
                        if (xx1 * yy2 == xx2 * yy1) {
                            // cerr << px1 << " " << px2 << " " << py1 << " " << py2 << " " << cnt[px1][py1] << " " << cnt[px2][py2] << "\n";
                            if (px1 == px2 && py1 == py2) {
                                ans += cnt[px1][py1] * (cnt[px1][py1] - 1LL) / 2LL;
                            } else {
                                ans += cnt[px1][py1] * cnt[px2][py2];
                            }
                            // cerr << ans << "\n";
                        }
                    }
                }
            }
        }
        cnt[x][y]++;
    }
    cout << ans << "\n";
}

/*#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300100;
const int MAX = 1000005;

typedef pair<int,int> par;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("dat.txt", "r", stdin);


}
*/
