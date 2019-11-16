// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507D

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);

	int m, a1, a2;
	cin >> m >> a1 >> a2;
	int n;
	cin >> n;
	vector <int> mf(n), af(n);
	for (int i = 0; i < n; i++) {
		cin >> mf[i] >> af[i];
	}
	int r;
	cin >> r;
	vector <int> rooms(r), mr(r), ar(r);
	for (int i = 0; i < r; i++) {
		cin >> rooms[i] >> mr[i] >> ar[i];
	}
	int ansA = -1;
	int idF;
	int idR;
	for (int rr = 0; rr < r; rr++) {
        int a = a1;
        if (rooms[rr] == 2) {
            a = a2;
        }
        if (m >= mr[rr]) {
            if (ansA == -1 || ansA < ar[rr] + a) {
                ansA = ar[rr] + a;
                idR = rr;
                idF = -1;
            }
        }
		if (rooms[rr] == 2) {
			for (int ff = 0; ff < n; ff++) {
				if (2 * m >= mr[rr] && 2 * mf[ff] >= mr[rr]) {
					if (ansA == -1 || ansA < ar[rr] + af[ff]) {
						ansA = ar[rr] + af[ff];
						idR = rr;
						idF = ff;
					}
				}
			}
		}
	}
	if (ansA == -1) {
		cout << "Forget about apartments. Live in the dormitory.\n";
	} else {
		if (idF == -1) {
			cout << "You should rent the apartment #" << idR + 1 << " alone.\n";
		} else {
			cout << "You should rent the apartment #" << idR + 1 << " with the friend #" << idF + 1 << ".\n";
		}
	}
}
