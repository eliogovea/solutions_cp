#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())

typedef long double ld;

#define EPS 2e-8
int sgn(ld x) { return x < -EPS ? -1 : x > EPS; }

struct pt {
  ld x, y;
  pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
  bool operator<(const pt &p2) const {
    if (fabs(x - p2.x) > EPS) return x < p2.x;
    return y < p2.y - EPS;
  }
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  int operator*(const pt &p2) const { return sgn(x * p2.y - y * p2.x); }
  ld dist2() const { return x * x + y * y; }
};

double cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

struct line {
  ld a, b, c;
  ld cang;

  line() {}
  line(const pt &p1, const pt &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -a * p1.x - b * p1.y;

    ld d = sqrt(a * a + b * b);
    a /= d;
    b /= d;
    c /= d;
    cang = atan2(b, a);
  }
  int side(const pt &p) const {
    return sgn(a * p.x + b * p.y + c);
  }

  bool operator||(const line &l2) const { return sgn(a * l2.b - b * l2.a) == 0; }

  pt operator&(const line &l2) const {
    ld d = a * l2.b - b * l2.a;
    assert(fabs(d) > EPS);
    pt res(
      (b * l2.c - c * l2.b) / d,
      (a * l2.c - c * l2.a) / -d
    );
    return res;
  }
  bool angEq(const line &l2) const {
    ld d = fabs(cang - l2.cang);
    if (2 * M_PI - d < d) d = 2 * M_PI - d;
    return d < EPS;
  }
  bool operator<(const line &l2) const {
    ld d = fabs(cang - l2.cang);
    if (d < EPS) return c < l2.c - EPS;
    return cang < l2.cang;
  }
};

// BEGIN ALGO
vector<pt> cross(vector<line> all) {
  { // \emph{PANIC. Better to rewrite!!!}
    const ld BBOXC = 5.5e10;
    vector<pt> bbox;
    bbox.pb(pt( BBOXC, -BBOXC));
    bbox.pb(pt( BBOXC,  BBOXC));
    bbox.pb(pt(-BBOXC,  BBOXC));
    bbox.pb(pt(-BBOXC, -BBOXC));
    bbox.pb(bbox[0]);
    for (int i = 0; i < 4; i++)
      all.pb(line(bbox[i], bbox[i + 1]));
  }

  sort(all.begin(), all.end());
  int off = 0;
  for (int i = 1; i < sz(all); i++)
    if (all[i - 1].angEq(all[i])) {
      off++;
    } else
      all[i - off] = all[i];
  all.resize(sz(all) - off);

  vector<pt> pts;
  vector<line> ss;
  ss.pb(all[0]);
  int deleted = 0;

  for (int i = 1; i < sz(all); i++) {
    int pcnt = sz(pts);
    while (sz(pts) > deleted && /*BOXNEXT*/
           all[i].side(pts[sz(pts) - 1]) <= 0) {
      pts.erase(pts.end() - 1);
      ss.erase(ss.end() - 1);
    }
    if (sz(pts) == deleted && pcnt) {  /*BOXNEXT*/
      if (pt(ss[sz(ss) - 1].a, ss[sz(ss) - 1].b) *
          pt(all[i].a, all[i].b) <= 0)
        return vector<pt>();
    } else {
      while (sz(pts) > deleted &&
             all[i].side(pts[deleted]) <= 0)
      	  ++deleted;
    } /*BOXNEXT*/
    if (ss[sz(ss) - 1] || all[i]) // parallel !!!
      return vector<pt>();  /*BOXNEXT*/
    pt cpt = ss[sz(ss) - 1] & all[i]; // intersect
    if (ss[deleted].side(cpt) >= 0) {
      pts.pb(cpt);
      ss.pb(all[i]);
    }
  }
  ss.erase(ss.begin(),ss.begin()+deleted);
  pts.erase(pts.begin(),pts.begin()+deleted);
  if (sz(ss) == 1) return pts;
  pts.pb(ss[0] & ss[sz(ss) - 1]);
  return pts;
}

double area(vector <pt> pts) {
	double res = 0.0;
	for (int i = 0; i < pts.size(); i++) {
		res += cross(pts[i], pts[i + 1 == pts.size() ? 0 : i + 1]);
	}
	return 0.5 * fabs(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("dat.txt", "r", stdin);

	int n;
	cin >> n;
	vector <pt> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}

	if (n <= 4) {
		cout << "1\n";
		return 0;
	}

	reverse(p.begin(), p.end());
/*
	for (int i = 1; i < n; i++) {
        vector <line> hp;
        for (int j = 0; j < n; j++) {
            hp.push_back(line(p[j], p[(j + i + 1) % n]));
        }
        vector <pt> pts = cross(hp);
        cerr << "-->> " << i << "\n";
        for (int j = 0; j < pts.size(); j++) {
            cerr << "(" << pts[j].x << ", " << pts[j].y << ")\n";
        }
        cerr << "area: " << area(pts) << "\n";
        cerr << "---------------------\n";
	}
*/
	int lo = 1;
	int hi = n - 2;
	int ans = hi;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		vector <line> hps;
		for (int i = 0; i < n; i++) {
			hps.push_back(line(p[i], p[(i + mid + 1) % n]));
		}
		if (sgn(area(cross(hps))) == 0) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
}
