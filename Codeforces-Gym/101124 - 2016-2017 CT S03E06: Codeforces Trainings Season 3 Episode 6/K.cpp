// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124K

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	//freopen("dat.txt", "r", stdin);
	string line;
	double lastChange = 0.0;
	double lastSpeed = 0.0;
	double length = 0.0;
	while (getline(cin, line)) {
		double h = (10.0 * (double)(line[0] - '0') + (double)(line[1] - '0'));
		double m = (10.0 * (double)(line[3] - '0') + (double)(line[4] - '0'));
		double s = (10.0 * (double)(line[6] - '0') + (double)(line[7] - '0'));
		double curTime = h + m / 60.0 + s / 3600.0;
		if (line.size() == 8) {
			double ans = length + lastSpeed * (curTime - lastChange);
			cout << line << " " << fixed << ans << " km\n";
		} else {
			length += lastSpeed * (curTime - lastChange);
			lastChange = curTime;
			lastSpeed = 0.0;
			for (int i = 9; i < line.size(); i++) {
				lastSpeed = 10.0 * lastSpeed + (double)(line[i] - '0');
			}
		}
	}
}
