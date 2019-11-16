#include <bits/stdc++.h>
 
using namespace std;
 
typedef complex<double> comp;
 
const double pi = acos(-1.0);
const int MAXN = 605000;
 
int rev[MAXN * 2];
 
void fft(comp p[], int n, bool invert) {
	int dig = 0;
	while ((1 << dig) < n)
		dig++;
 
	for (int i = 0; i < n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (dig - 1));
		if (rev[i] > i)
			swap(p[i], p[rev[i]]);
	}
 
	for (int len = 2; len <= n; len <<= 1) {
		double angle = 2 * pi / len;
		if (invert)
			angle *= -1;
		comp wgo(cos(angle), sin(angle));
		for (int i = 0; i < n; i += len) {
			comp w(1);
			for (int j = 0; j < (len >> 1); j++) {
				comp a = p[i + j], b = w * p[i + j  + (len >> 1)];
				p[i + j] = a + b;
				p[i + j + (len >> 1)] = a - b;
				w *= wgo;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; i++)
			p[i] /= n;
}
 
string s;
 
comp a[MAXN], ra[MAXN];
comp b[MAXN], rb[MAXN];
comp c[MAXN], rc[MAXN];
 
int ans[MAXN];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//freopen("dat.txt", "r", stdin);
	
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			a[i] = 1;
		} else if (s[i] == 'b') {
			b[i] = 1;
		} else {
			c[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		ra[i] = a[n - 1 - i];
		rb[i] = b[n - 1 - i];
		rc[i] = c[n - 1 - i];
	}
	int len = 1;
	while (len < n) {
		len *= 2;
	}
	len *= 2;
	fft(a, len, false);
	fft(b, len, false);
	fft(c, len, false);
	fft(ra, len, false);
	fft(rb, len, false);
	fft(rc, len, false);
	for (int i = 0; i < len; i++) {
		a[i] *= ra[i];
		b[i] *= rb[i];
		c[i] *= rc[i];
	}
	fft(a, len, true);
	fft(b, len, true);
	fft(c, len, true);
	for (int i = 0; i < n; i++) {
		ans[n - 1 - i] = floor(a[i].real() + 0.5) + floor(b[i].real() + 0.5) + floor(c[i].real() + 0.5);
	}
	int x = 1;
	for (int i = 2; i < n; i++) {
		if (ans[i] > ans[x]) {
			x = i;
		}
	}
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == ans[x]) {
			v.push_back(i);
		}
	}
	cout << ans[x] << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i + 1 < v.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}
