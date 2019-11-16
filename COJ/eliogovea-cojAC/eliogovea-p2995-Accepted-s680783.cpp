#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

int tc;
string str;
set<string> S;
vector<string> a;
vector<int> b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	getline(cin, str);
	while (tc--) {
		S.clear();
		a.clear();
		b.clear();
		getline(cin, str);
		istringstream in(str);
		while (in >> str) a.push_back(str);
		while (true) {
			getline(cin, str);
			if (str == "what does the fox say?") break;
			istringstream iin(str);
			while (iin >> str);
			S.insert(str);
		}
		for (int i = 0; i < a.size(); i++)
			if (S.find(a[i]) == S.end()) b.push_back(i);
		for (int i = 0; i < b.size(); i++) {
			cout << a[b[i]];
			if (i < b.size() - 1) cout << " ";
			else cout << "\n";
		}
	}
}
