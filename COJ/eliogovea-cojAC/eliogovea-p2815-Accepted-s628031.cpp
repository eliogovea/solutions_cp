#include <bits/stdc++.h>
using namespace std;

string a, b, aux;

bool match() {
	int sa = a.size(), sb = b.size();
	if (sa < sb) return false;
	for (int i = 0; i <= sa - sb; i++) {
		bool m = true;
		for (int j = 0; j < sb; j++)
			if (a[i + j] != b[j]) {
				m = false;
				break;
			}
		if (m) {
			aux = "";
			for (int k = 0; k < sa; k++)
				if (!(k >= i && k < i + sb))
					aux += a[k];
			a = aux;
			return true;
		}
	}
	return false;
}

int tc, sol;

int main() {
    cin >> tc;
	while (tc--) {
        cin >> a >> b;
        sol = 0;
		while (match()) sol++;
		cout << sol << "\n";
	}
}
