#include <bits/stdc++.h>

using namespace std;

inline double eval(double x, double v, double t) {
    return x + v * t;
}

inline double calct(double x1, double v1, double x2, double v2) {
    return (x2 - x1) / (v1 - v2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(7);

    // freopen("dat.txt","r",stdin);

    int n;
    cin >> n;

    vector <int> sx(n);
    vector <int> sv(n);
    int top = 0;

    bool ok = false;
    double ans;

    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;

        if (v < 0) {
            if (top == 0) {
                continue;
            }
            int pos = 0;
            int lo = 1;
            int hi = top - 1;

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (calct(x, v, sx[mid], sv[mid]) <= calct(x, v, sx[mid - 1], sv[mid - 1])) {
                    pos = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            double t = calct(x, v, sx[pos], sv[pos]);

            if (!ok || ans > t) {
                ok = true;
                ans = t;
            }
        } else {
            while (top > 0 && v > sv[top - 1]) {
                top--;
            }

            while (top > 1) {
                double lt = calct(sx[top - 2], sv[top - 2], sx[top - 1], sv[top - 1]);
                // double xt = eval(sx[top - 2], sv[top - 2], lt);
                double t = calct(x, v, sx[top - 2], sv[top - 2]);
                // double xx = eval(x, v, t);

                if (lt >= t) {
                    top--;
                } else {
                    break;
                }
            }

            sx[top] = x;
            sv[top] = v;
            top++;
        }
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        cout << fixed << ans << "\n";
    }
}
