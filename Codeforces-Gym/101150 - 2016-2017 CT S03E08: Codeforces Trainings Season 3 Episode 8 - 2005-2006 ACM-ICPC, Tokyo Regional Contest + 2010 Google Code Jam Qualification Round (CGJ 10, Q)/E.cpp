// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150E

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD EPS = 1e-13;

struct data {
	LD peso, largo, pos;
	data(LD _peso = 0.0, LD _largo = 0.0, LD _pos = 0.0) {
        peso = _peso;
        largo = _largo;
        pos = _pos;
	}
};

inline LD calcPos(LD a, LD b) {
	return b / (a + b);
}

data merge(const data &a, const data &b) {
	data res;
	res.largo = max(max(a.pos + 1.0 + (b.largo - b.pos), b.pos - 1.0 + (a.largo - a.pos)), max(a.largo, b.largo));
	res.peso = a.peso + b.peso;
	res.pos = a.pos + b.peso / (a.peso + b.peso);
	if (b.pos > 1.0 + a.pos) {
        res.pos = b.pos - (1.0 - b.peso / (a.peso + b.peso));
	}
	return res;
}

LD w[10];
vector <data> v[(1 << 8)];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(17);
	//freopen("dat.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
        LD r;
        int s;
        cin >> r >> s;
        //cerr << "room: " << r << "\n";
		for (int i = 0; i < s; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < (1 << s); i++) {
			v[i].clear();
		}
		for (int i = 0; i < s; i++) {
			v[1 << i].push_back(data(w[i], 0.0, 0.0));
		}
		for (int mask = 1; mask < (1 << s); mask++) {
			for (int x = mask; x > 0; x = (x - 1) & mask) {
				int y = mask ^ x;
				if (y == 0) {
                    continue;
				}
				/*if (!( ((x | y) == mask) && ((x & y) == 0) )) {
                    cerr << "ERROR: " << x << " " << y << " " << mask << "\n";
                    cerr << (x | y) << " " << (x & y) << "\n";
                    exit(0);
				}*/
				//assert(((x | y) == mask) && ((x & y) == 0));
				for (int i = 0; i < v[x].size(); i++) {
					for (int j = 0; j < v[y].size(); j++) {
                        /*if (mask == (1 << s) - 1) {
                            //cerr << v[x][i].peso << " " << v[x][i].largo << " " << v[x][i].pos << " + ";
                            //cerr << v[y][j].peso << " " << v[y][i].largo << " " << v[y][j].pos << "\n";
                            data tmp = merge(v[x][i], v[y][j]);
                            cerr << tmp.largo << "\n";
                            //cerr << "merge: " << tmp.peso << " " << tmp.largo << " " << tmp.pos << "\n";
                        }*/

						data tmp = merge(v[x][i], v[y][j]);
						if (tmp.largo <= r - 0.00001) {
							v[mask].push_back(tmp);
						}
					}
				}
			}
		}
		if (!v[(1 << s) - 1].size()) {
			cout << "-1\n";
			continue;
		}
		LD ans = v[(1 << s) - 1][0].largo;
		for (int i = 1; i < v[(1 << s) - 1].size(); i++) {
            //cerr << v[(1 << s) - 1][i].largo << "\n";
			ans = max(ans, v[(1 << s)- 1][i].largo);
		}
		cout << fixed << ans << "\n";
	}
}
