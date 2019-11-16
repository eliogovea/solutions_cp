// 2014 Benelux Algorithm Programming Contest (BAPC 14), 2014-2015 CT S02E08: Codeforces Trainings Season 2 Episode 8
// 100526K

#include <bits/stdc++.h>

using namespace std;

inline long long getHash(const vector <int> &v, long long base) {
	long long res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = base * res + (long long)v[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <string> answer(n);
		vector <int> score(n);
		for (int i = 0; i < n; i++) {
			cin >> answer[i] >> score[i];
			for (int j = 0; j < m; j++) {
				answer[i][j] -= '0';
			}
		}
		if (m == 1) {
			vector <int> ans;
			for (int mask = 0; mask < 2; mask++) {
				bool ok = true;
				for (int i = 0; i < n; i++) {
					if ((answer[i][0] == mask && score[i] == 0) || (answer[i][0] != mask && score[i] == 1)) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans.push_back(mask);
				}
			}
			if (ans.size() != 1) {
				cout << ans.size() << " solutions\n";
			} else {
				cout << ans[0] << "\n";
			}
		} else {
			int firstHalf = m / 2;
			map <long long, int> freq;
			map <long long, int> lastMask;
			map <long long, int> :: iterator it;
			for (int mask = 0; mask < (1 << firstHalf); mask++) {
				vector <int> firstScore(n);
				for (int i = 0; i < n; i++) {
					for (int q = 0; q < firstHalf; q++) {
						if ((mask & (1 << q)) && answer[i][q]) {
							firstScore[i]++;
						}
						if ((!(mask & (1 << q))) && !answer[i][q]) {
							firstScore[i]++;
						}
					}
				}
				long long hashValue = getHash(firstScore, m + 1);
				freq[hashValue]++;
				lastMask[hashValue] = mask;
			}
			long long ans = 0;
			int ansFirstMask = 0;
			int ansSecondMask = 0;
			int secondHalf = m - firstHalf;
			for (int mask = 0; mask < (1 << secondHalf); mask++) {
				vector <int> secondScore(n);
				for (int i = 0; i < n; i++) {
					for (int q = 0; q < secondHalf; q++) {
						if ((mask & (1 << q)) && answer[i][firstHalf + q]) {
							secondScore[i]++;
						}
						if ((!(mask & (1 << q))) && !answer[i][firstHalf + q]) {
							secondScore[i]++;
						}
					}
				}
				vector <int> needScore(n);
				bool ok = true;
				for (int i = 0; i < n; i++) {
					needScore[i] = score[i] - secondScore[i];
					if (needScore[i] < 0) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					continue;
				}
				long long hashValue = getHash(needScore, m + 1);
				it = freq.find(hashValue);
				if (it != freq.end()) {
					ansFirstMask = lastMask[hashValue];
					ansSecondMask = mask;
					ans += it->second;
				}
			}
			if (ans != 1) {
				cout << ans << " solutions\n";
			} else {
				vector <int> v;
				v.reserve(m);
				while (ansFirstMask) {
					v.push_back(ansFirstMask & 1);
					ansFirstMask >>= 1;
				}
				while (v.size() < firstHalf) {
					v.push_back(0);
				}
				while (ansSecondMask) {
					v.push_back(ansSecondMask & 1);
					ansSecondMask >>= 1;
				}
				while (v.size() < m) {
					v.push_back(0);
				}
				for (int i = 0; i < m; i++) {
					cout << v[i];
				}
				cout << "\n";
			}
		}
	}
}
