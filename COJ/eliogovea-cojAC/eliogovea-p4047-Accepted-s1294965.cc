#include <bits/stdc++.h>

using namespace std;

struct event {
	int x, id, type;

	event() {}
};

bool operator < (const event & lhs, const event & rhs) {
	if (lhs.x != rhs.x) {
		return lhs.x < rhs.x;
	}
	return lhs.type < rhs.type;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector <int> x(n), y(n);

		vector <event> events(2 * n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		       	events[i].x = x[i];
			events[i].id = i;
			events[i].type = 0;

			cin >> y[i];
			events[i + n].x = y[i];
			events[i + n].id = i;
			events[i + n].type = 1;
		}

		sort(events.begin(), events.end());

		int answer = 0;

		vector <bool> active(n);
		int last = -1;
		for (int i = 0; i < 2 * n; i++) {
			if (events[i].type == 0) {
				active[events[i].id] = true;
			} else if (active[events[i].id]) {
				if (x[events[i].id] > last) {
					answer++;
					last = events[i].x;
				}
				active[events[i].id] = false;
			}
		}

		cout << answer << "\n";
	}

}
