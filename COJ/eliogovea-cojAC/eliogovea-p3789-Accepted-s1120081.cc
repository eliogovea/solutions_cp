#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		vector <vector <int> > v(n, vector <int> (m));
		vector <vector <int> > L(n, vector <int> (m));
		vector <vector <int> > R(n, vector <int> (m));
		vector <vector <int> > U(n, vector <int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		// cerr << "read ok\n";
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (r == 0) {
					U[r][c] = 1;
				} else {
					if (v[r][c] == v[r - 1][c] + 1) {
						U[r][c] = U[r - 1][c] + 1;
					} else {
						U[r][c] = 1;
					}
				}
			}
		}
		// cerr << "U ok\n";
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (c == 0) {
					L[r][c] = 1;
				} else {
					if (v[r][c] == v[r][c - 1] + 1) {
						L[r][c] = L[r][c - 1] + 1;
					} else {
						L[r][c] = 1;
					}
				}
			}
		}
		// cerr << "L ok\n";
		for (int r = 0; r < n; r++) {
			for (int c = m - 1; c >= 0; c--) {
				if (c == m - 1) {
					R[r][c] = 1;
				} else {
					if (v[r][c] + 1 == v[r][c + 1]) {
						R[r][c] = R[r][c + 1] + 1;
					} else {
						R[r][c] = 1;
					}
				}
			}
		}
		// cerr << "R ok\n";
		int ans = 1;
		for (int r = 0; r < n; r++) {
			vector <int> ll(m, -1);
			{
				stack <int> st;
				for (int c = m - 1; c >= 0; c--) {
					while (!st.empty() && U[r][c] < U[r][st.top()]) {
						ll[st.top()] = c;
						st.pop();
					}
					st.push(c);
				}
			}
			// cerr << "ll ok\n";
			vector <int> rr(m, m);
			{
				stack <int> st;
				for (int c = 0; c < m; c++) {
					while (!st.empty() && U[r][c] < U[r][st.top()]) {
						rr[st.top()] = c;
						st.pop();
					}
					st.push(c);
				}
			}
			// cerr << "rr ok\n";
			for (int c = 0; c < m; c++) {
				int vl = min(c - ll[c], L[r][c]);
				int vr = min(rr[c] - c, R[r][c]);
				// cerr << r << " " << c << " " << ll[c] << " " << " " << rr[c] << "\n";
				ans = max(ans, (vl + vr - 1) * U[r][c]);
			}
		}
		cout << ans << "\n";
	}
}
