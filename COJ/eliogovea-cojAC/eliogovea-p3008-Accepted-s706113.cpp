#include <iostream>
#include <queue>

using namespace std;

const int N = 5005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

string s;

int get() {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		for (int j = 0; j < 3; j++)
			if (s[j] == '*') {
				int pos = 3 * i + j;
				ret += (1 << pos);
			}
	}
	return ret;
}

int f(int n, int x, int y) {
	int ret = n;
	int pos = 3 * x + y;
	ret ^= (1 << pos);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
			int pos = 3 * nx + ny;
			ret ^= (1 << pos);
		}
	}
	return ret;
}

void pr(int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int pos = 3 * i + j;
            if (x & (1 << pos)) cout << "*";
            else cout << ".";
        }
        cout << "\n";
    }
    cout << "\n";
}

int dist[N];
queue<int> Q;

int main() {
    ios::sync_with_stdio(false);
	for (int i = 1; i < N; i++) dist[i] = -1;
	Q.push(0);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		//pr(x);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				int nn = f(x, i, j);
				if (dist[nn] == -1) {
					dist[nn] = dist[x] + 1;
					Q.push(nn);
				}
			}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n = get();
		cout << dist[n] << "\n";
	}
}
