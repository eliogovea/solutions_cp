#include <bits/stdc++.h>

using namespace std;

inline int sign(const long long x) {
    return (x < 0) ? -1 : (x > 0);
}

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) :
        x(_x), y(_y) {}
};

point operator + (const point & P, const point & Q) {
    return point(P.x + Q.x, P.y + Q.y);
}

point operator - (const point & P, const point & Q) {
    return point(P.x - Q.x, P.y - Q.y);
}

long long dot(const point & P, const point & Q) {
    return (long long)P.x * Q.x + (long long)P.y * Q.y;
}

long long cross(const point & P, const point & Q) {
    return (long long)P.x * Q.y - (long long)P.y * Q.x;
}

inline int halfPlane(const point & P) {
	if (sign(P.y) != 0) {
		return sign(P.y);
	}
	return sign(P.x);
}

bool byPolarAngle(const point & P, const point & Q) {
	if (halfPlane(P) != halfPlane(Q)) {
		return halfPlane(P) < halfPlane(Q);
	}
	int s = sign(cross(P, Q));
	if (s != 0) {
		return (s > 0);
	}
	return dot(P, P) < dot(Q, Q);
}

long long dArea(const vector <point> & G) {
    int n = G.size();
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1 == n ? 0 : i + 1;
        result += cross(G[i], G[j]);
    }
    return result;
}

void solve(const vector <point> & G, vector <long long> & x, vector <long long> & y) {
    int n = G.size();
    long long A = dArea(G);
    
    assert(sign(A) > 0);
    
    long long Al = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (true) {
            int nr = r + 1 == n ? 0 : r + 1;
            long long delta =  cross(G[r] - G[l], G[nr] - G[l]);
            
            assert(delta >= 0);
            
            if (2LL * (Al + delta) <= A) {
                Al += delta;
                r = nr;
            } else {
            	break;
            }
        }
        
        assert(2LL * Al <= A);
        
        if (2LL * Al == A) {
            long long vx = G[r].x - G[l].x;
            long long vy = G[r].y - G[l].y;
            long long g = __gcd(abs(vx), abs(vy));
            vx /= g;
            vy /= g;
        	x[l] = G[l].x + vx;
        	y[l] = G[l].y + vy;
        } else {
        	point P = G[l];
        	point Q = G[r];
        	point R = G[r + 1 == n ? 0 : r + 1];
        	
        	// the point is in the segment QR
		      long long At = cross(Q - P, R - P);
		      
		      assert(sign(At) >= 0);
		      
		      assert(2LL * (Al + At) > A);

		      // 2 * (Al / 2 + k * At / 2) = A / 2
		      // Al + k * At = A / 2
		      // k * At = (A - 2 * Al) / 2
		      // k = (A - 2 * Al) / (2 * At)
		      // x = xl + k * dx
		      // x = (x1 * 2 * At + (A - 2 * Al) * (x2 - x1)) / (2 * At)

//		      long double dx = R.x - Q.x;
//		      long double dy = R.y - Q.y;
		      
			
			// v = (Q - P) + k * (R - Q)
		      
		      
			long long nvx = (long long)(Q.x - P.x) * 2LL * At + (A - 2LL * Al) * (long long)(R.x - Q.x);
			long long nvy = (long long)(Q.y - P.y) * 2LL * At + (A - 2LL * Al) * (long long)(R.y - Q.y);

			long long g = __gcd(abs(nvx), abs(nvy));
			nvx /= g;
			nvy /= g;

			x[l] = (long long)P.x + nvx;
			y[l] = (long long)P.y + nvy;
        }

        int nl = l + 1 == n ? 0 : l + 1;
        
        long long delta = cross(G[l] - G[r], G[nl] - G[r]);
        assert(sign(delta) >= 0);
        Al -= delta;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector <point> G(n);
	for (auto & P : G) {
		cin >> P.x >> P.y;
	}
	
	int q;
	cin >> q;
	
	vector <int> Q(q);
	for (auto & x : Q) {
		cin >> x;
	}
	
	vector <long long> x(n), y(n);
	solve(G, x, y);
	
	for (int i = 0; i < q; i++) {
		cout << x[Q[i]] << " " << y[Q[i]] << "\n";
	}
}
