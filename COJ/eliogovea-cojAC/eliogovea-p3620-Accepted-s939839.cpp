#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(5);
	int cards, boxes;
	cin >> boxes >> cards;
	vector <int> values(cards);
	for (int i = 0; i < cards; i++) {
		cin >> values[i];
	}
	sort(values.begin(), values.end(), greater <int>());
	vector <int> box_sum(boxes, 0);
	for (int i = 0; i < cards; i++) {
		if (i < boxes) {
			box_sum[i] += values[i];
		} else {
			box_sum[boxes - 1 - (i - boxes)] += values[i];
		}
	}
	double AM = 0.0;
	for (int i = 0; i < cards; i++) {
		AM += (double)values[i];
	}
	AM /= (double)boxes;
	double ans = 0.0;
	for (int i = 0; i < boxes; i++) {
		ans += abs((double)box_sum[i] - AM);
	}
	cout << fixed << ans << "\n";
}
