#include <iostream>

using namespace std;

long long x[2][205], a[2][2], b[2][2], p[2];

int main() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cin >> a[i][j] >> b[i][j];
		for (int j = a[i][0]; j <= b[i][0]; j++)
			for (int k = a[i][1]; k <= b[i][1]; k++)
				x[i][j + k]++;
		for (int j = 1; j <= 200; j++)
			x[i][j] += x[i][j - 1];
	}
	for (int i = 1; i <= 200; i++) {
		p[0] += (x[0][200] - x[0][i - 1]) * (x[1][i - 1]);
		p[1] += (x[1][200] - x[1][i - 1]) * (x[0][i - 1]);
	}
	if (p[0] == p[1]) cout << "Tie\n";
	else if (p[0] < p[1]) cout << "Emma\n";
	else cout << "Gunnar\n";
}
