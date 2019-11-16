#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD EPS = 1e-15;

inline int sign(LD x) {
	if (fabs(x) < EPS) {
		return 0;
	}
	if (x < 0) {
		return -1;
	}
	return 1;
}

struct pt {
	LD x, y;
	pt() {}
	pt(LD _x, LD _y) {
        x = _x;
        y = _y;
	}
};

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline LD cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

struct line {
	LD a, b, c;
	line() {}
	line(LD _a, LD _b, LD _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	line(pt p1, pt p2) {
		LD dx = p2.x - p1.x;
		LD dy = p2.y - p1.y;
		a = -dy;
		b = dx;
		c = -(a * p1.x + b * p1.y);
	}
	int side(pt p) {
		return sign(a * p.x + b * p.y + c);
	}
};

pt inter(line l1, line l2) {
    //cerr << "-->> " << l1.a << " " << l1.b << " " << l1.c << "\n";
    //cerr << "-->> " << l2.a << " " << l2.b << " " << l2.c << "\n\n";
	LD det = l1.a * l2.b - l1.b * l2.a;
	LD x = ((-l1.c) * l2.b - l1.b * (-l2.c)) / det;
	LD y = (l1.a * (-l2.c) - (-l1.c) * l2.a) / det;
	return pt(x, y);
}

const LD INF = 1e15;

bool checkpt(pt p) {
    return -INF <= p.x && p.x <= INF && -INF <= p.y && p.y <= INF;
}

vector <pt> halfPlanesInter(vector <line> all) {
	vector <pt> bbox;
	bbox.push_back(pt(0, 0));
	bbox.push_back(pt(INF, 0));
	bbox.push_back(pt(INF, INF));
	bbox.push_back(pt(0, INF));

	for (int i = 0; i < all.size(); i++) {

        // cerr << "bbox\n";
        // for (int j = 0; j < bbox.size(); j++) {
            // cerr << bbox[j].x << " " << bbox[j].y << "\n";
        // }
        // cerr << "\n";

		vector <pt> nbbox;

		for (int j = 0; j < bbox.size(); j++) {
			if (all[i].side(bbox[j]) >= 0) {
				nbbox.push_back(bbox[j]);
			}
			int nj = (j + 1) % bbox.size();
			if (all[i].side(bbox[j]) * all[i].side(bbox[nj]) == -1) {
                pt p = inter(all[i], line(bbox[j], bbox[nj]));
				nbbox.push_back(p);
			}
		}
		bbox = nbbox;
	}

	// cerr << "bbox\n";
    // for (int j = 0; j < bbox.size(); j++) {
        // cerr << bbox[j].x << " " << bbox[j].y << "\n";
    // }
    // cerr << "\n";
	return bbox;
}

void test() {

    vector <line> hp;
    hp.push_back(line(1, -2, 0));
    vector <pt> hpi = halfPlanesInter(hp);
    cerr << hpi.size() << "\n";
    for (int i = 0; i < hpi.size(); i++) {
        cerr << hpi[i].x << " " << hpi[i].y << "\n";
    }
    cerr << "\n";
}

inline LD area(vector <pt> &p) {
	LD res = 0.0;
	for (int i = 0; i < p.size(); i++) {
		res += cross(p[i], p[(i + 1) % p.size()]);
	}
	return fabs(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cerr.precision(5); cerr << fixed;

	//test(); return 0;

	// freopen("da.txt", "r", stdin);

	int n;
	cin >> n;
	vector <int> u(n), v(n), w(n);
	vector <LD> uu(n), vv(n), ww(n);
	const LD VAL = 1e2;
	for (int i = 0; i < n; i++) {
		cin >> u[i] >> v[i] >> w[i];
		uu[i] = VAL / (LD)u[i];
		vv[i] = VAL / (LD)v[i];
		ww[i] = VAL / (LD)w[i];
	}

	for (int i = 0; i < n; i++) {
		bool alwaysLose = false;
		for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
			if (u[j] >= u[i] && v[j] >= v[i] && w[j] >= w[i]) {
				alwaysLose = true;
				break;
			}
		}
		if (alwaysLose) {
			cout << "No\n";
		} else {
			vector <line> lines;
			for (int j = 0; j < n; j++) {
				if (j == i) {
                    continue;
				}
				if (u[j] < u[i] && v[j] < v[i] && w[j] < w[i]) { // i wins
                    continue;
				}
				// lines.push_back(line( (LD)(u[i] - u[j]) / (LD)(u[i] * u[j]), (LD)(v[i] - v[j]) / (LD)(v[i] * v[j]), (LD)(w[i] - w[j]) / (LD)(w[i] * w[j]) ));
				lines.push_back(line(uu[j] - uu[i], vv[j] - vv[i], ww[j] - ww[i]));
			}

			// cerr << "half planes: " << lines.size() << "\n\n";
			// for (int j = 0; j < lines.size(); j++) {
                // cerr << "line: " << lines[j].a << " " << lines[j].b << " " << lines[j].c << "\n";
			// }

			// if (!lines.size()) {
				// cout << "Yes\n";
			// } else {
				vector <pt> hpi = halfPlanesInter(lines);
				if (hpi.size() <= 2) {
					cout << "No\n";
				} else {
				    cout << "Yes\n";
					LD a = area(hpi);
					// cerr << "area: " << a << "\n";
					// if (sign(a) == 1) {
						// cout << "Yes\n";
					// } else {
						// cout << "No\n";
					// }
				}
			// }
		}
	}
}
