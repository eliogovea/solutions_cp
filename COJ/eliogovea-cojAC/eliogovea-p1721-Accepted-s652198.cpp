#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int tc;
string str;
vector<int> dp;
string words[] = {"out", "output", "puton", "in", "input", "one"};

int main() {
  //freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		dp.clear();
		cin >> str;
		int sz = str.size();
		dp.resize(sz + 5);
		dp[0] = 1;
		for (int i = 0; str[i]; i++)
			if (dp[i])
				for (int j = 0; j < 6; j++) {
					bool match = true;
					for (int k = 0; words[j][k]; k++)
						if (str[i + k] != words[j][k]) {
							match = false;
							break;
						}
					if (match) dp[i + words[j].size()] = 1;
				}
		if (dp[sz]) cout << "YES\n";
		else cout << "NO\n";
	}
}
