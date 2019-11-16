#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const double EPS = 1e-9;

int t, n;
double x[N], y[N];
double d[N][N];

bool visited[N];
double pd[N * N];

int dfs(int u, double dd) {
	int res = 1;
	visited[u] = true;
	for (int v = 0; v < n; v++) {
		if (v != u && !visited[v] && d[u][v] <= dd + EPS) {
			res += dfs(v, dd);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(3);
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		
		int c = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				pd[c++] = d[i][j] = d[j][i] = sqrt(dx * dx + dy * dy); 
			}
		}
		
		sort(pd, pd + c);
		
		
		
		int lo = 0;
		int hi = c - 1;
		int ans_id = c - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			for (int i = 0; i < n; i++) {
				visited[i] = false;
			}
			if (dfs(0, pd[mid]) == n) {
				ans_id = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		
		cout << fixed << pd[ans_id] << "\n";
	}
}