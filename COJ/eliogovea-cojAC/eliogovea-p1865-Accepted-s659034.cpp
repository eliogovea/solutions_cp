#include <iostream>
#include <map>

using namespace std;

int n, m;
string W, P, aux;
map<string, int> M;
map<string, int>::iterator it;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> W;
		for (int i = 0; W[i]; i++)
			for (int j = 0; j <= i; j++) {
        aux.clear();
				for (int k = j; k <= i; k++) aux += W[k];
				M[aux]++;
			}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> P;
		it = M.find(P);
		if (it == M.end()) cout << "0\n";
		else cout << it->second << "\n";
	}
}
