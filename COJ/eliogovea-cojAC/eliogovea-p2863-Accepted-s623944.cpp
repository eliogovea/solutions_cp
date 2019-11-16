#include <bits/stdc++.h>
using namespace std;

string a, b;
char op;
int sa, sb;

int main() {
	cin >> a >> op >> b;
	sa = a.size();
	sb = b.size();
	if (op == '+') {
		if (sa == sb) {a[0] = '2'; cout << a;}
		else {
			if (sa > sb) {a[sa - sb] = '1'; cout << a;}
			else {b[sb - sa] = '1'; cout << b;}
		}
	}
	if (op == '-') {
        if (sa == sb) cout << '0';
        else if (sa > sb) {
            for (int i = 0; i < sa - sb; i++) cout << '9';
            for (int i = 1; i < sb; i++) cout << '0';
        }
        else {
            cout << '-';
            for (int i = 0; i < sb - sa; i++) cout << '9';
            for (int i = 1; i < sa; i++) cout << '0';
        }
	}
	if (op == '*') {
		cout << '1';
		sa += sb - 2;
		for (int i = 0; i < sa; i++) cout << '0';
	}
	if (op == '/') {
		sa -= sb;
		if (sa >= 0) {
			cout << '1';
			for (int i = 0; i < sa; i++) cout << '0';
		}
		else {
			cout << "0.";
			for (int i = -1; i > sa; i--) cout << '0';
			cout << '1';
		}
	}
	if (op == '%') {
		if (sa >= sb) cout << '0';
		else cout << a;
	}
	cout << endl;
}
