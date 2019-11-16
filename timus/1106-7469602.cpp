// Problem: pace=1&num=1106
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector <vector <int> > graph(n);
	for (int i = 0; i < n; i++) {
		int x;
		while (cin >> x && x != 0) {
			graph[i].push_back(x - 1);
		}
	}
	
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (!graph[i].size()) {
			ok = false;
			break;
		}
	}
	
	if (!ok) {
		cout << "0\n";
		return 0;
	}
	
	vector <int> depth(n, -1);
	queue <int> q;
	for (int i = 0; i < n; i++) {
		if (depth[i] == -1) {
			depth[i] = 0;
			q.push(i);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < graph[u].size(); i++) {
				int v = graph[u][i];
				if (depth[v] == -1) {
					depth[v] = depth[u] + 1;
					q.push(u);
				}
			}
		}
	}
	vector <int> answer;
	for (int i = 0; i < n; i++) {
		if (depth[i] & 1) {
			answer.push_back(i + 1);
		}
	}
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
		if (i + 1 < answer.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}