#include <iostream>
#include <map>

using namespace std;

int mx;
string a, b;
map<string, int> M;
map<string, int>::iterator it;

int main() {
	cin >> a;
	if (a.size() >= 8) {
		for (int i = 0; i + 7 < a.size(); i++) {
			b.clear();
			for (int j = 0; j < 8; j++)
				b += a[i + j];
			M[b]++;
		}
	}
	b.clear();
	for (it = M.begin(); it != M.end(); it++)
		if (it->second > mx || (it->second == mx && it->first < b)) {
			mx = it->second;
			b = it->first;
		}
	if (mx >= 2) cout << b << "\n";
	else cout << "Solution was not found\n";
}
