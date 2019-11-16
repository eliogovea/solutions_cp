// 2014 Benelux Algorithm Programming Contest (BAPC 14), 2014-2015 CT S02E08: Codeforces Trainings Season 2 Episode 8
// 100526C

#include <bits/stdc++.h>

using namespace std;

inline int sign(long long x) {
	if (x < 0) {
		return -1;
	}
	if (x > 0) {
		return 1;
	}
	return 0;
}

struct pt {
	int x, y;
	pt() {}
	pt(int _x, int _y) : x(_x), y(_y) {}
};

bool operator < (const pt &a, const pt &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline long long cross(const pt &a, const pt &b) {
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

inline long long norm2(const pt &a) {
	return (long long)a.x * a.x + (long long)a.y * a.y;
}


struct compareByAngle {
	pt O;
	compareByAngle() {
		O = pt(0, 0);
	}
	compareByAngle(pt _O) {
		O = _O;
	}
	bool operator () (const pt &a, const pt &b) {
		int c = sign(cross(a - O, b - O));
		if (c != 0) {
			return (c > 0);
		}
		return norm2(a - O) < norm2(b - O);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <pt> pts(n);
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}
		sort(pts.begin(), pts.end());
		sort(++pts.begin(), pts.end(), compareByAngle(pts[0]));
		vector <pt> ch;
		ch.reserve(2 * n);
		ch.push_back(pts[0]);
		ch.push_back(pts[1]);
		for (int i = 2; i < n; i++) {
			while (true) {
				pt a = ch[ch.size() - 2];
				pt b = ch[ch.size() - 1];
				if (sign(cross(b - a, pts[i] - a)) >= 0) {
					break;
				}
				ch.pop_back();
			}
			ch.push_back(pts[i]);
		}
		long long ans = 0;
		for (int i = 0; i < ch.size(); i++) {
			for (int j = i + 1; j < ch.size(); j++) {
				int pos1 = i;
				{
					int lo = i + 1;
					int hi = j;
					while (lo <= hi) {
						int mid = (lo + hi) >> 1;
						long long area1 = abs(cross(ch[j] - ch[i], ch[mid] - ch[i]));
						long long area2 = abs(cross(ch[j] - ch[i], ch[mid - 1] - ch[i]));
						if (area1 >= area2) {
							pos1 = mid;
							lo = mid + 1;
						} else {
							hi = mid - 1;
						}
					}
				}
				int pos2 = j;
				{
					int lo = j + 1;
					int hi = i + ch.size();
					while (lo <= hi) {
						int mid = (lo + hi) >> 1;
						long long area1 = abs(cross(ch[i] - ch[j], ch[mid % ch.size()] - ch[j]));
						long long area2 = abs(cross(ch[i] - ch[j], ch[(mid - 1 + ch.size()) % ch.size()] - ch[j]));
						if (area1 >= area2) {
							pos2 = mid;
							lo = mid + 1;
						} else {
							hi = mid - 1;
						}
					}
				}
				long long area1 = abs(cross(ch[j] - ch[i], ch[pos1] - ch[i]));
				long long area2 = abs(cross(ch[i] - ch[j], ch[pos2 % ch.size()] - ch[j]));
				ans = max(ans, area1 + area2);
			}
		}
		cout << ans / 2LL;
		if (ans & 1LL) {
			cout << ".5";
		}
		cout << "\n";
	}
}
