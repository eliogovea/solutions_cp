#include <iostream>
#include <vector>

using namespace std;

struct pt {
	int x, y;
};

struct cir {
	int x, y, r;
	int a, b, c;
};

struct sq {
	int x1, y1, x2, y2;
	int a, b, c;
};

int inside(pt P, cir C) {
	if ((P.x - C.x) * (P.x - C.x) + (P.y - C.y) * (P.y - C.y) > C.r * C.r) return 0;
	if ((P.x - C.x) * (P.x - C.x) + (P.y - C.y) * (P.y - C.y) == C.r * C.r) return 1;
	return 2;
}

int inside(pt P, sq S) {
	if (P.x > S.x2 || P.x < S.x1 || P.y > S.y2 || P.y < S.y1) return 0;
	if (P.x > S.x1 && P.x < S.x2 && P.y < S.y2 && P.y > S.y1) return 2;
	return 1;
}

int tc, n, m;
vector<pt> P;
vector<cir> C;
vector<sq> S;
string str;
int cas;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		P.clear();
		C.clear();
		S.clear();
		for (int i = 0, x, y, z, a, b, c; i < n; i++) {
			cin >> str >> x >> y >> z >> a >> b >> c;
			if (str[0] == 'C') {
				cir cr;
				cr.x = x; cr.y = y; cr.r = z;
				cr.a = a; cr.b = b; cr.c = c;
				C.push_back(cr);
			}
			else {
				sq s;
				s.x1 = x; s.y1 = y; s.x2 = x + z; s.y2 = y + z;
				s.a = a; s.b = b; s.c = c;
				S.push_back(s);
			}
		}

		cout << "Case " << ++cas << ":\n";
		for (int i = 0, x, y; i < m; i++) {
			pt p;
			cin >> x >> y;
			p.x = x; p.y = y;
            double aa, bb, cc;
            aa = bb = cc = 0;
            int cnt = 0;
			for (int j = 0; j < C.size(); j++) {
				if (inside(p, C[j]) == 2) {
				    cnt++;
					aa += (double)C[j].a;
					bb += (double)C[j].b;
					cc += (double)C[j].c;
				}
				if (inside(p, C[j]) == 1)
                    cnt++;
			}
			for (int j = 0; j < S.size(); j++) {
				if (inside(p, S[j]) == 2) {
				    cnt++;
					aa += (double)S[j].a;
					bb += (double)S[j].b;
					cc += (double)S[j].c;
				}
				if (inside(p, S[j]) == 1) cnt++;
			}
            if (cnt) {
                aa /= double(cnt);
                bb /= double(cnt);
                cc /= double(cnt);
            }
            else {
                aa = bb = cc = 255;
            }
            cout.precision(0);
            cout << "(" << fixed << aa << ", ";
            cout << fixed << bb << ", ";
            cout << fixed << cc << ")\n";
		}
		if (tc) cout << "\n";
	}
}
