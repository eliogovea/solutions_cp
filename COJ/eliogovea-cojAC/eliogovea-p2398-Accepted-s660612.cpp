#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n, c;
char L[16], aux[2];
vector<string> sol;
string s;

inline int vocal(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}


int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &c);
		for (int i = 0; i < c; i++) {
			scanf("%s", aux);
			L[i] = aux[0];
		}
		sort(L, L + c);
		sol.clear();
		for (int i = 1; i < (1 << c); i++) {
      s.clear();
			int voc = 0, let = 0;
			for (int j = 0; j < c; j++)
				if (i & (1 << j)) {
					let++;
					voc += vocal(L[j]);
          s += L[j];
				}
			if (let == n && voc >= 1 && n - voc >= 2)
        sol.push_back(s);
		}
		sort(sol.begin(), sol.end());
		sol.erase(unique(sol.begin(), sol.end()), sol.end());
		for (int i = 0; i < (int)sol.size(); i++)
      printf("%s\n", sol[i].c_str());
    if (tc) printf("\n");
	}
}
