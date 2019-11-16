#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int> > teams;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n; i++) {
		scanf("%d%d", &a, &b);
		teams.push_back(make_pair(make_pair(b, n - i), a));
	}
	sort(teams.begin(), teams.end(), greater<pair<pair<int, int>, int > >());
	for (int i = 0; i < n; i++)
		printf("%d %d\n", teams[i].second, teams[i].first.first);
}
