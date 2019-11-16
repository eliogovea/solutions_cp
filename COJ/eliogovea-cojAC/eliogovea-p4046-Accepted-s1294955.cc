#include <bits/stdc++.h>

using namespace std;

// base and base_digits must be consistent
constexpr int base = 1000000000;
constexpr int base_digits = 9;

struct bigint {
    // value == 0 is represented by empty z
    vector<int> z; // digits

    // sign == 1 <==> value >= 0
    // sign == -1 <==> value < 0
    int sign;

    bigint() : sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint &operator=(long long v) {
        sign = v < 0 ? -1 : 1;
        v *= sign;
        z.clear();
        for (; v > 0; v = v / base)
            z.push_back((int) (v % base));
        return *this;
    }

    bigint &operator+=(const bigint &other) {
        if (sign == other.sign) {
            for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
                if (i == z.size())
                    z.push_back(0);
                z[i] += carry + (i < other.z.size() ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry)
                    z[i] -= base;
            }
        } else if (other != 0 /* prevent infinite loop */) {
            *this -= -other;
        }
        return *this;
    }

    friend bigint operator+(bigint a, const bigint &b) {
        return a += b;
    }

    bigint &operator-=(const bigint &other) {
        if (sign == other.sign) {
            if (sign == 1 && *this >= other || sign == -1 && *this <= other) {
                for (int i = 0, carry = 0; i < other.z.size() || carry; ++i) {
                    z[i] -= carry + (i < other.z.size() ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry)
                        z[i] += base;
                }
                trim();
            } else {
                *this = other - *this;
                this->sign = -this->sign;
            }
        } else {
            *this += -other;
        }
        return *this;
    }

    friend bigint operator-(bigint a, const bigint &b) {
        return a -= b;
    }

    bigint &operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < z.size() || carry; ++i) {
            if (i == z.size())
                z.push_back(0);
            long long cur = (long long) z[i] * v + carry;
            carry = (int) (cur / base);
            z[i] = (int) (cur % base);
        }
        trim();
        return *this;
    }

    bigint operator*(int v) const {
        return bigint(*this) *= v;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.z.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.z.resize(a.z.size());

        for (int i = (int) a.z.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.z[i];
            int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
            int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
            int d = (int) (((long long) s1 * base + s2) / b.z.back());
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.z[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return {q, r / norm};
    }

    friend bigint sqrt(const bigint &a1) {
        bigint a = a1;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        int n = a.z.size();

        int firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
        firstDigit = (int) ::sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        int q = firstDigit;
        bigint res;

        for (int j = n / 2 - 1; j >= 0; j--) {
            for (;; --q) {
                bigint r1 = (r - (res * 2 * base + q) * q) * base * base +
                            (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0) {
                int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
                int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
                int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
                q = (int) (((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2));
            }
        }

        res.trim();
        return res / norm;
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    bigint &operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = z[i] + rem * (long long) base;
            z[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
        return *this;
    }

    bigint operator/(int v) const {
        return bigint(*this) /= v;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = (int) z.size() - 1; i >= 0; --i)
            m = (int) ((z[i] + m * (long long) base) % v);
        return m * sign;
    }

    bigint &operator*=(const bigint &v) {
        *this = *this * v;
        return *this;
    }

    bigint &operator/=(const bigint &v) {
        *this = *this / v;
        return *this;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (z.size() != v.z.size())
            return z.size() * sign < v.z.size() * v.sign;
        for (int i = (int) z.size() - 1; i >= 0; i--)
            if (z[i] != v.z[i])
                return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }

    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }

    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }

    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }

    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!z.empty() && z.back() == 0)
            z.pop_back();
        if (z.empty())
            sign = 1;
    }

    bool isZero() const {
        return z.empty();
    }

    friend bigint operator-(bigint v) {
        if (!v.z.empty())
            v.sign = -v.sign;
        return v;
    }

    bigint abs() const {
        return sign == 1 ? *this : -*this;
    }

    long long longValue() const {
        long long res = 0;
	if (z.size() == 0) {
		return 0;
	}
        for (int i = (int) z.size() - 1; i >= 0; i--)
            res = res * base + z[i];
        return res * sign;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int v : a) {
            cur += v * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->z, base_digits, 6);
        vector<int> b6 = convert_base(v.z, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < c.size(); i++) {
            long long cur = c[i] + carry;
            res.z.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.z = convert_base(res.z, 6, base_digits);
        res.trim();
        return res;
    }
    
    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    
    friend ostream &operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int) v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }

};

