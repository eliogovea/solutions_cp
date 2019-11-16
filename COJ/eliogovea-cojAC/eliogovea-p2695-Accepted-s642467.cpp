#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int n, k;
vector<int> v[25];
string str;

vector<int> func(const string &s) {
	int i = 1, num = 0;
	bool menos = false;
	vector<int> r;
	r.clear();
	for (int i = 0; s[i]; i++) {
		if (s[i] == '{') continue;
		if (s[i] == ',' || s[i] == '}') {
			if (menos) num = -num;
			r.push_back(num);
			num = 0;
			menos = false;
		}
		else if (s[i] == '-') menos = true;
		else num = 10 * num + s[i] - '0';
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	while (n--) {
		cin >> k;
		int len = -1;
		bool sol = true;
		for (int i = 0; i < k; i++) {
			v[i].clear();
			cin >> str;
			if (!sol) continue;
			v[i] = func(str);
			if (len == -1) len = v[i].size();
			else if (len != v[i].size()) sol = false;
		}
		if (sol) {
			cout << '{';
			for (int i = 0; i < len; i++) {
				int tmp = 0;
				for (int j = 0; j < k; j++) tmp += v[j][i];
				cout << tmp;
				if (i < len - 1) cout << ',';
			}
			cout << "}\n";
		}
		else cout << "No solution\n";
	}
}
