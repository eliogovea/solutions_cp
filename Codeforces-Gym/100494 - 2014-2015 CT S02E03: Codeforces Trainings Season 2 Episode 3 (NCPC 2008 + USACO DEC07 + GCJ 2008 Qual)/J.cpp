// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494J

#include <bits/stdc++.h>

using namespace std;

typedef complex<double> comp;

const double pi = acos(-1.0);
const int MAXN = 605000;

int rev[MAXN * 2];

void fft( comp p[], int n, bool invert) {
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

int n;
int cnt[2 * MAXN];

comp poly[2 * MAXN];

int mult[2 * MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int x = (long long)i * i % n;
		cnt[x]++;
	}

	for (int i = 0; i < n; i++) {
		poly[i] = cnt[i];
	}

	int len = 1;
	while (len <= n) {
		len *= 2;
	}
	len *= 2;
	fft(poly, len, false);
	for (int i = 0; i < len; i++) {
		poly[i] *= poly[i];
	}
	fft(poly,len, true);

	for (int i = 0; i < len; i++) {
		mult[i] = floor(poly[i].real() + 0.5);
	}

	long long total = 0;
	for (int i = 0; i < len; i++) {
		total += (long long)cnt[i % n] * mult[i];
	}

	long long val = 0;
	for (int i = 1; i < n; i++) {
		int x = (long long)i * i % n;
		int y = (x + x) % n;
		if (cnt[y] > 0) {
			val += (long long)cnt[y];
		}
	}
	cout << val + (total - val) / 2LL << "\n";
}
