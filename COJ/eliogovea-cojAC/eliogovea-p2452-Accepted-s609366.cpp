#include <iostream>
#include <map>
using namespace std;

int tc, n;
map<string, double> m;
string aux;
double x, sol;

int main() {
	cin.sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		cin >> n;
		m.clear();
		sol = 0;

		for (int i = 0; i < n; i++) {
			cin >> aux >> x;
			if (m.find(aux) == m.end()) m[aux] = x;
			else m[aux] = min(m[aux], x);
		}
		for (map<string, double>::iterator it = m.begin(); it != m.end(); it++)
			sol += it->second;
		cout.precision(2);
		cout << fixed << sol << endl;
	}
}