const int N = 200 * 1000 + 10;

int t, n, m;
char op;
int u, v;
int x[3][N];
int y[N];
int z[N];

int len[N];

bool visited[N];

long long egcd(long long a, long long b, long long & x, long long & y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	long long g = egcd(b % a, a, y, x);
	x -= (b / a) * y;

	return g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for (int c = 1; c <= t; c++) {
		cin >> n;

		int half = n >> 1;

		for (int i = 0; i < n; i++) {
			cin >> y[i];
			x[0][i] = i;
		}

		int p = 0;

		cin >> m;
		while (m--) {
			cin >> op;
			if (op == 'R') {
				for (int i = 0; i < n; i++) {
					x[p ^ 1][n - 1 - i] = x[p][i];
				}
				p ^= 1;
			} else if (op == 'I') {
				for (int i = 0; i < half; i++) {
					x[p ^ 1][i << 1] = x[p][half + i];
					x[p ^ 1][(i << 1) | 1] = x[p][i];
				}
				p ^= 1;
			} else if (op == 'S') {
				cin >> u;
				if (u == n) {
					continue;
				}
				int now = n - u;
				for (int i = 0; i < n; i++) {
					x[p ^ 1][i] = x[p][now];
					now++;
					if (now == n) {
						now = 0;
					}
				}
				p ^= 1;
			} else {
				cin >> u >> v;
				swap(x[p][u - 1], x[p][v - 1]);
			}
		}
/*		
		for (int i = 0; i < n; i++) {
			cerr << x[p][i] << " ";
		}
		cerr << "\n";
*/		
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		
		bigint R(0);
		bigint M(1);

		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				continue;
			}

			int now = i;
			int steps = 0;

			while (!visited[now]) {
				visited[now] = true;
				steps++;
				now = x[p][now];
			}

			len[i] = steps;
			
			if (steps == 1) {
				z[i] = y[i];
				continue;
			}

			int g = __gcd(steps, M % steps);

			int rg = R % g;
			int rd = rg;

			int v = -1;
			int s = -1;

			for (int j = 0, k = i; j < steps; j++, k = x[p][k]) {
				if (j % g == rg) {
					if (v < y[k]) {
						v = y[k];
						s = j;
					}
				}
			}

			int d = g;

			// crt
			bigint r1 = R / d; // big int
			bigint m1 = M / d; // big int

			long long r2 = s / d;
			long long m2 = steps / d;

			if (m1 < bigint(1000 * 1000)) {
				long long mm1 = m1.longValue();
				long long rr1 = r1.longValue();
				
				if (mm1 < m2) {
					swap(mm1, m2);
					swap(rr1, r2);
				}


				long long k = (r2 - rr1) % m2;

				if (k < 0) {
					k += m2;
				}

				long long xx, yy;
				egcd(mm1, m2, xx, yy);

				xx %= m2;
				if (xx < 0) {
					xx += m2;
				}

				k = (k * xx) % m2;

				M = bigint(mm1) * m2 * g;
				R = (bigint(k) * mm1 + bigint(rr1)) * d + bigint(rd);
			} else {
				long long k = (r2 - (r1 % m2)) % m2;
				if (k < 0) {
					k += m2;
				}

				// egcd(m2, m1, yy, xx);
				// egcd(m1 % m2, m2, xx, yy)
				// yy -= (m1 / m2) * xx 
				
				long long xx, yy;
				egcd(m1 % m2, m2, xx, yy);

				xx %= m2;
				if (xx < 0) {
					xx += m2;
				}

				k = (k * xx) % m2;

				M = m1 * m2 * g;
				R = (m1 * k + r1) * d + bigint(rd);
			}
				
			now = i;
			for (int j = 0; j < s; j++) {
				now = x[p][now];
			}
			int pos = i;
			for (int j = 0; j < steps; j++) {
				z[pos] = y[now];
				now = x[p][now];
				pos = x[p][pos];
			}
		}

		cout << "Case #" << c << ":";
		for (int i = 0; i < n; i++) {
			cout << " " << z[i];
		}
		cout << "\n";
	}
}
