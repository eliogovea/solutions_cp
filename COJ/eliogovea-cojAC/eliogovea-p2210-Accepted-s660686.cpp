#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 20015, MAXL = 40;

struct vertex {
	int par;
	char ch;
	int cnt;
	int next[26];
} T[MAXN * MAXL];

int states = 1;

vector<int> Lev[MAXL];

int N, Q, D, K;
string s;
vector<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> N;

	T[0].ch = '\0';
	T[0].par = -1;
	T[0].cnt = 0;
	for (int i = 0; i < 26; i++)
    T[0].next[i] = -1;

	while (N--) {
		cin >> s;
		int cur = 0, l = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      l++;
      char c = s[i] - 'a';
      if (T[cur].next[c] == -1) {
        T[cur].next[c] = states++;
        T[T[cur].next[c]].par = cur;
        T[T[cur].next[c]].ch = s[i];
        T[T[cur].next[c]].cnt = 0;
        for (int i = 0; i < 26; i++)
          T[T[cur].next[c]].next[i] = -1;
        Lev[l].push_back(T[cur].next[c]);
      }
      cur = T[cur].next[c];
      T[cur].cnt++;
    }
	}
	cin >> Q;
	while (Q--) {
		cin >> K >> D;
		ans.clear();
		for (int i = 0; i < Lev[D].size(); i++)
			if (T[Lev[D][i]].cnt >= K) {
				int x = Lev[D][i];
				s.clear();
				while (x) {
					s += T[x].ch;
					x = T[x].par;
				}
				ans.push_back(s);
			}
		if (ans.size() == 0) cout << "CLEAR\n";
		else {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << "\n";
		}
		if (Q) cout << "\n";
	}
}
