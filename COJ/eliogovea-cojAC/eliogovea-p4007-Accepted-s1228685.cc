#include <bits/stdc++.h>

using namespace std;

int slow(int n) {
	int answer = 0;
	for (int x = 1; x < n; x++) {
		for (int y = 1; y < n; y++) {
			if (__gcd(x, y) == 1 && __gcd(x, n - y) == 1) {
				answer++;
			}
		}
	}
	return answer;
}

long long fast(int n) {
	if (n == 2) {
		return 1;
	}

	vector <vector <int>> fp(n + 1);
	vector <int> pp(n + 1, 1);
	
	for (int i = 2; i <= n; i++) {
		if (pp[i] == 1) {
			for (int j = i; j <= n; j += i) {
				pp[j] *= i;
				fp[j].push_back(i);
			}
		}
	}
	
	map <long long, long long> cache;
	
	long long answer = 0;
	
	for (int y = 1; y <= n - y; y++) {
	
		long long g = __gcd(pp[y], pp[n - y]);
		long long v = (long long)y * (long long)(n - y) / g;
		if (cache.find(v) != cache.end()) {
			answer += cache[v];
			continue;
		}
		
		vector <int> f;
		
		if (y == 1) {
			f = fp[n - y];
		} else if (n - y == 1) {
			f = fp[y];
		} else {
			int pa = 0;
			int pb = 0;
			while (pa < fp[y].size() && pb < fp[n - y].size()) {
				if (fp[y][pa] < fp[n - y][pb]) {
					if (f.size() == 0 || f.back() != fp[y][pa]) {
						f.push_back(fp[y][pa]);
					}
					pa++;
				} else {
					if (f.size() == 0 || f.back() != fp[n - y][pb]) {
						f.push_back(fp[n - y][pb]);
					}
					pb++;
				}
			}
			while (pa < fp[y].size()) {
				if (f.back() != fp[y][pa]) {
					f.push_back(fp[y][pa]);
				}
				pa++;
			}
			while (pb < fp[n - y].size()) {
				if (f.back() != fp[n - y][pb]) {
					f.push_back(fp[n - y][pb]);
				}
				pb++;
			}
		}
		
		vector <long long> pm(1 << (int)f.size(), 1);
		for (int i = 0; i < f.size(); i++) {
			pm[1 << i] = f[i];
		}
		
		long long t = 0;
		for (int m = 0; m < (1 << f.size()); m++) {
			pm[m] = pm[m ^ (m & -m)] * pm[m & -m];
			if (__builtin_popcount(m) & 1) {
				t -= (n - 1) / pm[m];
			} else {
				t += (n - 1) / pm[m];
			}
		}
		
		cache[v] = t;
		
		if (y != n - y) {
			answer += 2LL * t;
		} else {
			answer += t;
		}
	}
	
	return answer;
}

int main() {
	// time_t start = clock();
    int n;
    cin >> n;
    
    long long f = fast(n);
    
    if (n <= 1000) {
    	int s = slow(n);
    	assert(s == f);
    }
    
    cout << f << "\n";
    // cerr << "time: " << (double)(clock() - start) /  CLOCKS_PER_SEC << "\n";
}
